#ifndef SLAE__CSR_MATRIX_HPP
#define SLAE_CSR_MATRIX_HPP

#include <iostream>
#include <utility>
#include <map>
#include <vector>

template<typename T>
class Matrix{
private:
    std::map<std::pair<int, int>, T> M;
public:
    Matrix(const std::map<std::pair<int, int>,T> &v){
        this->M = v;
    };
    ~Matrix() = default;
    T operator()(int i, int j) {
        return M[{i,j}];
    }

};
#endif //SLAE__CSR_MATRIX_HPP
