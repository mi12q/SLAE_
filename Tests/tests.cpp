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
for (int i = 0; i < x.size(); i++){
    ASSERT_NEAR(x[i], solution[i], 0.01);
}

}
TEST(test2, _4x4_matrix){
    std::vector<elements> v = {{0,7,3},{1,9,10},{2,4,4},{4,3,0}};
    std::vector<double> solution = {0.77, -1.47, 1.54, 0.94};
    std::vector<double> f = {1, 3, 7, 9};
    Tridiagonal_matrix matrix(v);
    std::vector<double> x = solve(matrix,f);
    for (int i = 0; i < x.size(); i++){
        ASSERT_NEAR(x[i], solution[i], 0.01);
    }

}

TEST(test3, _6x6_matrix){
    std::vector<elements> v = {{0,10,3},{1,9,10},{2,5,7},{6,3,1}, {7,12,9},{3,5,0}};
    std::vector<double> solution = {12.4, 3.3, -0.81, 0.63, 11.96, -6.77};
    std::vector<double> f = {134, 34, 7, 9, 87, 2};
    Tridiagonal_matrix matrix(v);
    std::vector<double> x = solve(matrix,f);
    for (int i = 0; i < x.size(); i++){
        ASSERT_NEAR(x[i], solution[i], 0.01);
    }

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}