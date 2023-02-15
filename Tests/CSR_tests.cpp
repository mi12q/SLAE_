#include <iostream>
#include "../src/CSR_matrix.hpp"
#include "gtest/gtest.h"
using namespace std;

TEST(csr_test1, _3x3_matrix){
    std::map<std::pair<int, int>, double> v;
    v[{0, 0}] = 1;
    v[{0, 1}] = 2;
    v[{0, 2}] = 0;
    v[{1, 0}] = 0;
    v[{1, 1}] = 4;
    v[{1, 2}] = 0;
    v[{2, 0}] = 0;
    v[{2, 1}] = 2;
    v[{2, 2}] = 6;

    Matrix M(v);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_TRUE(M(i, j) == v.at({i,j}));
        }
    }
    std::vector<double> a = {2, 5, 7};
    std::vector<double> solution = {12, 20, 52};
    std::vector<double> res = M.multiply(a);
    for (int i = 0; i < a.size(); i++){
        ASSERT_NEAR(res[i], solution[i], 0.01);
    }

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
