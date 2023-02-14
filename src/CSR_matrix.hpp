#ifndef SLAE__CSR_MATRIX_HPP
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
        int m = (v.end()->first).first;
        int n = (v.end()->first).second;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
            if (v[{i,j}] != 0) {
                values.push_back(v[{i,j}]);
                columns.push_back(j);
                }
                non_zero++;
            }
            rows.push_back(non_zero);
        }
    };
    ~Matrix() = default;

};
#endif //SLAE__CSR_MATRIX_HPP
