//
// Created by milica on 18.02.23.
//

#ifndef SLAE__DENSE_MATRIX_HPP
#define SLAE__DENSE_MATRIX_HPP

#include <vector>

template<typename T>
class Dense_matrix{
private:
    std::vector<T> M{};
    int row_length = 0;
public:
    Dense_matrix(const std::vector<T> &v, int length){
        this->M = v;
        this->row_length = length;
    }
    ~Dense_matrix() = default;
    const T operator() (int i, int j) const{
        return M[i*row_length + j];
    }
    std::vector<T> vector_mull(const std::vector<T> &x) {
        std::vector<T> res(x.size());
        for (int i = 0; i < x.size(); i++) {
            for (int j = 0; j < x.size(); j++) {
                res[i] += M[i * row_length + j] * x.at(j);
            }
        }
        return res;
    }
    const void operator + (const Dense_matrix &A) {
        if (M.size() == (A.M).size()) {
            for (int i = 0; i < (A.M).size(); i ++)
                M[i] += A.M[i];

        }
    }
    const void operator - (const Dense_matrix &A) {
        if (M.size() == (A.M).size()) {
            for (int i = 0; i < (A.M).size(); i ++)
                M[i] -= A.M[i];

        }
    }

};


#endif //SLAE__DENSE_MATRIX_HPP
