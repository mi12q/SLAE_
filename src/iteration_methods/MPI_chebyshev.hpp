#ifndef SLAE__MPI_CHEBYSHEV_HPP
#define SLAE__MPI_CHEBYSHEV_HPP

#include <vector>
#include "../CSR_matrix.hpp"
#include "../Dense_matrix.hpp"
#include <fstream>
#include <bits/stdc++.h>

template <typename T>
std::pair<std::vector<T>, std::pair<double,std::size_t>> chebyshev_mpi(const Matrix<T> &A, const std::vector<T> &b,const std::vector<T> &x0, T tolerance, std::size_t roots,
                             double lambda_min, double lambda_max){

    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/MPI_chebyshev.txt");
    std::size_t n = pow(2,roots);
    std::vector<std::size_t > root_num(n,0);
    root_num[pow(2,roots-1)] = 1;
    for(std::size_t  i = 2; i <= roots; i++){
        std::size_t k = pow(2,roots-i);
        for(std::size_t  j = 0; j < n; j+= 2*k){
            root_num[j+k] = pow(2,i) - root_num[j] - 1;
        }
    }
    double cos_a = cos(M_PI/n);
    double sin_a = sin(M_PI/n);
    double sin_b = sin(M_PI/(2*n));
    std::vector<T> x(n,0);
    x[0] = sin(M_PI/(2*n));

    for(std::size_t  i = 1; i < n; i++){
        x[i] = x[i-1]*cos_a - sin_b*sin_a;
        sin_b = x[i-1]*cos_a + sin_b*sin_a;
        x[i-1] = x[i-1]*(lambda_max-lambda_min)/2 + (lambda_max+lambda_min)/2;
    }
    x[n-1] = x[n-1]*(lambda_max-lambda_min)/2 + (lambda_max+lambda_min)/2;

    std::vector<T> x1 = x0;
    std::vector<T> r = A.multiply(x1) - b;
    std::size_t  it = 0;
    while(mod(r) > tolerance){
        for(auto i = 0; i < root_num.size(); i++) {
            x1 = x1 - r * (1 / x[root_num[i]]);
            r = A.multiply(x1) - b;
            file << x1 << "\n";
            it++;
        }
    }
    return std::make_pair(x1, std::make_pair(mod(r),it));;
}



#endif //SLAE__MPI_CHEBYSHEV_HPP
