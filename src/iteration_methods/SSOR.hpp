#ifndef SLAE__SSOR_HPP
#define SLAE__SSOR_HPP

#include <iostream>
#include <fstream>
#include "../CSR_matrix.hpp"
#include "../Dense_matrix.hpp"

template <typename T>
std::vector<T> SOR_iteration(const Matrix<T> &A, const std::vector<T> &b, const std::vector <T> &x,T w){
    std::vector<T> x0 = x;
    T t;
    T diag_el;

    for(int i = 0; i < x.size(); i++){ //0.5
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

    for(int i = x.size()-1; i-- > 0; i){ //1
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

    return x0;
}


template <typename T>
std::vector<T> SSOR(const Matrix<T> &A, const std::vector<T> &b, const std::vector <T> &x, T tolerance, T w){
    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/SSOR.txt");
    std::vector<T> x0 = x;
    std::vector<T> r = A.multiply(x0)-b;
    int n = 0;
    while(mod(r) > tolerance){
        x0 = SOR_iteration(A,b,x0,w);
        r = A.multiply(x0)-b;
        file << mod(r) << " " << n << std::endl;
        n++;
    }
    return x0;
}

template <typename T>
std::vector<T> SSOR_chebyshev(const Matrix<T> &A, const std::vector<T> &b, const std::vector <T> &x, T tolerance, T w, T ro){
    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/SSOR_chebyshev.txt");
    std::vector<T> y0 = x;
    std::vector<T> y1 = SOR_iteration(A,b,y0,w);
    std::vector<T> t = SOR_iteration(A,b,y1,w);
    T myu_0 = 1;
    T myu_1 = 1/ro;
    std::vector<T> r = A.multiply(y1)-b;
    int n = 0;
    while(mod(r) > tolerance){
        y0 = (2*myu_1/ro)*t - myu_0*y0;
        myu_0 = (2/ro)*myu_1-myu_0;
        y0 = y0/myu_0;
        t = SOR_iteration(A,b,y0,w);
        y1 = y0;
        std::swap(myu_0,myu_1);
        r = A.multiply(y1)-b;
        file << mod(r) << " " << n << std::endl;
        n++;
    }
    return y1;
}

#endif //SLAE__SSOR_HPP
