## Challenge: 2D-DCT Image Denoising

This challenge focuses on restoring images corrupted by Additive White Gaussian Noise (AWGN) using advanced patch-based denoising techniques in the 2D Discrete Cosine Transform (DCT) domain.

### Tasks Overview

* **Patch Extraction & 2D-DCT**: Divide the noisy image into overlapping $ p\times p $ patches and compute their spatial frequency representation using the 2D-DCT.

* **First Pass - Hard Thresholding (HT)**: Apply a hard threshold to the DCT coefficients of each noisy patch to discard noise-dominated frequencies, ensuring the DC component remains unaltered. Reconstruct the image by aggregating the inverse-transformed patches, weighting them adaptively based on their sparsity (number of non-zero coefficients).

* **Second Pass - Empirical Wiener Filtering**: Use the initial HT-denoised image as a prior (oracle) to perform empirical Wiener filtering on the overlapping patches in the DCT domain. This step refines the coefficients by estimating the true signal variance against the noise variance.

* **Reconstruction & Performance Evaluation**: Reconstruct the final image by aggregating the Wiener-filtered patches. Evaluate the effectiveness of the two-step denoising pipeline by calculating and comparing the Peak Signal-to-Noise Ratio (PSNR) of the noisy image, the intermediate HT estimate, and the final Wiener estimate.