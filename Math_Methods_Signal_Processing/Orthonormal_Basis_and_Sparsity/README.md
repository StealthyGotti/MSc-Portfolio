## 💻 Assignment 1: Orthonormal Basis & Sparsity
The first assignment introduces analysis, synthesis, and sparsity using the Discrete Cosine Transform.

### Tasks Overview:
* **Generate the Basis:** Generate the DCT type II basis in dimension M using the cosine formula. Each vector is then divided by its l2 norm.
* **Analysis and Synthesis:** Load ECG traces and compute their representation with respect to the generated DCT basis. Then, reconstruct the signal from these coefficients and verify if the reconstruction is perfect.
* **Denoising via Sparsity:** Add noise to the signal. Enforce sparsity to get rid of the noise by performing thresholding in the transformed domain. This involves keeping the L largest coefficients or keeping all coefficients above a certain threshold. Finally, apply the inverse transform to reconstruct the denoised signal.
