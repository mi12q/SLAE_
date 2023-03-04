#include <iostream>
#include "../src/CSR_matrix.hpp"
#include "../src/Dense_matrix.hpp"

#ifndef SLAE__PROSTAYA_HPP
#define SLAE__PROSTAYA_HPP


template <typename T>
std::vector<T> simple_iteration(const Matrix<T> &A, const std::vector<T> &b, std::vector<T> &x, T tolerance, T tau){
    std::vector<T> r;
    while((A.multiply(x)-b).size() > tolerance){
        x = x - tau*(A.multiply(x) - b);
    }
    r = A.multiply(x) - b;
    return r;
}


#endif //SLAE__PROSTAYA_HPP
