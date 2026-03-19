## Assignment: 1D Signal Sparse Recovery using Matching Pursuit

This assignment explores the concept of signal sparsity and the reconstruction of 1D signals corrupted by Additive White Gaussian Noise (AWGN) using the Matching Pursuit (MP) greedy algorithm over an overcomplete dictionary.

### Tasks Overview

* **Overcomplete Dictionary Generation**: Construct an overcomplete dictionary matrix $D \in \mathbb{R}^{M \times N}$ by concatenating a 1D-Discrete Cosine Transform (DCT) orthonormal basis and a 1D standard canonical basis (Kronecker delta). This allows the representation of signals containing both localized spikes and harmonic components.

* **Sparse Signal Synthesis & Noise Addition**: Generate a sparse representation vector $x_0$ consisting of a few random active coefficients in the DCT domain alongside a high-energy localized spike in the spatial domain. Synthesize the corresponding noise-free signal $s_0$ and corrupt it with varying levels of Gaussian noise to obtain the observation $s$.

* **Matching Pursuit (MP) Implementation**: Implement the iterative Matching Pursuit algorithm to greedily approximate the noisy signal. At each iteration, perform a sweep step to compute the inner products between the current residual and the dictionary atoms, selecting the atom with the maximum absolute projection to sequentially update the sparse coefficients and minimize the residual norm.

* **Sparsity Analysis & Noise Robustness Evaluation**: Visualize and evaluate the reconstructed signal and the estimated coefficients. Analyze the fundamental limitations of the MP algorithm when operating under high noise conditions (low SNR), demonstrating how a high noise variance can mislead the greedy selection step into incorrectly fitting noise-dominated components instead of the true underlying sparse signal.