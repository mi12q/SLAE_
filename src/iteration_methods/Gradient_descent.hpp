#ifndef SLAE__GRADIENT_DESCENT_HPP
#define SLAE__GRADIENT_DESCENT_HPP
#include <iostream>
#include "../CSR_matrix.hpp"
#include "../Dense_matrix.hpp"
#include <fstream>

template <typename T>
std::vector<T> Gradient_descent(const Matrix<T> &A, const std::vector<T> &b,const std::vector<T> &x, T tolerance){
    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/Gradient_descent.txt");
    T alpha;
    std::vector<T> x1 = x;
    std::vector<T> r = A.multiply(x1) - b;
    int n = 0;
    while(mod(r) > tolerance){
        alpha = r*r/ (r*A.multiply(r));
        x1 = x1 - alpha*(A.multiply(x1) - b);
        r = A.multiply(x1) - b;
        file << x1 <<  std::endl;
        n++;
    }
    file.close();
        return x1;
}

#endif //SLAE__GRADIENT_DESCENT_HPP
