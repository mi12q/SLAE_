#include <iostream>
#include "../src/CSR_matrix.hpp"
//#include "gtest/gtest.h"

using namespace std;

int main() {
    std::map<std::pair<int, int>, double> v;
    v[{0,0}] = 1;
    v[{0,1}] = 2;
    v[{0,2}] = 6;
    v[{1,0}] = 9;
    v[{1,1}] = 0;
    v[{1,2}] = 7;
    v[{2,0}] = 1.5;
    v[{2,1}] = 1.6;
    v[{2,2}] = 1.7;

    Matrix M(v);

    cout << M(2,2);

    return 0;
}