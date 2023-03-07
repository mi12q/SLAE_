#include <iostream>
#include "../CSR_matrix.hpp"
#include "../Dense_matrix.hpp"
#include <fstream>

#ifndef SLAE__SIMPLE_ITERATION_HPP
#define SLAE__SIMPLE_ITERATION_HPP

template <typename T>
std::vector<T> fixed_point_iteration(const Matrix<T> &A, const std::vector<T> &b,const std::vector<T> &x, T tolerance, T tau){
    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/fixed_point.txt");
    std::vector<T> x1 = x;
    std::vector<T> r = A.multiply(x1) - b;
    int n = 1;
    while(mod(r) > tolerance){
        x1 = x1 - tau*(A.multiply(x1) - b);
        r = A.multiply(x1) - b;
        file << mod(r) << " " << n << std::endl;
        n++;
    }
    file.close();
    return x1;
}


#endif //SLAE__SIMPLE_ITERATION_HPP
