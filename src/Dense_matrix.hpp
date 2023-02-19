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
    const std::vector<T>& get_elements() const {return M;}
    const std::vector<T> vector_mull(const std::vector<T> &x) const{
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
            for (int i = 0; i < (A.M).size(); i++)
                M[i] += (A.M)[i];
        }
    }
    const void operator - (const Dense_matrix &A) {
        if (M.size() == (A.get_elements()).size()) {
            for (int i = 0; i < (A.M).size(); i++)
                M[i] -= (A.M)[i];
        }
    }

};

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v){
    for(int i = 0; i < v.size(); i++){
        os << v[i] << " ";
    }
    return os;
}

template<typename T>
std::vector<T> operator + (const std::vector<T>& x, const std::vector<T>& y){
    std::vector<T> res(x.size());
    for(int i = 0; i < x.size(); i++){
        res[i] = x[i] + y[i];
    }
    return res;
}

template<typename T>
std::vector<T> operator - (const std::vector<T>& x, const std::vector<T>& y){
    std::vector<T> res(x.size());
    for(int i = 0; i < x.size(); i++){
        res[i] = x[i] - y[i];
    }
    return res;
}

template<typename T>
std::vector<T> operator * (const std::vector<T>& x, const std::vector<T>& y){
    std::vector<T> res(x.size());
    for(int i = 0; i < x.size(); i++){
        res[i] = x[i]*y[i];
    }
    return res;
}

template<typename T, typename Scalar>
std::vector<T> operator * (const std::vector<T>&x, Scalar num){
    std::vector<T> res(x.size());
    for(int i = 0; i < x.size(); i++){
        res[i] = x[i]*num;
    }
    return res;
}

template<typename T, typename Scalar>
std::vector<T> operator * (Scalar num, const std::vector<T>&x){
    std::vector<T> res(x.size());
    for(int i = 0; i < x.size(); i++){
        res[i] = x[i]*num;
    }
    return res;
}


#endif //SLAE__DENSE_MATRIX_HPP
