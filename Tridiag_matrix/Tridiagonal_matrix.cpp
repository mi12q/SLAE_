//
// Created by Milica on 9.2.2023..
//

#include "Tridiagonal_matrix.h"

std::array<double, 3> &Tridiagonal_matrix::operator[](unsigned long long int i) {
    static std::array<double, 3> row{};
    row[0] = M[i].a;
    row[1] = M[i].b;
    row[2] = M[i].c;

    return row;
}

Tridiagonal_matrix::Tridiagonal_matrix(std::vector<elements> &v) {
    this->M = v;
}

unsigned long long int Tridiagonal_matrix::size() {
    return M.size();
}
