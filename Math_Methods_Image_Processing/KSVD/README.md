## Assignment: Dictionary Learning for Image Patches using K-SVD

This assignment focuses on learning an optimal, overcomplete dictionary adapted to natural image patches using the K-SVD algorithm. Unlike relying on pre-defined mathematical bases (like the Discrete Cosine Transform), K-SVD iteratively learns a set of atoms directly from the data to achieve highly sparse representations.

### Tasks Overview

* **Training Data Preparation**: Extract a massive dataset of overlapping $p \times p$ patches from a set of natural training images. These patches are vectorized to form the training signal matrix $Y \in \mathbb{R}^{M \times N}$.
* **Dictionary Initialization**: Initialize the overcomplete dictionary $D \in \mathbb{R}^{M \times K}$ (where $K > M$). This is typically done by randomly sampling $K$ patches directly from the training data or by using an analytical basis like an overcomplete DCT.
* **Sparse Coding Stage**: Fix the current dictionary $D$ and compute the sparse representation matrix $X$ for all training signals in $Y$. This step utilizes Orthogonal Matching Pursuit (OMP) to find the coefficients, enforcing a strict sparsity constraint (e.g., maximum $T_0$ non-zero elements per signal).
* **Dictionary Update Stage**: Update the dictionary atoms one by one. For each atom $d_k$, isolate the residual error $E_k$ restricted only to the subset of signals that actively use $d_k$. Apply Singular Value Decomposition (SVD) to this restricted error matrix to simultaneously update the atom $d_k$ and optimize its corresponding non-zero coefficients in $X$.
* **Algorithm Evaluation**: Monitor the convergence of the algorithm by tracking the reduction of the total representation error $\|Y - DX\|_F^2$ over multiple iterations. Finally, visualize the learned dictionary to observe the emergence of oriented edges, structural primitives, and textural patterns characteristic of the training images.