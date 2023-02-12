#include "Tridiagonal_matrix.h"

template<typename T>
Tridiagonal_matrix<T>::Tridiagonal_matrix(std::vector<elements<T>> &v) {
    this->M = v;
}

template<typename T>
T Tridiagonal_matrix<T>::operator()(unsigned long long int i, unsigned long long int j) const {
    if(j == 0)
        return M[i].a;
    if(j==1)
        return M[i].b;
    if(j==2)
        return M[i].c;
}

template<typename T>
unsigned long long int Tridiagonal_matrix<T>::size() const {
    return M.size();
}
