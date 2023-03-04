//
// Created by milica on 28.02.23.
//
#include "gtest/gtest.h"
#include "../src/Dense_matrix.hpp"
#include "../src/Householder.hpp"
#include <cstdlib>
#include <iostream>


TEST(qr_test1, _3x3_matrix){
    std::vector<double> b = {2,-2,18,2,1,0,1,2,0};
    Dense_matrix M(b,3);
    Dense_matrix<double> Q =  Householder(M).first;
    Dense_matrix<double> R = Householder(M).second;

    EXPECT_TRUE(unitary(Q));
    EXPECT_TRUE(upper_diagonal(R));
    Dense_matrix<double> A = Q*R;
    EXPECT_TRUE(A == M);

}

TEST(qr_test2, _3x3_matrix){
    std::vector<double> b = {1,2,4,0,0,5,0,3,6};
    Dense_matrix M(b,3);
    Dense_matrix<double> Q =  Householder(M).first;
    Dense_matrix<double> R = Householder(M).second;

    EXPECT_TRUE(unitary(Q));
    EXPECT_TRUE(upper_diagonal(R));
    Dense_matrix<double> A = Q*R;
    EXPECT_TRUE(A == M);

}

TEST(qr_test3, _10x10_matrix){
    std::vector<double> b(16);
    std::generate(b.begin(), b.end(), []() {
        return rand() % 5;
    });
    Dense_matrix M(b,4);
    Dense_matrix<double> Q =  Householder(M).first;
    Dense_matrix<double> R = Householder(M).second;

    EXPECT_TRUE(unitary(Q));
    EXPECT_TRUE(upper_diagonal(R));
    Dense_matrix<double> A = Q*R;
    // std::cout << A.get_elements() << std::endl;
    //std::cout << M.get_elements();
    std::cout << R.get_column(0) << std::endl;
    std::cout << R.get_column(1) << std::endl;
    std::cout << R.get_column(2) << std::endl;
    std::cout << R.get_column(3) << std::endl;
    EXPECT_TRUE(A == M);

}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
