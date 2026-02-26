
#include <Eigen/Dense>
#include <Eigen/Sparse>

#include <unsupported/Eigen/SparseExtra>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>

using namespace std;
using namespace Eigen;
 
int
main(int argc, char *argv[])
{
Eigen::SparseMatrix<double> sol;
    Eigen::loadMarket(sol,"sol.mxt");

    auto sol_uchar =Eigen::MatrixXd<unsigned char, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>(
            256*341,1);
    sol_uchar = sol.unaryExpr([](double val) -> unsigned char {
        return static_cast<unsigned char>(std::clamp(val, 0.0, 255.0));
    }).cast<unsigned char>();
    stbi_write_png("sol.png", 256, 341, 1, sol_uchar.data(), 256);
    return 0;
}