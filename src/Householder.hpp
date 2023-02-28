#ifndef SLAE__HOUSEHOLDER_HPP
#define SLAE__HOUSEHOLDER_HPP

#include "../src/Dense_matrix.hpp"
#include <iostream>

template<typename T>
Dense_matrix<T> Householder(const Dense_matrix<T> &M) {
    Dense_matrix<T> A = M;
    int size = A.get_elements().size() / A.get_length();
    std::vector<T> e(size, 0);
    e[0] = 1;
    std::vector<std::vector<T>> vectors = {};

    std::vector<T> v = A.get_column(0) + sign(A.get_column(0)) * mod(A.get_column(0)) * e;
    vectors.push_back(v);
    std::vector<T> prod = A.get_column(0) - 2 * v * ((v * A.get_column(0)) / pow(mod(v), 2));
    A.swap_element(0, 0, prod[0]);
    for (int i = 1; i < A.get_length(); i++) {
        A.swap_element(i, 0, 0);
    }
    for (int j = 1; j < A.get_length(); j++) {
        std::vector<T> prod = A.get_column(j) - 2 * v * ((v * A.get_column(j)) / pow(mod(v), 2));
        for (int i = 0; i < size; i++) {
            A.swap_element(i, j, prod[i]);
        }
    }

    //pravilno

    for (int k = 1; k < A.get_length(); k++) {
        size --;
        std::vector<T> e(size, 0);
        e[0] = 1;
        std::vector<T> x;
        std::vector<T> a  = A.get_column(k);
        x = std::vector<T>(a.begin() + k, a.end());
        std::vector<T> v = x + sign(x) * mod(x) * e;
        vectors.push_back(v);
        std::vector<T> prod = x - 2 * v * ((v * x) / pow(mod(v), 2));
        A.swap_element(k, k, prod[0]);
        for (int i = 1 + k; i < size+1; i++) {
            A.swap_element(i, k, 0);
        }

        for (int j = 1 + k; j < A.get_length(); j++) {
            std::vector<T> a  = A.get_column(j);
            x = std::vector<T>(a.begin() + k, a.end());
            std::vector<T> prod = x- 2 * v * ((v * x) / pow(mod(v), 2));
            for (int i = 0; i < size; i++) {
                A.swap_element(i + k, j, prod[i]);
            }

        }

        }
    return A;


}




#endif //SLAE__HOUSEHOLDER_HPP
