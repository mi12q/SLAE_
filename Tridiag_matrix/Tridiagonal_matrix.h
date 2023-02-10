//
// Created by Milica on 9.2.2023..
//

#ifndef SLAE_TRIDIAGONAL_MATRIX_H
#define SLAE_TRIDIAGONAL_MATRIX_H

#include <iostream>
#include <utility>
#include <vector>
#include <array>

struct elements{
    double a; //lower diagonal element
    double b; //main diagonal element
    double c; //upper diagonal element
};

class Tridiagonal_matrix{
private:
    std::vector<elements> M;
public:
    explicit Tridiagonal_matrix(std::vector<elements>& v);
    ~Tridiagonal_matrix()= default;
    std::array<double, 3> &operator[](unsigned long long int i);
    unsigned long long int size();
};

#endif //SLAE_TRIDIAGONAL_MATRIX_H
