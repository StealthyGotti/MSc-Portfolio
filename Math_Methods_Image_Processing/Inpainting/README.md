## Assignment: Image Inpainting and Denoising using Orthogonal Matching Pursuit

This assignment explores the use of Orthogonal Matching Pursuit (OMP) to reconstruct images corrupted by missing pixels (inpainting) and Additive White Gaussian Noise (AWGN) relying on sparse representations over a pre-trained dictionary.

### Tasks Overview

* **Dictionary Preparation**: Load a learned overcomplete dictionary of natural image patches $D$ and augment it by concatenating a constant DC atom to effectively represent patches with non-zero means.
* **Signal Corruption**: Simulate real-world degradation by adding Gaussian noise to the original image and applying a random binary mask to arbitrarily remove a specified percentage of pixels (e.g., 25% dead pixels).
* **Patch-wise OMP Implementation**: Greedily approximate the sparse coefficients $x$ for overlapping $p \times p$ patches. The algorithm operates strictly on the known valid pixels by extracting a sub-dictionary projection operator and uses a dynamic stopping tolerance $\tau = \sigma_{noise} \sqrt{N_{known}}$.
* **Image Aggregation**: Reconstruct the localized patches via $s_{hat} = D x$ and aggregate them back into the global 2D image space. A weight matrix is maintained to correctly average overlapping overlapping regions and avoid block artifacts.
* **Algorithm Evaluation**: Assess the effectiveness of the sparse reconstruction by visually comparing the results and computing the Peak Signal-to-Noise Ratio (PSNR) before and after the OMP inpainting process.