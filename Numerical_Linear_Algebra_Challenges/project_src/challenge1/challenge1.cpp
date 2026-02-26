#include <Eigen/Dense>
#include <unsupported/Eigen/SparseExtra>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>

using namespace std;
using namespace Eigen;


void
convolution_matrix(
    MatrixXd &filter, SparseMatrix<double> &out, int height, int width
)
{
  out.reserve(VectorXi::Constant(height * width, 9));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
#pragma unroll 3
      for (int k = 0; k < 3; k++) {
#pragma unroll 3
        for (int l = 0; l < 3; l++) {
          int row = i + k - 1;
          int col = j + l - 1;
          if (row >= 0 && row < height && col >= 0
              && col < width) { // less branching, more readable code, imo
            out.insert(i * width + j, row * width + col) = filter(k, l);
          }
        }
      }
    }
  }
}

int
main(int argc, char *argv[])
{
  // load image
  int width, height, channels;
  // unsigned char *img
  //     = stbi_load("./pengbrew.png", &width, &height, &channels, 0);
  unsigned char *img = stbi_load(
      "./Einstein.jpg", &width, &height, &channels, 0
  );

  if (!img) {
    cout << "Error loading the image" << endl;
    return 1;
  }

  cout << "Image loaded: " << width << "x" << height << " with " << channels
       << " channels" << endl;

  // load image in a matrix
  MatrixXd grey(height, width);

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      int index  = (i * width + j);
      grey(i, j) = static_cast<double>(img[index]);
    }
  }
  stbi_image_free(img);

 cout << grey.cols() << grey.rows()<<endl;

  // create matrix with noise
  MatrixXd noisy_grey(height, width);
  int min = -50;
  int max = 50;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int noise = min + (rand() % static_cast<int>(max - min + 1));
      if ((grey(i, j) + noise) > 255) noise = 255 - grey(i, j);
      if ((grey(i, j) + noise) < 0) noise = grey(i, j);
      noisy_grey(i, j) = grey(i, j) + noise;
    }
  }

  uint8_t *pixels = new uint8_t[width * height];

  int index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixels[index++] = uint8_t(noisy_grey(i, j));
    }
  }
  // create noisy png
  stbi_write_png(
      "noisy.png", width, height, channels, pixels, width * channels
  );


  // matrix to vector
  VectorXd v(width * height);
  VectorXd w(width * height);
   saveMarket(w,"w.mtx");

  index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      v[index] = grey(i, j);
      w[index] = noisy_grey(i, j);
      index++;
    }
  }

  // print length and norm
  int size_of_v = v.rows();
  int size_of_w = w.rows();
  cout << "rows of v: " << size_of_v << endl;
  cout << "rows of w: " << size_of_w << endl;
  cout << "norm of v: " << v.norm() << endl;

  // Matrix A1
  double a = 1.0 / 9;
  MatrixXd Hav2 = MatrixXd(3, 3);
    Hav2 << a, a, a,
    	    a, a, a,
    	    a, a, a;
  
  SparseMatrix<double> A1(height * width, height * width);
  convolution_matrix(Hav2, A1, height, width);

  cout << "Number of non zero elements is A1 is: " << A1.nonZeros() << endl;
  cout << "is A1 symmetric? " << (A1.isApprox(A1.transpose()) ? "yes" : "no")
       << endl;

  VectorXd filtered_w = A1 * w;

  for (int i = 0; i < size_of_w; i++) {
    pixels[i] = uint8_t(filtered_w(i));
  }
  stbi_write_png(
      "filtered_noisy.png", width, height, channels, pixels, width * channels
  );

  // Matrix A2
  MatrixXd Hsh2 = MatrixXd(3, 3);
    Hsh2 << 0, -3,  0,
    	    -1,  9, -3,
    	    0, -1,  0;

  SparseMatrix<double> A2(height * width, height * width);
  convolution_matrix(Hsh2, A2, height, width);

  cout << "Number of non zero elements is A2 is: " << A2.nonZeros() << endl;
  cout << "is A2 symmetric? " << (A2.isApprox(A2.transpose()) ? "yes" : "no")
       << endl;

  VectorXd sharp_v = A2 * v;

  for (int i = 0; i < size_of_w; i++) {
    if (sharp_v[i] > 255) sharp_v[i] = 255;
    if (sharp_v[i] < 0) sharp_v[i] = 0;
    pixels[i] = uint8_t(sharp_v(i));
  }
  stbi_write_png(
      "sharp.png", width, height, channels, pixels, width * channels
  );
  saveMarket(A2, "A2.mtx");

  // Matrix A3
  MatrixXd Hlap = MatrixXd(3, 3);
    Hlap << 0, -1,  0,
    	   -1,  4, -1,
     	    0, -1,  0;

  SparseMatrix<double> A3(height * width, height * width);
  convolution_matrix(Hlap, A3, height, width);
  cout << "Number of non zero elements is A3 is: " << A3.nonZeros() << endl;
  cout << "is A3 symmetric? " << (A3.isApprox(A3.transpose()) ? "yes" : "no")
       << endl;
  saveMarket(A3, "A3.mtx");
  // saveMarket(w, "w.mtx");


  VectorXd tap_v = A3 * v;

  for (int i = 0; i < size_of_v; i++) {
    if (tap_v[i] > 255) tap_v[i] = 255;
    if (tap_v[i] < 0) tap_v[i] = 0;
    pixels[i] = uint8_t(tap_v(i));
  }
  stbi_write_png("tap.png", width, height, channels, pixels, width * channels);

  auto edge_image = A3 * v;
    auto edge_image_matrix_uchar = Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>(
            height, width);
    edge_image_matrix_uchar = edge_image.unaryExpr([](double val) -> unsigned char {
        return static_cast<unsigned char>(std::clamp(val, 0.0, 255.0));
    }).cast<unsigned char>();
    stbi_write_png("edge.png", width, height, 1, edge_image_matrix_uchar.data(), width);

  //(I + A3) * y = w
  setNbThreads(2); 

  SparseMatrix<double> I(height * width, height * width);
  I.setIdentity();
  SparseMatrix<double> A3_plus_I
      = A3 + I; // A3 is symmetric, so A3 + I is also symmetric
  ConjugateGradient<Eigen::SparseMatrix<double>, Lower | Upper> // faster
      cg; // since A3 is symmetric we can use a conjugate gradient solver
  double tolerance = 1e-10;
  cg.setTolerance(tolerance);
  cg.compute(A3_plus_I);
  VectorXd y = cg.solve(w);
  cout << "Conjugate gradient solver: "
       << (cg.info() == Eigen::Success ? "converged" : "did not converge")
       << endl;
  cout << "Residual: " << cg.error() << std::endl;
  cout << "Number of iterations: " << cg.iterations() << std::endl;

  for (int i = 0; i < size_of_v; i++) {
    if (y[i] > 255) y[i] = 255;
    if (y[i] < 0) y[i] = 0;
    pixels[i] = uint8_t(y(i));
  } 
  stbi_write_png("tap.png", width, height, channels, pixels, width * channels);

  return 0;
}
