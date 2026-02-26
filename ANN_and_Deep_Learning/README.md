# AN2DL Challenges - MSc Computer Science @ Polimi

This repository contains the solutions developed by my team for the *Artificial Neural Networks and Deep Learning* course challenges.

---

## 📊 Challenge 1: Multivariate Time Series Classification
**Goal:** Classify multivariate sequences of 160 time steps into three pain intensity classes (no pain, low pain, high pain).

### 🛠️ Methodology
* **Hybrid Architecture:** A static branch using Embedding layers for categorical features and a dynamic branch for temporal data.
* **Pipeline:** Parallel CNNs for multiple temporal scales, Squeeze-and-Excitation blocks, a bidirectional GRU, and a Transformer Encoder.
* **Preprocessing:** Implementation of Window Slicing (Window=20, Stride=10) to triple the training data and addition of cyclical time features (sin/cos).
* **Training Strategy:** 5-Fold Stratified Cross-Validation, Categorical Cross-Entropy with class weights, AdamW optimizer, and Label Smoothing.
---

## 🔬 Challenge 2: Biological Image Recognition
**Goal:** Classify histological images (WSI) into four molecular subtypes: Luminal A, Luminal B, HER2(+), and Triple Negative.

### 🛠️ Methodology
* **Dual-Branch Network:** Simultaneous processing of RGB images (ConvNeXt Tiny backbone) and binary segmentation masks.
* **Data Augmentation:** Strong pipeline including geometric transformations (flips, rotations), ColorJitter, and CutMix regularization.
* **Optimization:** Utilized the Lion optimizer with a CosineAnnealingWarmRestarts scheduler and CrossEntropyLoss with class weights.
* **Inference:** Weighted ensemble of the three best-performing folds from the stratified K-Fold.
---

## 👥 Team (iFormaggini)
* Federico Pinto 
* Mattia Gotti
* Michele Milani
* Stefano Pedretti