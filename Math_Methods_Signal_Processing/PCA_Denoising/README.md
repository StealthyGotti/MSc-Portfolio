## Assignment: Global PCA Image Denoising and Patch Reconstruction

This assignment focuses on the restoration of 2D images corrupted by Additive White Gaussian Noise (AWGN) by exploiting the sparse representation of image patches within a globally learned Principal Component Analysis (PCA) domain.

### Tasks Overview

* **Patch Extraction & Preprocessing**: Implement a sliding window mechanism with a configurable `STEP` size to extract overlapping $p \times p$ patches from the noisy observation. Flatten and stack these patches to construct the global data matrix $S$, followed by zero-centering the data to obtain $\tilde{S}$ for proper statistical analysis.

* **Global PCA Basis Generation**: Compute the data-driven orthonormal PCA basis matrix $U$. To handle high-resolution images efficiently, derive the principal components through the eigendecomposition of the covariance matrix $C = \tilde{S}\tilde{S}^T$ rather than performing a computationally expensive full Singular Value Decomposition (SVD) on the entire dataset.

* **Hard Thresholding (HT) Denoising**: Project the noisy centered patches onto the learned PCA basis. Apply a hard thresholding operator using a noise-dependent threshold $\tau$ to discard low-energy, noise-dominated coefficients while retaining the principal structural components of the signal. 

* **Synthesis & Overlap Averaging**: Reconstruct the denoised patches via the inverse PCA transformation and reposition them into the 2D spatial domain. Effectively manage overlapping patches by accumulating pixel contributions and normalizing the final estimated image $\hat{y}$ using a spatial weight matrix, thereby preventing block artifacts and ensuring smooth transitions.

* **Performance & Trade-off Analysis**: Evaluate the quality of the reconstructed image using the Peak Signal-to-Noise Ratio (PSNR) metric. Analyze the fundamental trade-off between computational complexity (execution time) and restoration quality by varying the sliding window `STEP` size, identifying the optimal parameters for efficient denoising.