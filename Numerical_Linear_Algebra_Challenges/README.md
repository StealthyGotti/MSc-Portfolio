# Image Processing Project

## Overview

This project is divided into two challenges that implement various image processing techniques using **Eigen** (C++) and **LIS** (C). The starting point is a provided input image. The challenges are:

- **Challenge 1:** Apply image filters and find the approximate solution of a linear system to process a greyscale image.
- **Challenge 2:** Apply Singular Value Decomposition (SVD) for image compression and noise reduction.

## Input Image
![Input Image](project_src/challenge1/einstein.jpg)

## Challenge 1: Image Filtering and Linear System Approximation

- **Objective:** Process a greyscale image by applying various filters and approximating the solution of a linear system.
- **Libraries Used:** Eigen (C++), LIS (C)
- **Implementation Details:**  
  The implementation leverages Eigen for efficient matrix operations and LIS for solving linear systems. Adjust the filter parameters and system settings as needed for optimal performance.

[Documentation](project_src/challenge1/Challenge1_description.pdf)

## Challenge 2: Image Compression and Noise Reduction with SVD

- **Objective:** Utilize Singular Value Decomposition (SVD) to compress the image and reduce noise.
- **Libraries Used:** Eigen (C++), LIS (C)
- **Implementation Details:**  
  The challenge involves decomposing the image matrix using SVD, filtering out noise components, and reconstructing a compressed version of the image while retaining its essential features.

[Documentation](project_src/challenge2/Challenge.pdf)



