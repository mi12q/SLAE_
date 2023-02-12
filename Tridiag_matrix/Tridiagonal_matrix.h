#ifndef SLAE_TRIDIAGONAL_MATRIX_H
#define SLAE_TRIDIAGONAL_MATRIX_H

#include <iostream>
#include <utility>
#include <vector>
#include <array>

template<typename T>
struct elements{
    T a; //lower diagonal element
    T b; //main diagonal element
    T c; //upper diagonal element
};

template<typename T>
class Tridiagonal_matrix{
private:
    std::vector<elements<T>> M;
public:
    explicit Tridiagonal_matrix(std::vector<elements<T>>& v);
    ~Tridiagonal_matrix()= default;
    T operator()(unsigned long long int i,unsigned long long int j);
    unsigned long long int size();
};



#endif //SLAE_TRIDIAGONAL_MATRIX_H
