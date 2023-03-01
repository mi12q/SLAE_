#ifndef SLAE__HOUSEHOLDER_HPP
#define SLAE__HOUSEHOLDER_HPP

#include "../src/Dense_matrix.hpp"
#include <iostream>

template <typename T>
struct QR{
    Dense_matrix<T> Q;
    Dense_matrix<T> R;
};

template<typename T>
struct QR<T> Householder(const Dense_matrix<T> &M) {
    Dense_matrix<T> R = M;
    int size = R.get_elements().size() / R.get_length();
    std::vector<T> e(size, 0); // vector e1
    e[0] = 1;
    std::vector<T> q(R.get_elements().size(), 0);
    std::vector<T> v = R.get_column(0) + sign(R.get_column(0)) * mod(R.get_column(0)) * e;
    for (int i = 0; i < R.get_elements().size(); i++){
        for(int j = 0; j < R.get_length(); j++){
            if(i == j)
                q[i * R.get_length()+ j] = 1;
        }
    }
    q = q - 2 * transposed_prod(v)/row_column_prod(v);
    Dense_matrix<T> Q(q, R.get_length()); //calculating Q[0]

    std::vector<T> prod = R.get_column(0) - 2 * v * ((v * R.get_column(0)) / pow(mod(v), 2));
    R.swap_element(0, 0, prod[0]);
    for (int i = 1; i < R.get_length(); i++) {
        R.swap_element(i, 0, 0); //transforming the first column of R
    }
    for (int j = 1; j < R.get_length(); j++) {
        std::vector<T> prod = R.get_column(j) - 2 * v * ((v * R.get_column(j)) / pow(mod(v), 2));
        for (int i = 0; i < size; i++) {
            R.swap_element(i, j, prod[i]); //transforming rest of the columns
        }
    }
    
    for (int n = 1; n < R.get_length(); n++) { //repeating for other columns
        size--;
        std::vector<T> e(size, 0); //new vector e1
        e[0] = 1;
        std::vector<T> a = R.get_column(n);
        std::vector<T> x = std::vector<T>(a.begin() + n, a.end());
        std::vector<T> v = x + sign(x) * mod(x) * e;
        std::vector<T> prod = x - 2 * v * ((v * x) / pow(mod(v), 2));
        R.swap_element(n, n, prod[0]); //transforming n-th column
        for (int i = 1 + n; i < size + 1; i++) {
            R.swap_element(i, n, 0);
        }

        for (int j = 1 + n; j < R.get_length(); j++) { //transforming columns after n
            std::vector<T> a = R.get_column(j);
            std::vector<T> x = std::vector<T>(a.begin() + n, a.end());
            std::vector<T> prod = x - 2 * v * ((v * x) / pow(mod(v), 2));
            for (int i = 0; i < size; i++) {
                R.swap_element(i + n, j, prod[i]);
            }
        }
        for (int i = 0; i < R.get_length() ; i++) {
            a = Q.get_row(i);
            std::vector<T> x = std::vector<T>(a.begin()+n , a.end());
            for(int j = 0; j < size; j++){
                std::vector<T> prod = x - 2 * v * ((v * x) / pow(mod(v), 2));
                Q.swap_element(i,j + n,prod[j]);
            }
        }
    }
    QR result = {Q,R};
    return result;
}

#endif //SLAE__HOUSEHOLDER_HPP
