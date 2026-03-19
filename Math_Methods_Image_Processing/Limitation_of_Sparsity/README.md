## Assignment: 1D-DCT Signal Denoising and Sparsity

This assignment focuses on the concept of signal sparsity and the restoration of 1D signals corrupted by Additive White Gaussian Noise (AWGN) using Hard Thresholding in the 1D Discrete Cosine Transform (DCT) domain.

### Tasks Overview

* **1D-DCT Basis Generation**: Construct the 1D-DCT orthonormal basis matrix $D \in \mathbb{R}^{N \times M}$ to enable transformations between the spatial/time domain and the frequency domain.

* **Sparse Signal Synthesis & Noise Addition**: Generate an $L$-sparse representation vector and synthesize the corresponding noise-free signal $y$ in the signal domain. Corrupt the signal with Gaussian noise to obtain a noisy observation $s$.

* **Hard Thresholding (HT) Denoising**: Compute the DCT coefficients of the noisy signal and apply a hard thresholding operator. By retaining only the $L$-largest coefficients in absolute value, discard the noise-dominated frequencies and reconstruct the denoised signal $\hat{y}$ via the inverse transformation.

* **Sparsity Analysis & Evaluation**: Modify the signal by introducing a random localized spike (which is sparse in the canonical basis but not in the DCT domain) and repeat the noise addition and HT denoising process. Evaluate the reconstruction results to demonstrate the fundamental principle that thresholding-based denoising is only effective when the signal is inherently sparse in the chosen transform domain.
