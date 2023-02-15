#include <iostream>
#include "../src/CSR_matrix.hpp"
#include "gtest/gtest.h"

using namespace std;

int main() {


    std::map<std::pair<int, int>, double> v;
    v[{0,0}] = 1;
    v[{0,1}] = 2;
    v[{0,2}] = 0;
    v[{1,0}] = 0;
    v[{1,1}] = 4;
    v[{1,2}] = 0;
    v[{2,0}] = 0;
    v[{2,1}] = 2;
    v[{2,2}] = 6;
    //cout << ((--v.end())->first).second;

    Matrix M(v);

//    cout << endl;
//    cout << M(0,0) << M(0,1) << M(0,2) << endl;
//    cout << M(1,0) << M(1,1) << M(1,2) << endl;
//    cout << M(2,0) << M(2,1) << M(2,2) << endl;

    std::vector<double> a = {2,5,7};
    std::vector<double> res = M.multiply(a);
    for(auto i: res){
        cout << i << endl;
    }
    return 0;
}