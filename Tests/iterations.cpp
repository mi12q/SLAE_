#include <iostream>
#include "../src/simple_iteration.hpp"
#include "gtest/gtest.h"

TEST(simple_iteration, _3x3_matrix){
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
    std::vector<double> b = {1,2,3};
    std::vector<double> x = {5,7,9};
    for(int i = 0; i< 3; i++){
        ASSERT_NEAR(simple_iteration(M, b, x, 0.01 , 0.2)[i], 0.0, 0.01);
    }

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}