## Assignment: Image Denoising using Orthogonal Matching Pursuit

This assignment focuses on removing Additive White Gaussian Noise (AWGN) from images using Orthogonal Matching Pursuit (OMP). The method leverages the principle that natural image patches admit highly sparse representations when expressed over an overcomplete learned dictionary.

### Tasks Overview

* **Dictionary Preparation**: Load a pre-trained overcomplete dictionary $D \in \mathbb{R}^{M \times N}$ of natural image patches. Augment the dictionary by concatenating a constant DC atom, ensuring that patches with non-zero means can be accurately represented and processed.
* **Signal Corruption**: Simulate a noisy real-world observation by taking a clean target image and corrupting it with Additive White Gaussian Noise (AWGN) based on a specific standard deviation $\sigma_{noise}$.
* **Patch-wise Sparse Coding**: Extract overlapping $p \times p$ patches from the corrupted image. For each noisy patch $s$, apply the OMP algorithm to greedily approximate its sparse representation $x$. The iterative selection stops when the residual error falls below a noise-dependent tolerance threshold ($\|D x - s\|_2 \leq \tau$).
* **Image Aggregation**: Reconstruct the localized denoised patches by computing $\hat{s} = D x$ and map them back to their original 2D spatial coordinates. A weight matrix is maintained to correctly average the overlapping regions, which naturally suppresses block artifacts and enhances the final smoothing.
* **Algorithm Evaluation**: Quantify the effectiveness of the sparse reconstruction by computing the Peak Signal-to-Noise Ratio (PSNR) before and after the denoising process, supported by a side-by-side visual comparison of the noisy and recovered images.