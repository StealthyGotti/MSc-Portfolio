## Assignment 24: Multi Model Fitting using Sequential RANSAC
This assignment explores the use of standard RANSAC and Sequential RANSAC to robustly fit multiple 2D line models to spatial point cloud data corrupted by random outliers.

## Tasks Overview
* **Data Preparation & Outliers**: Load 2D spatial datasets (e.g., star5.mat) and dynamically inject uniform random outliers within the data's bounding box to evaluate model robustness.

* **DLT Line Fitting**: Implement the Direct Linear Transform (DLT) using Singular Value Decomposition (SVD) to estimate 2D line parameters from a sample of points and compute orthogonal distance residuals.

* **Standard RANSAC**: Implement a basic RANSAC algorithm to find a single best-fitting line by iteratively sampling points and maximizing the inlier consensus within a given threshold (epsi).

* **Sequential RANSAC**: Greedily extract multiple line models from the dataset. Find the best matching model via RANSAC, store it, remove its consensus set (inliers) from the working data, and repeat.

* **Stopping Criteria**: Implement termination logic to stop the sequential extraction when the current consensus falls below an absolute minimum (E_min) or drops significantly compared to the previous iteration (drop_ratio).

* **Visualization**: Iteratively plot the extracted line models, display their respective inlier bands, and compare the sequence of estimated models against the provided ground truth clusters.