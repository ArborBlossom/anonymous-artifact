import os
import json
import torch
import random
import numpy as np
from tqdm import tqdm
import transformers
from datasets import load_dataset
import copy

IGNORE_INDEX = -100
EOT_TOKEN = "<|EOT|>"


def set_deterministic_seed(seed=42):
    random.seed(seed)
    np.random.seed(seed)
    
    torch.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)
    
    os.environ["PYTHONHASHSEED"] = str(seed)
    os.environ["CUBLAS_WORKSPACE_CONFIG"] = ":4096:8"
    
    torch.backends.cudnn.deterministic = True  
    torch.backends.cudnn.benchmark = False
    
    try:
        torch.use_deterministic_algorithms(True, warn_only=True)
    except AttributeError:
        pass 

    print(f"🔒 [System] 已开启严格确定性模式，当前 Seed: {seed}")

def build_instruction_prompt(instruction: str):
    return '''
You are an AI programming assistant, utilizing the DeepSeek Coder model, developed by DeepSeek Company, and you only answer questions related to computer science. For politically sensitive questions, security and privacy issues, and other non-computer science questions, you will refuse to answer.
### Instruction:
{}
### Response:
'''.format(instruction.strip()).lstrip()

def _tokenize_fn(strings, tokenizer):
    tokenized_list = [
        tokenizer(
            text, return_tensors="pt", padding="longest",
            max_length=tokenizer.model_max_length, truncation=True,
        ) for text in strings
    ]
    input_ids = labels = [tokenized.input_ids[0] for tokenized in tokenized_list]
    input_ids_lens = labels_lens = [
        tokenized.input_ids.ne(tokenizer.pad_token_id).sum().item() for tokenized in tokenized_list
    ]
    return dict(input_ids=input_ids, labels=labels, input_ids_lens=input_ids_lens, labels_lens=labels_lens)

def preprocess(sources, targets, tokenizer):
    examples = [s + t for s, t in zip(sources, targets)]
    examples_tokenized, sources_tokenized = [_tokenize_fn(strings, tokenizer) for strings in (examples, sources)]
    input_ids = examples_tokenized["input_ids"]
    labels = copy.deepcopy(input_ids)
    for label, source_len in zip(labels, sources_tokenized["input_ids_lens"]):
        label[:source_len] = IGNORE_INDEX
    return dict(input_ids=input_ids, labels=labels)

def train_tokenize_function(examples, tokenizer):
    sources = [build_instruction_prompt(instruction) for instruction in examples['instruction']]
    targets = [f"{output}\n{EOT_TOKEN}" for output in examples['output']]
    return preprocess(sources, targets, tokenizer)

def run_independent_k_evaluations(
    model_path, data_path, output_dir, 
    k, temperature, top_p, base_seed, 
    filename_template, max_length=1536
):
    os.makedirs(output_dir, exist_ok=True)
    
    print(f"加载 Tokenizer 和 模型: {model_path} ...")
    tokenizer = transformers.AutoTokenizer.from_pretrained(
        model_path, model_max_length=max_length, padding_side="right", use_fast=True, trust_remote_code=True
    )
    model = transformers.AutoModelForCausalLM.from_pretrained(model_path, torch_dtype=torch.bfloat16).cuda()
    model.eval()

    print("加载并处理评估数据集...")
    raw_eval_datasets = load_dataset('json', data_files=data_path, split="train")
    eval_dataset = raw_eval_datasets.map(
        train_tokenize_function, batched=True, batch_size=3000, num_proc=16,
        remove_columns=raw_eval_datasets.column_names, desc="Running Eval Encoding",
        fn_kwargs={"tokenizer": tokenizer}
    )

    for k_idx in range(1, k + 1):
        print(f"\n🚀 开始第 {k_idx}/{k} 次独立生成 (T={temperature}, Top-p={top_p})...")
        
        current_seed = base_seed + k_idx
        set_deterministic_seed(current_seed)
        
        torch.cuda.empty_cache()

        results = []
        
        for i, example in enumerate(tqdm(eval_dataset, desc=f"Eval k={k_idx}")):
            try:
                input_ids = torch.tensor(example['input_ids']).unsqueeze(0).to(model.device)
                labels = torch.tensor(example['labels'])
                response_start_indices = (labels != IGNORE_INDEX).nonzero(as_tuple=True)[0]

                if len(response_start_indices) > 0:
                    response_start_pos = response_start_indices[0].item()
                    input_ids_for_gen = input_ids[:, :response_start_pos]

                    with torch.no_grad():
                        generated_ids = model.generate(
                            input_ids=input_ids_for_gen,
                            max_length=min(max_length, input_ids_for_gen.shape[1] + 256),
                            do_sample=True,          
                            temperature=temperature, 
                            top_p=top_p,             
                            pad_token_id=tokenizer.pad_token_id,
                            eos_token_id=tokenizer.eos_token_id,
                            repetition_penalty=1.1,
                            use_cache=True
                        )

                    generated_tokens = generated_ids[0][input_ids_for_gen.shape[1]:]
                    generated_text = tokenizer.decode(generated_tokens, skip_special_tokens=True)
                    target_text = tokenizer.decode(torch.tensor(example['input_ids'])[response_start_pos:], skip_special_tokens=True)

                    generated_tokens_list = [tokenizer.decode(t, skip_special_tokens=False) for t in generated_tokens]
                    target_tokens_list = [tokenizer.decode(t, skip_special_tokens=False) for t in torch.tensor(example['input_ids'])[response_start_pos:]]
                    generated_tokens_clean = [t.replace(' ', '').replace('\n', '\\n').replace('\t', '\\t') for t in generated_tokens_list]
                    target_tokens_clean = [t.replace(' ', '').replace('\n', '\\n').replace('\t', '\\t') for t in target_tokens_list]

                    results.append({
                        "step": f"k_eval_{k_idx}",
                        "sample_index": i,
                        "input_length": input_ids_for_gen.shape[1],
                        "generated_length": len(generated_tokens),
                        "target_length": len(torch.tensor(example['input_ids'])[response_start_pos:]),
                        "generated_text": generated_text,
                        "target_text": target_text,
                        "target_tokens": target_tokens_clean,
                        "generated_tokens": generated_tokens_clean
                    })
                else:
                    results.append({"step": f"k_eval_{k_idx}", "sample_index": i, "error": "No response start found"})

            except Exception as e:
                results.append({"step": f"k_eval_{k_idx}", "sample_index": i, "error": str(e)})

        out_file_name = filename_template.format(k_idx=k_idx)
        eval_file = os.path.join(output_dir, out_file_name)
        
        with open(eval_file, 'w', encoding='utf-8') as f:
            json.dump({
                "global_step": f"k_eval_{k_idx}",
                "total_samples": len(results),
                "successful_generations": len([r for r in results if "error" not in r]),
                "results": results
            }, f, ensure_ascii=False, indent=2)

        print(f"✅ 第 {k_idx} 次生成完成！文件已保存至: {eval_file}")


if __name__ == "__main__":
    os.environ["CUBLAS_WORKSPACE_CONFIG"] = ":4096:8"
    os.environ["PYTHONHASHSEED"] = "42"

    MODEL_DIR = "Model_path"
    EVAL_DATA_PATH = "data.jsonl"
    OUTPUT_DIRECTORY = "./Pass@k_eval_results"
    
    K_SAMPLES = 15       
    TEMPERATURE = 1.0      
    TOP_P = 0.95              
    BASE_SEED = 42            
    MAX_LENGTH = 1536        
    
    FILENAME_TEMPLATE = f"GenMPO_T{TEMPERATURE}_topp{TOP_P}_k{{k_idx}}.json"
    
    # ======================================================================

    print("-" * 60)
    print(f"准备执行独立评估任务...")
    print(f"计划生成次数 (k): {K_SAMPLES}")
    print(f"预期文件命名: {FILENAME_TEMPLATE.format(k_idx='X')}")
    print("-" * 60)

    run_independent_k_evaluations(
        model_path=MODEL_DIR,
        data_path=EVAL_DATA_PATH,
        output_dir=OUTPUT_DIRECTORY,
        k=K_SAMPLES,
        temperature=TEMPERATURE,
        top_p=TOP_P,
        base_seed=BASE_SEED,
        filename_template=FILENAME_TEMPLATE,
        max_length=MAX_LENGTH
    )
