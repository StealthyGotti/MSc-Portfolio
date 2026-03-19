## Assignment: 1D Signal Sparse Recovery using Matching Pursuit Variants

This assignment explores Orthogonal Matching Pursuit (OMP) and Least Squares Orthogonal Matching Pursuit (LS-OMP) to reconstruct 1D sparse signals corrupted by Additive White Gaussian Noise (AWGN) over an overcomplete dictionary.

### Tasks Overview

* **Overcomplete Dictionary**: Construct a dictionary $D \in \mathbb{R}^{M \times N}$ by concatenating a 1D-DCT orthonormal basis and a 1D canonical basis to represent both harmonic components and localized spikes.
* **Signal Synthesis & Noise**: Generate a sparse representation $x_0$ (random DCT coefficients + spatial spike), synthesize the noise-free signal $s_0$, and corrupt it with Gaussian noise.
* **OMP Implementation**: Greedily approximate the signal. Select the best matching atom via correlation, then update all active coefficients jointly using Least Squares ($\min \|D_{\Omega} x - s\|_2$) to ensure the residual is orthogonal to the chosen support.
* **LS-OMP Implementation**: Enhance the sweep step by solving temporary Least Squares problems for each candidate atom, strictly selecting the one that minimizes the overall residual energy.
* **Algorithm Evaluation**: Compare the reconstructed signals, estimated coefficients, and noise robustness of OMP and LS-OMP against the fundamental limitations of standard MP.