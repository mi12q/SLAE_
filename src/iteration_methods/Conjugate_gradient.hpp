#ifndef SLAE__CONJUGATE_GRADIENT_HPP
#define SLAE__CONJUGATE_GRADIENT_HPP

#include <iostream>
#include "../CSR_matrix.hpp"
#include "../Dense_matrix.hpp"
#include <fstream>

template <typename T>
std::vector<T> Conjugate_gradient(const Matrix<T> &A, const std::vector<T> &b,const std::vector<T> &x, T tolerance){
    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/Conjugate_gradient.txt");
    T alpha;
    T temp;
    std::vector<T> x1 = x;
    std::vector<T> r = A.multiply(x1) - b;
    std::vector<T> d = r;
    int n = 0;
    while(mod(r) > tolerance){
        for(int i = 0; i < x.size(); i++) {
            if(mod(r) != 0) {
                alpha = d * r / (d * A.multiply(d));
                temp = 1 / (d * r);
                x1 = x1 - alpha * d;
                r = r - alpha * (A.multiply(d));
                d = r + (r*r)*temp * d;
                file << mod(r) << " " << n << std::endl;
                n++;
            }
            else
                return x1;
        }
    }
    file.close();
        return x1;
}

#endif //SLAE__CONJUGATE_GRADIENT_HPP
