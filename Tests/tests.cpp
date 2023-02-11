//
// Created by milica on 11.02.23.
//

#include <iostream>
#include "/home/milica/CLionProjects/SLAE3/Solve/solve.hpp"
#include "gtest/gtest.h"
using namespace std;

TEST(test1, _4x4_matrix){
std::vector<elements> v = {{0,2,3},{6,3,9},{2,5,2},{4,3,0}};
std::vector<double> solution = {3.0, 5.0, 4.0, 2.0};
std::vector<double> f = {21.0, 69.0, 34.0, 22.0};
Tridiagonal_matrix matrix(v);
std::vector<double> x = solve(matrix,f);
for (int i = 1; i < x.size(); i++){
    ASSERT_NEAR(x[i], solution[i], 0.1);
}

}

TEST(test2, _4x4_matrix){
    std::vector<elements> v = {{0,7,3},{1,9,10},{2,4,4},{4,3,0}};
    std::vector<double> solution = {0.77, -1.47, 1.54, 0.94};
    std::vector<double> f = {1, 3, 7, 9};
    Tridiagonal_matrix matrix(v);
    std::vector<double> x = solve(matrix,f);
    for (int i = 1; i < x.size(); i++){
        ASSERT_NEAR(x[i], solution[i], 0.1);
    }

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}