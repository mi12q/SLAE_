#ifndef SLAE_CSR_MATRIX_HPP
#define SLAE_CSR_MATRIX_HPP

#include <iostream>
#include <utility>
#include <map>
#include <vector>

template<typename T>
class Matrix{
private:
    std::vector<T> values;
    std::vector<int> columns;
    std::vector<int> rows = {0};
public:
    Matrix(const std::map<std::pair<int, int>,T> &v){
        int non_zero = 0;
        for(int i = 0; i < ((--v.end())->first).first+1; i++){
            for(int j = 0; j < ((--v.end())->first).second+1; j++){
                if (v.at({i,j}) != 0) {
                    values.push_back(v.at({i,j}));
                    columns.push_back(j);
                    non_zero++;
                }
            }
            rows.push_back(non_zero);
        }
    }
    ~Matrix() = default;
    const std::vector<T>& get_values() const {return values;}
    const std::vector<int>& get_columns() const {return columns;}
    const std::vector<int>& get_rows() const {return rows;}
    const T operator() (int i, int j) const{
        for(int r = rows[i]; r < rows[i+1]; r++){
            if (columns[r] == j){
                return values[r];
            }
        }
        return 0;
    }
    std::vector<T> multiply(const std::vector<T> &x) const{
        std::vector<T> res(x.size(), 0);
        for (int i = 0; i < x.size(); i++) {
            for (int j = rows[i]; j < rows[i + 1]; j++)
                res[i] += values[j] * x[columns[j]];
        }
        return res;
    }
};

#endif //SLAE_CSR_MATRIX_HPP
