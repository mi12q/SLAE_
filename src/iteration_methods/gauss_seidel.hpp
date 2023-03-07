#ifndef SLAE__GAUSS_SEIDEL_HPP
#define SLAE__GAUSS_SEIDEL_HPP
#include <iostream>
#include <fstream>
#include "../CSR_matrix.hpp"
#include "../Dense_matrix.hpp"

template <typename T>
std::vector<T> Gauss_seidel(const Matrix<T> &A, const std::vector<T> &b, const std::vector <T> &x, T tolerance){
    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/gauss_seidel.txt");
    std::vector<T> x0 = x;
    std::vector<T> xi(x.size());
    std::vector<T> r = A.multiply(x0)-b;
    int n = 0;
    while(mod(r) > tolerance){
        for(int i = 0 ; i < x.size(); i++){
            xi[i] = b[i];
            for(int j = i + 1; j < x.size(); j++ ){
                xi[i] -= A(i,j) * x0[j];
            }
            for (int j = 0; j < i; j++){
                xi[i] -= A(i,j) * xi[j];
            }
        xi[i] = xi[i]/A(i,i);
        }
        x0 = xi;
        r = A.multiply(xi)-b;
        file << mod(r) << " " << n << std::endl;
        n++;
    }
    return xi;
}

#endif //SLAE__GAUSS_SEIDEL_HPP
