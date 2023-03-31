#ifndef SLAE__MPI_CHEBYSHEV_HPP
#define SLAE__MPI_CHEBYSHEV_HPP

#include <vector>
#include "../CSR_matrix.hpp"
#include "../Dense_matrix.hpp"
#include <fstream>

template <typename T>
std::vector<T> chebyshev_mpi(const Matrix<T> &A, const std::vector<T> &b,const std::vector<T> &x0, T tolerance, unsigned int roots,
                             double lambda_min, double lambda_max){
    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/src/iteration_methods/MPI_chebyshev.txt");
    int n = pow(2,roots);
    std::vector<int> root_num(n,0);
    root_num[pow(2,roots-1)] = 1;
    for(int i = 2; i <= roots; i++){
        int k = pow(2,roots-i);
        for(int j = 0; j < n; j+= 2*k){
            root_num[j+k] = pow(2,i) - root_num[j] - 1;
        }
    }
    double cos_a = cos(M_PI/n);
    double sin_a = sin(M_PI/n);
    double sin_b = sin(M_PI/(2*n));
    std::vector<T> x(n,0);
    x[0] = sin(M_PI/(2*n));

    for(int i = 1; i < n; i++){
        x[i] = x[i-1]*cos_a - sin_b*sin_a;
        sin_b = x[i-1]*cos_a + sin_b*sin_a;
        x[i-1] = x[i-1]*(lambda_max-lambda_min)/2 + (lambda_max+lambda_min)/2;
    }
    x[n-1] = x[n-1]*(lambda_max-lambda_min)/2 + (lambda_max+lambda_min)/2;

    std::vector<T> x1 = x0;
    std::vector<T> r = A.multiply(x1) - b;
    int it = 0;
    while(mod(r) > tolerance){
        for(int i = 0; i < n; i++) {
            x1 = x1 - (A.multiply(x1) - b) * (1 / x[root_num[i]]);
            r = A.multiply(x1) - b;
            file << mod(r) << " " << it << std::endl;
            it++;
        }
    }
    file.close();
    return x1;
}



#endif //SLAE__MPI_CHEBYSHEV_HPP
