#ifndef SLAE__JACOBI_HPP
#define SLAE__JACOBI_HPP

#include <iostream>
#include <fstream>
#include "../CSR_matrix.hpp"
#include "../Dense_matrix.hpp"

template <typename T>
std::vector<T> Jacobi(const Matrix<T> &A, const std::vector<T> &b, const std::vector <T> &x, T tolerance, int dim1, int dim2){
    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/Yakobi.txt");
    std::vector<T> x1 = x;
    std::vector<T> r = A.multiply(x1)-b;
    int n = 0;
    while(mod(r) > tolerance){
        x1 = mul_components(static_cast<const std::vector<T>>(inverse_diagonal(A, dim1, dim2)),b-static_cast<const std::vector<T>>(A.multiply_LU(x1)));
        r = A.multiply(x1) - b;
        file << mod(r) << " " << n << std::endl;
        n++;
    }
    return x1;
}


#endif //SLAE__JACOBI_HPP
