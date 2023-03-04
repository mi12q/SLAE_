#include <iostream>
#include "../src/Dense_matrix.hpp"
#include "gtest/gtest.h"


TEST(dense_test1, _3x3_matrix){
    std::vector<double> v = {1,2,3,2,2,4,5,6,7};
    std::vector<double> c = {9,7,5};
    std::vector<double> solution = {38,52,122};
    Dense_matrix M(v,3);
    std::vector<double> prod = M*c;
    for (int i = 0; i < M.get_length(); i++) {
        for (int j = 0; j < M.get_length(); j++) {
            EXPECT_TRUE(M(i, j) == v[i*M.get_length()+j]);
        }
    }
    for (int i = 0; i < c.size(); i++){
        ASSERT_NEAR(prod[i], solution[i], 0.01);
    }
}

TEST(dense_test2, _4x4_matrix){
    std::vector<double> v = {2,3,-4,4,11,8,7,7,2,5,9,-3,8,9,8,3};
    std::vector<double> c = {3,7,5,6};
    std::vector<double> solution = {31,166,68,145};
    Dense_matrix M(v,4);
    std::vector<double> prod = M*c;
    for (int i = 0; i < M.get_length(); i++) {
        for (int j = 0; j < M.get_length(); j++) {
            EXPECT_TRUE(M(i, j) == v[i*M.get_length()+j]);
        }
    }
    for (int i = 0; i < c.size(); i++){
        ASSERT_NEAR(prod[i], solution[i], 0.01);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
