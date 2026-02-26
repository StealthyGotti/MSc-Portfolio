#include <Eigen/Dense>
#include <unsupported/Eigen/SparseExtra>
#include <Eigen/SparseCore>
#include <Eigen/IterativeLinearSolvers>
#include <Eigen/Eigenvalues> 
#include <Eigen/SVD>
#include <cmath>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>

using namespace std;
using namespace Eigen;
using Mat= Eigen::MatrixXd;
using SpMat=Eigen::SparseMatrix<double>;
using SpVec=Eigen::VectorXd;

SpVec Max(SpVec eig){
    SpVec ris(2);
    int max=0;

    for(int i=0;i<eig.rows();i++){
    if(eig(i)>ris(0)){
        ris(1)=ris(0);
        ris(0)=eig(i);
    }

    if(ris(1)<eig(i) && eig(i)<ris(0)){
        ris(1)=eig(i);
    }

    }

    return ris;
}

Mat construct_D( const Mat &V,const SpVec &S,int k, int width ){
    Mat D(width,k);
    for(int i=0; i<k; i++){
        D.col(i)=S(i)*V.col(i);
    }
   return D;
}

// function to save images
int save_image(const MatrixXd &matrix, int height, int width, const string &output_image_path)
{


    // Saves an unsigned char-type matrix with a dynamic number of rows and columns using RowMajor allocation
    Matrix<unsigned char, Dynamic, Dynamic, RowMajor> image(height, width);

    // Use Eigen's unaryExpr to map the grayscale values (0.0 to 1.0) to 0 to 255
    image = matrix.unaryExpr([](double val) -> unsigned char
                             { return static_cast<unsigned char>(val); });

    // Save the image using stb_image_write
    if (stbi_write_png(output_image_path.c_str(), width, height, 1, image.data(), width) == 0)
    {
        cerr << "Error: Could not save noise image" << endl;
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]){
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
  Mat grey(height, width);

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      int index  = (i * width + j);
      grey(i, j) = static_cast<double>(img[index]);
    }
  }
  stbi_image_free(img);
   
  Mat grey2T = grey.transpose()*grey;

  cout<< "norm of A^t*A: "<< grey2T.norm()<< endl;

  Eigen::SelfAdjointEigenSolver<Mat> eigensolver(grey2T);
   if (eigensolver.info() != Eigen::Success) abort();
     SpVec ris= Max(eigensolver.eigenvalues());
   cout << "The singular values of A are: \n" << sqrt(ris(0)) <<endl;
   cout << sqrt(ris(1)) <<endl;

   saveMarket(grey2T,"A^tA.mtx");

   //5e+07 n-ite: 6 --> point4 after testing on Lis
   // command: mpirun -n 4 ./eigen1 A^tA.mtx eigvec.txt hist.txt -e pi -etol 10e-8 -shift 5e+7
  //end of first 4 points
  
  //point 5
  Eigen::JacobiSVD<Mat> svd(grey, Eigen::ComputeFullU | Eigen::ComputeFullV);
  Mat U=svd.matrixU();
  Mat V=svd.matrixV();
  SpVec S=svd.singularValues();
  
  cout<< "norm of Singular Values:"<<svd.singularValues().norm()<<endl;

  //point 6
   int k1=40 , k2=80;
   Mat C_k1 = svd.matrixU().leftCols(k1);
   Mat D_k1 =construct_D(V,S,k1,width);
   
   Mat C_k2 = svd.matrixU().leftCols(k2);
   Mat D_k2 = construct_D(V,S,k2,width);
   
   cout<<"Non zeros entries of C with k=40: "<<C_k1.nonZeros()<<endl<<"Non zeros entries of C with k=80: "<<C_k2.nonZeros()<<endl;
   cout<<"Non zeros entries of D with k=40: "<<D_k1.nonZeros()<<endl<<"Non zeros entries of D with k=80: "<<D_k2.nonZeros()<<endl;

   Mat COMPRESSED_AK1= C_k1 * D_k1.transpose(); 
   Mat COMPRESSED_AK2= C_k2 * D_k2.transpose(); 
    
    for(int i=0 ; i<height;i++){
        for(int j=0;j<width;j++){
            if(COMPRESSED_AK1(i,j)>255){
                COMPRESSED_AK1(i,j)=255;
            }
            if(COMPRESSED_AK1(i,j)<0){
                COMPRESSED_AK1(i,j)=0;
            }

            if(COMPRESSED_AK2(i,j)>255){
                COMPRESSED_AK2(i,j)=255;
            }
            if(COMPRESSED_AK2(i,j)<0){
                COMPRESSED_AK2(i,j)=0;
            }
        }
    }

    save_image(COMPRESSED_AK1,height,width,"compressed_ak1.png");
    save_image(COMPRESSED_AK2,height,width,"compressed_ak2.png");
  

  //point 8 

  Mat checkerboard(200,200);
  for(int i=0 ; i<200;i++){
        for(int j=0;j<200;j++){
            if(i<25 || (i>=50 && i<75) || (i>=100 && i<125) || (i>=150 && i<175)){

            if(j<25 || (j>=50 && j<75) || (j>=100 && j<125) || (j>=150 && j<175)) {
                checkerboard(i,j) = static_cast<double>(0);
            }else{
                checkerboard(i,j) = static_cast<double>(255);
            } 

            }else{
                if(j<25 || (j>=50 && j<75) || (j>=100 && j<125) || (j>=150 && j<175)) {
                checkerboard(i,j) = static_cast<double>(255);
            }else{
                checkerboard(i,j) = static_cast<double>(0);
            } 
            }  
        }
    }
   cout<<" norm of checkerboard: "<< checkerboard.norm()<<endl;

   Mat noisy_checkerboard(200, 200);
  int min = -50;
  int max = 50;

  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 200; j++) {
      int noise = min + (rand() % static_cast<int>(max - min + 1));
      
      noisy_checkerboard(i, j) = checkerboard(i,j) + noise;
    }
  }

  for(int i=0 ; i<200;i++){
        for(int j=0;j<200;j++){
            if(noisy_checkerboard(i, j)>255){
                noisy_checkerboard(i, j)=255;
            }
            if(noisy_checkerboard(i, j)<0){
                noisy_checkerboard(i, j)=0;
            }

            
        }
    }

  save_image(noisy_checkerboard,200,200,"noisy_checkerboard.png");
   
   Eigen::JacobiSVD<Mat> noisy_svd(noisy_checkerboard, Eigen::ComputeFullU | Eigen::ComputeFullV);

   SpVec noisy_S=noisy_svd.singularValues();
    Mat noisy_U=noisy_svd.matrixU();
    Mat noisy_V=noisy_svd.matrixV();
   cout<<"two largest singular value of noisy checkerboard:"<<endl<<Max(noisy_S)<<endl;

   int noisy_k1=5,noisy_k2=10;
  
   Mat noisy_C_k1 = noisy_svd.matrixU().leftCols(noisy_k1);
   cout<<"size of C_k1 of checkerboard: "<<noisy_C_k1.rows()<<" x "<<noisy_C_k1.cols()<<endl;
   Mat noisy_D_k1 =construct_D(noisy_V,noisy_S,noisy_k1,200);
   cout<<"size of D_k1 of checkerboard: "<<noisy_D_k1.rows()<<" x "<<noisy_D_k1.cols()<<endl;
   
   Mat noisy_C_k2 = noisy_svd.matrixU().leftCols(noisy_k2);
   cout<<"size of C_k2 of checkerboard: "<<noisy_C_k2.rows()<<" x "<<noisy_C_k2.cols()<<endl;
   Mat noisy_D_k2 = construct_D(noisy_V,noisy_S,noisy_k2,200);
   cout<<"size of D_k2 of checkerboard: "<<noisy_D_k2.rows()<<" x "<<noisy_D_k2.cols()<<endl;

    Mat COMPRESSED_noisy_AK1= noisy_C_k1 * noisy_D_k1.transpose(); 
    Mat COMPRESSED_noisy_AK2= noisy_C_k2 * noisy_D_k2.transpose(); 
    
    for(int i=0 ; i<200;i++){
        for(int j=0;j<200;j++){
            if(COMPRESSED_noisy_AK1(i,j)>255){
                COMPRESSED_noisy_AK1(i,j)=255;
            }
            if(COMPRESSED_noisy_AK1(i,j)<0){
                COMPRESSED_noisy_AK1(i,j)=0;
            }

            if(COMPRESSED_noisy_AK2(i,j)>255){
                COMPRESSED_noisy_AK2(i,j)=255;
            }
            if(COMPRESSED_noisy_AK2(i,j)<0){
                COMPRESSED_noisy_AK2(i,j)=0;
            }
        }
    }
    
    save_image(COMPRESSED_noisy_AK1,200,200,"compressed_noisy_ak1.png");
    save_image(COMPRESSED_noisy_AK2,200,200,"compressed_noisy_ak2.png");
   
   return 0;
}
