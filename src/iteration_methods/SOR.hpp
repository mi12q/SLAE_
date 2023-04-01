#ifndef SLAE__SOR_HPP
#define SLAE__SOR_HPP

#include <iostream>
#include <fstream>
#include "../CSR_matrix.hpp"
#include "../Dense_matrix.hpp"

template <typename T>
std::vector<T> SOR(const Matrix<T> &A, const std::vector<T> &b, const std::vector <T> &x, T tolerance, T w){
    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/SOR.txt");
    std::vector<T> x0 = x;
    T t;
    T diag_el;
    std::vector<T> r = A.multiply(x)-b;
    int n = 0;
    while(mod(r) > tolerance){
        for(int i = 0 ; i < x.size(); i++){
            t = x0[i];
            x0[i] = b[i]*w;
            for(int j = A.get_rows()[i]; j < A.get_rows()[i+1]; j++){
                if (A.get_columns()[j] == i){
                    diag_el = A(i,i);
                    continue;
                }
                x0[i] -= A.get_values()[j]*x0[A.get_columns()[j]]*w;
            }
            x0[i] /= diag_el;
            x0[i] += (1-w)*t;
        }
        r = A.multiply(x0)-b;
        file << mod(r) << " " << n << std::endl;
        n++;
    }
    return x0;
}












#endif //SLAE__SOR_HPP
