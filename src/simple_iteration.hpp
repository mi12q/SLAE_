#include <iostream>
#include "../src/CSR_matrix.hpp"
#include "../src/Dense_matrix.hpp"

#ifndef SLAE__SIMPLE_ITERATION_HPP
#define SLAE__SIMPLE_ITERATION_HPP


template <typename T>
std::vector<T> simple_iteration(const Matrix<T> &A, const std::vector<T> &b,const std::vector<T> &x, T tolerance, T tau){
    std::vector<T> r;
    std::vector<T> x1 = x;
    r = A.multiply(x) - b;
    while(mod(r) > tolerance){
        r = A.multiply(x1) - b;
        x1 = x1 - tau*r;
    }
    return x1;
}


#endif //SLAE__SIMPLE_ITERATION_HPP
