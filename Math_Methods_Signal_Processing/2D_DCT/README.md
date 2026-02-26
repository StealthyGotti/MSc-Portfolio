## 💻 Assignment 2: 2D-DCT & JPEG Compression
The second assignment introduces 2D image transformations and the fundamental concepts of image compression using the 2D Discrete Cosine Transform (DCT).

### Tasks Overview:
* **2D-DCT Dictionary:** Construct the 2D-DCT dictionary matrix for $p \times p$ image patches using the inverse 1D-DCT. Verify the orthonormality of the generated dictionary and visualize its atoms (basis functions).
* **Separable 2D-DCT:** Exploit the separability property of the DCT to compute the 2D transform more efficiently using 1D matrices. Compare and validate the coefficients obtained through this method against the standard dictionary multiplication.
* **JPEG Compression Pipeline:** Implement the core algorithm of JPEG compression. Divide an image into non-overlapping $4 \times 4$ patches, apply the 2D-DCT, and perform hard thresholding to discard high-frequency coefficients (while carefully preserving the DC component).
* **Performance Evaluation:** Apply the inverse 2D-DCT to reconstruct the compressed image. Finally, evaluate the trade-off between visual quality and memory savings by computing the Peak Signal-to-Noise Ratio (PSNR) and the Compression Ratio.