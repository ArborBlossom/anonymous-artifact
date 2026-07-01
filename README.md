# Anonymous Artifact Package

This repository provides the anonymized artifact package for double-anonymous review.

The package contains source code, tool implementation, configuration files, sample data, error/performance records, training code, and partial training data used to support the main experimental results. The artifact has been prepared for review purposes and does not contain author-identifying information.

Upon acceptance, we will release the complete version of the dataset and artifact package in a public archival repository.

## Repository Structure

```text
.
├── 1.SciMath-Kernel/
│   ├── sample programs
│   ├── configuration files
│   ├── error data
│   └── performance data
│
├── 2.Clang-tools-extra/
│   └── loop-convert and related Clang tooling implementation
│
├── 3.GenMPO-train-infer/
│   ├── training code
│   ├── inference code
│   ├── training environment files
│   └── MACE loss implementation
│
└── 4.thesis-intermediate-data/
    ├── partial training data
    ├── intermediate evaluation data
```

## 1. SciMath-Kernel Samples

The directory `1.SciMath-Kernel/` contains a subset of the SciMath-Kernel samples used in our experiments.

The released subset includes:

- program source files;
- configuration files;
- error data;
- performance data;

Due to size and review-stage constraints, this repository currently contains a partial version of the SciMath-Kernel dataset. Upon acceptance, we will release the complete SciMath-Kernel dataset together with the final artifact package.

## 2. Clang Tooling Implementation

The directory `2.Clang-tools-extra/` contains our Clang tooling implementation.

The tool was developed and tested with the following Clang environment:

```text
clang version 10.0.0-4ubuntu1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

The `loop-convert` component contains our modified `clang-tools-extra` implementation. After compiling the corresponding Clang tools, the generated tool can be used to process the target programs in the dataset.

A typical build workflow is:

```bash
# Build LLVM/Clang with clang-tools-extra enabled.
# Then compile the loop-convert component together with the Clang tools.
```

Please refer to the source files and configuration files in `2.Clang-tools-extra/` for the specific tool implementation used in our experiments.

## 3. Training and Inference Code

The directory `3.GenMPO-train-infer/` contains the training and inference code used in our experiments.

This part includes:

- model training scripts;
- inference scripts;
- training environment information;
- implementation of the MACE loss function.

The MACE loss function is implemented by modifying the `loss-utils` component in the Transformer SDK. The relevant implementation files are included in this artifact package.

A typical usage workflow is:

```bash
# Install the required environment.
# Please refer to the environment files in 3.GenMPO-train-infer/.

# Run training.
python train.py

# Run inference.
python infer.py
```

Depending on the local environment and hardware configuration, paths and runtime parameters may need to be adjusted.

## 4. Partial Training and Intermediate Data

The directory `4.thesis-intermediate-data/` contains partial training data and intermediate result files used for analysis.

The released files include:

- partial training data;
- intermediate evaluation data;
- MACE evaluation results;
- result files used to generate tables and figures.

The complete training data will be released after acceptance, together with the complete artifact package.

## Artifact Scope During Double-Anonymous Review

This repository is intended for double-anonymous review. Therefore, some information has been anonymized or partially released at this stage.

The current artifact supports inspection of:

- representative SciMath-Kernel samples;
- the Clang tooling implementation;
- the training and inference pipeline;
- the MACE loss implementation;
- partial training and evaluation data;
- intermediate result files used in the paper.

The full dataset and complete artifact package will be made publicly available after acceptance.

## Notes for Reviewers

This artifact is provided to help reviewers inspect the implementation and reproduce representative parts of the experimental workflow.

Because the repository is anonymized for double-anonymous review, author-identifying metadata has been removed where possible. A complete public version with full metadata, the complete dataset, and an archival DOI will be provided upon acceptance.

## Data Availability

An anonymized artifact package containing source code, tool implementation, configuration files, sample data, and reproduction-related intermediate results is available in this repository for review.

The complete SciMath-Kernel dataset and the final artifact package will be publicly released upon acceptance.
