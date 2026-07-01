import copy
import random
import numpy as np
import os
import json
from dataclasses import dataclass, field
from typing import Optional, Dict, Sequence

import torch
import torch.distributed
import transformers
from transformers import Trainer, TrainerCallback
from tqdm import tqdm
from datasets import load_dataset

IGNORE_INDEX = -100
EOT_TOKEN = "<|EOT|>"


def set_deterministic_seed(seed=42):
    random.seed(seed)
    np.random.seed(seed)
    torch.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)
    
 
    torch.backends.cudnn.deterministic = True  
    torch.backends.cudnn.benchmark = False
    

    os.environ["CUBLAS_WORKSPACE_CONFIG"] = ":4096:8"
    os.environ["PYTHONHASHSEED"] = str(seed)
    

    try:
        torch.use_deterministic_algorithms(True, warn_only=True)
    except AttributeError:
        pass 

    print(f"🔒 [System] 已开启严格确定性模式，Seed: {seed}")
    print(f"   随机数校验: Python={random.random():.6f}, Numpy={np.random.rand():.6f}")


def build_instruction_prompt(instruction: str):
    return '''
You are an AI programming assistant, utilizing the DeepSeek Coder model, developed by DeepSeek Company, and you only answer questions related to computer science. For politically sensitive questions, security and privacy issues, and other non-computer science questions, you will refuse to answer.
### Instruction:
{}
### Response:
'''.format(instruction.strip()).lstrip()


@dataclass
class ModelArguments:
    model_name_or_path: Optional[str] = field(
        default="Model_Path")

@dataclass
class DataArguments:
    data_path: str = field(default="Path_train.jsonl",    
                           metadata={"help": "Path to the training data."})
    eval_data_path: Optional[str] = field(default="Path_eval.jsonl",
                                          metadata={"help": "Path to the evaluation data."})


@dataclass
class TrainingArguments(transformers.TrainingArguments):
    cache_dir: Optional[str] = field(default=None)
    optim: str = field(default="adamw_torch")
    model_max_length: int = field(
        default=1536,
        metadata={"help": "Maximum sequence length. Sequences will be right padded (and possibly truncated)."},
    )
    num_train_epochs: float = field(
        default=8.0,
        metadata={"help": "Total number of training epochs to perform."}
    )
    lr_scheduler_type: str = field(
        default="cosine", 
        metadata={"help": "The scheduler type to use. options: linear, cosine, constant, etc."}
    )
    learning_rate: float = field(default=3e-5, metadata={"help": "The initial learning rate for AdamW."})
    warmup_steps: int = field(default=500, metadata={"help": "Number of warmup steps for learning rate scheduler."})
    weight_decay: float = field(default=0.01, metadata={"help": "Weight decay for AdamW if we apply some."})


def safe_save_model_for_hf_trainer(trainer: transformers.Trainer, output_dir: str):
    """Collects the state dict and dump to disk."""
    state_dict = trainer.model.state_dict()
    if trainer.args.should_save:
        cpu_state_dict = {key: value.cpu() for key, value in state_dict.items()}
        del state_dict
        trainer._save(output_dir, state_dict=cpu_state_dict)  # noqa


def _tokenize_fn(strings: Sequence[str], tokenizer: transformers.PreTrainedTokenizer) -> Dict:
    """Tokenize a list of strings."""
    tokenized_list = [
        tokenizer(
            text,
            return_tensors="pt",
            padding="longest",
            max_length=tokenizer.model_max_length,
            truncation=True,
        )
        for text in strings
    ]

    input_ids = labels = [tokenized.input_ids[0] for tokenized in tokenized_list]
    input_ids_lens = labels_lens = [
        tokenized.input_ids.ne(tokenizer.pad_token_id).sum().item() for tokenized in tokenized_list
    ]

    return dict(
        input_ids=input_ids,
        labels=labels,
        input_ids_lens=input_ids_lens,
        labels_lens=labels_lens,
    )


def preprocess(
        sources: Sequence[str],
        targets: Sequence[str],
        tokenizer: transformers.PreTrainedTokenizer,
) -> Dict:
    """Preprocess the data by tokenizing."""
    examples = [s + t for s, t in zip(sources, targets)]
    examples_tokenized, sources_tokenized = [_tokenize_fn(strings, tokenizer) for strings in (examples, sources)]
    input_ids = examples_tokenized["input_ids"]

    labels = copy.deepcopy(input_ids)
    for label, source_len in zip(labels, sources_tokenized["input_ids_lens"]):
        label[:source_len] = IGNORE_INDEX
    return dict(input_ids=input_ids, labels=labels)


@dataclass
class DataCollatorForSupervisedDataset(object):
    """Collate examples for supervised fine-tuning."""
    tokenizer: transformers.PreTrainedTokenizer

    def __call__(self, instances: Sequence[Dict]) -> Dict[str, torch.Tensor]:
        input_ids, labels = tuple([instance[key] for instance in instances] for key in ("input_ids", "labels"))
        input_ids = [torch.tensor(x) for x in input_ids]
        input_ids = torch.nn.utils.rnn.pad_sequence(
            input_ids, batch_first=True, padding_value=self.tokenizer.pad_token_id
        )
        labels = [torch.tensor(x) for x in labels]
        labels = torch.nn.utils.rnn.pad_sequence(labels, batch_first=True, padding_value=IGNORE_INDEX)

        return dict(
            input_ids=input_ids,
            labels=labels,
            attention_mask=input_ids.ne(self.tokenizer.pad_token_id),
        )


class ForwardSaveTrainer(Trainer):

    def __init__(self, *args, ** kwargs):
        super().__init__(*args, ** kwargs)
        self.debug_tokenizer = kwargs.get('tokenizer', None)
        self.forward_output_dir = os.path.join(kwargs.get('args').output_dir, "forward_outputs")
        os.makedirs(self.forward_output_dir, exist_ok=True)
    

    def get_train_dataloader(self):
        train_dataloader = super().get_train_dataloader()
        if train_dataloader is not None:
            train_dataloader.generator = torch.Generator().manual_seed(42)

        return train_dataloader

    def get_eval_dataloader(self, eval_dataset=None):
        eval_dataloader = super().get_eval_dataloader(eval_dataset)
        if eval_dataloader is not None:
            eval_dataloader.generator = torch.Generator().manual_seed(42)
        return eval_dataloader

    def compute_loss(self, model, inputs, return_outputs=False, ** kwargs):
        outputs = model(**inputs)
        loss = outputs.get("loss")

        if self.args.local_rank in [-1, 0] and self.state.global_step % 100 == 0:
            try:
                logits = outputs.get("logits")
                labels = inputs.get("labels")

                if logits is not None and labels is not None and self.debug_tokenizer is not None:
                    shift_logits = logits[..., :-1, :].contiguous()
                    shift_labels = labels[..., 1:].contiguous()
                    batch_size = shift_logits.size(0)
                    if batch_size > 0:
                        pred_ids = torch.argmax(shift_logits[0], dim=-1)
                        label_ids = shift_labels[0]
                        valid_mask = label_ids != IGNORE_INDEX
                        valid_preds = pred_ids[valid_mask]
                        valid_labels = label_ids[valid_mask]

                        if len(valid_preds) > 0 and len(valid_labels) > 0:
                            pred_str = self.debug_tokenizer.decode(valid_preds, skip_special_tokens=True)
                            label_str = self.debug_tokenizer.decode(valid_labels, skip_special_tokens=True)
                            pred_tokens = [self.debug_tokenizer.decode(token_id, skip_special_tokens=False) for token_id in valid_preds]
                            label_tokens = [self.debug_tokenizer.decode(token_id, skip_special_tokens=False) for token_id in valid_labels]
                            pred_tokens_clean = [token.replace(' ', '').replace('\n', '\\n').replace('\t', '\\t') for token in pred_tokens]
                            label_tokens_clean = [token.replace(' ', '').replace('\n', '\\n').replace('\t', '\\t') for token in label_tokens]
                            match_count = sum(1 for p, l in zip(valid_preds, valid_labels) if p == l)
                            accuracy = match_count / len(valid_preds) if len(valid_preds) > 0 else 0

                            forward_data = {
                                "step": self.state.global_step,
                                "loss": loss.item(),
                                "accuracy": accuracy,
                                "predicted_text": pred_str,
                                "target_text": label_str,
                                "predicted_tokens": pred_tokens_clean,
                                "target_tokens": label_tokens_clean,
                                "match_count": match_count,
                                "total_tokens": len(valid_preds)
                            }

                            output_file = os.path.join(self.forward_output_dir, f"forward_step_{self.state.global_step}.json")
                            with open(output_file, 'w', encoding='utf-8') as f:
                                json.dump(forward_data, f, ensure_ascii=False, indent=2)

            except Exception as e:
                error_file = os.path.join(self.forward_output_dir, f"forward_step_{self.state.global_step}_error.json")
                with open(error_file, 'w', encoding='utf-8') as f:
                    json.dump({"step": self.state.global_step, "error": str(e)}, f, ensure_ascii=False, indent=2)

        return (loss, outputs) if return_outputs else loss


class GenerationEvalCallback(TrainerCallback):
    def __init__(self, tokenizer, eval_dataset, output_dir="./eval_results", eval_steps=500):
        self.tokenizer = tokenizer
        self.eval_dataset = eval_dataset
        self.output_dir = output_dir
        self.eval_steps = eval_steps
        self.last_eval_step = -1
        os.makedirs(output_dir, exist_ok=True)

    def on_step_end(self, args, state, control, **kwargs):
        if args.local_rank not in [-1, 0]:
            return
        if (state.global_step > 0 and 
            state.global_step % self.eval_steps == 0 and 
            state.global_step != self.last_eval_step):
            
            self.last_eval_step = state.global_step
            print(f"步骤 {state.global_step}: 开始生成式评估...")
            self.run_generation_eval(args, state, kwargs.get('model'))

    def on_evaluate(self, args, state, control, **kwargs):
        if args.local_rank in [-1, 0]:
            print(f"步骤 {state.global_step}: 执行官方评估的生成式评估...")
            self.run_generation_eval(args, state, kwargs.get('model'))

    def run_generation_eval(self, args, state, model):
        if model is None:
            print("错误: 模型为None，无法进行评估")
            return

        try:
            model.eval()
            results = []
            eval_subset = self.eval_dataset
            print(f"评估数据集大小: {len(eval_subset)}")

            for i, example in enumerate(tqdm(eval_subset, desc="生成评估")):
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
                                max_length=min(args.model_max_length, input_ids_for_gen.shape[1] + 256),
                                do_sample=False, 
                                temperature=1.0, 
                                pad_token_id=self.tokenizer.pad_token_id,
                                eos_token_id=self.tokenizer.eos_token_id,
                                repetition_penalty=1.1,
                                use_cache=True
                            )

                        generated_tokens = generated_ids[0][input_ids_for_gen.shape[1]:]
                        generated_text = self.tokenizer.decode(generated_tokens, skip_special_tokens=True)
                        target_text = self.tokenizer.decode(
                            torch.tensor(example['input_ids'])[response_start_pos:], 
                            skip_special_tokens=True
                        )

                        generated_tokens_list = [self.tokenizer.decode(token_id, skip_special_tokens=False) for token_id in generated_tokens]
                        target_tokens_list = [self.tokenizer.decode(token_id, skip_special_tokens=False) for token_id in torch.tensor(example['input_ids'])[response_start_pos:]]
                        generated_tokens_clean = [token.replace(' ', '').replace('\n', '\\n').replace('\t', '\\t') for token in generated_tokens_list]
                        target_tokens_clean = [token.replace(' ', '').replace('\n', '\\n').replace('\t', '\\t') for token in target_tokens_list]

                        results.append({
                            "step": state.global_step,
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
                        results.append({"step": state.global_step, "sample_index": i, "error": "No response start found"})

                except Exception as e:
                    results.append({"step": state.global_step, "sample_index": i, "error": str(e)})

            eval_file = os.path.join(self.output_dir, f"eval_step_{state.global_step}.json")
            with open(eval_file, 'w', encoding='utf-8') as f:
                json.dump({
                    "global_step": state.global_step,
                    "total_samples": len(results),
                    "successful_generations": len([r for r in results if "error" not in r]),
                    "results": results
                }, f, ensure_ascii=False, indent=2)

            print(f"✅ 评估结果已保存到: {eval_file}")

        except Exception as e:
            print(f"❌ 评估过程中发生错误: {str(e)}")
            error_file = os.path.join(self.output_dir, f"eval_step_{state.global_step}_error.json")
            with open(error_file, 'w', encoding='utf-8') as f:
                json.dump({"step": state.global_step, "error": str(e)}, f, ensure_ascii=False, indent=2)
        finally:
            model.train()


def train_tokenize_function(examples, tokenizer):
    sources = [
        build_instruction_prompt(instruction)
        for instruction in examples['instruction']
    ]
    targets = [f"{output}\n{EOT_TOKEN}" for output in examples['output']]
    data_dict = preprocess(sources, targets, tokenizer)
    return data_dict


def train():
    parser = transformers.HfArgumentParser((ModelArguments, DataArguments, TrainingArguments))
    model_args, data_args, training_args = parser.parse_args_into_dataclasses()

    training_args.evaluation_strategy = "steps"
    training_args.eval_steps = 500
    training_args.save_steps = 500
    training_args.logging_steps = 100
    training_args.load_best_model_at_end = False
    training_args.metric_for_best_model = "eval_loss"
    training_args.greater_is_better = False

    if training_args.local_rank == 0:
        print('=' * 100)
        print("训练参数配置:")
        print(f"  评估策略: {training_args.evaluation_strategy}")
        print(f"  评估步数: {training_args.eval_steps}")
        print(f"  保存步数: {training_args.save_steps}")
        print(f"  日志步数: {training_args.logging_steps}")
        print('=' * 100)

    tokenizer = transformers.AutoTokenizer.from_pretrained(
        model_args.model_name_or_path,
        model_max_length=training_args.model_max_length,
        padding_side="right",
        use_fast=True,
        trust_remote_code=True
    )

    print("PAD Token:", tokenizer.pad_token, tokenizer.pad_token_id)
    print("BOS Token", tokenizer.bos_token, tokenizer.bos_token_id)
    print("EOS Token", tokenizer.eos_token, tokenizer.eos_token_id)

    if training_args.local_rank == 0:
        print("Load tokenizer from {} over.".format(model_args.model_name_or_path))

    model = transformers.AutoModelForCausalLM.from_pretrained(
        model_args.model_name_or_path,
        torch_dtype=torch.bfloat16
    )
    
    torch.cuda.empty_cache()

    if training_args.local_rank == 0:
        print("Load model from {} over.".format(model_args.model_name_or_path))

    raw_train_datasets = load_dataset(
        'json', 
        data_files=data_args.data_path, 
        split="train", 
        cache_dir=training_args.cache_dir
    )
    raw_eval_datasets = load_dataset(
        'json', 
        data_files=data_args.eval_data_path, 
        split="train", 
        cache_dir=training_args.cache_dir
    )

    if training_args.local_rank == 0:
        print(f"评估数据集大小: {len(raw_eval_datasets)}")

    train_dataset = raw_train_datasets.map(
        train_tokenize_function,
        batched=True,
        batch_size=3000,
        num_proc=32,
        remove_columns=raw_train_datasets.column_names,
        load_from_cache_file=True,
        desc="Running Encoding",
        fn_kwargs={"tokenizer": tokenizer}
    )

    eval_dataset = raw_eval_datasets.map(
        train_tokenize_function,
        batched=True,
        batch_size=3000,
        num_proc=32,
        remove_columns=raw_eval_datasets.column_names,
        load_from_cache_file=True,
        desc="Running Eval Encoding",
        fn_kwargs={"tokenizer": tokenizer}
    )

    if training_args.local_rank == 0:
        print("Training dataset samples:", len(train_dataset))
        print("Evaluation dataset samples:", len(eval_dataset))

    if training_args.local_rank == 0 and len(eval_dataset) > 0:
        print("检查评估数据集样本:")
        sample = eval_dataset[0]
        print(f"  input_ids长度: {len(sample['input_ids'])}")
        print(f"  labels长度: {len(sample['labels'])}")
        non_ignore_count = sum(1 for x in sample['labels'] if x != IGNORE_INDEX)
        print(f"  非IGNORE_INDEX的labels数量: {non_ignore_count}")
        
        if non_ignore_count > 0:
            response_start = (torch.tensor(sample['labels']) != IGNORE_INDEX).nonzero(as_tuple=True)[0]
            if len(response_start) > 0:
                print(f"  响应开始位置: {response_start[0].item()}")
            else:
                print("  警告: 未找到响应开始位置")

    data_collator = DataCollatorForSupervisedDataset(tokenizer=tokenizer)
    data_module = dict(train_dataset=train_dataset, eval_dataset=eval_dataset, data_collator=data_collator)

    trainer = ForwardSaveTrainer(
        model=model,
        tokenizer=tokenizer,
        args=training_args,
        ** data_module
    )

    generation_callback = GenerationEvalCallback(
        tokenizer=tokenizer,
        eval_dataset=eval_dataset,
        output_dir=os.path.join(training_args.output_dir, "eval_results"),
        eval_steps=training_args.eval_steps
    )
    trainer.add_callback(generation_callback)

    print("开始训练...")
    trainer.train()
    trainer.save_state()
    safe_save_model_for_hf_trainer(trainer=trainer, output_dir=training_args.output_dir)

if __name__ == "__main__":
    set_deterministic_seed(42)
    torch.cuda.empty_cache()
    train()