#include <iostream>
#include "../src/iteration_methods/fixed_point_iteration.hpp"
#include "../src/iteration_methods/Jacobi.hpp"
#include "../src/iteration_methods/gauss_seidel.hpp"
#include "../src/iteration_methods/MPI_chebyshev.hpp"
#include "../src/iteration_methods/SOR.hpp"
#include "gtest/gtest.h"

TEST(Fixed_point_iteration, _3x3_matrix){
    std::map<std::pair<int, int>, double> v;
    v[{0, 0}] = 12;
    v[{0, 1}] = 17;
    v[{0, 2}] = 3;
    v[{1, 0}] = 17;
    v[{1, 1}] = 15825;
    v[{1, 2}] = 28;
    v[{2, 0}] = 3;
    v[{2, 1}] = 28;
    v[{2, 2}] = 138;

    Matrix M(v);
    std::vector<double> b = {1,2,3};
    std::vector<double> x = {1,1,1};
    double tolerance = pow(10,-12);
    std::vector<double> solution = {0.0804084117,0.0000194982, 0.0115891967};
    std::vector<double> result = fixed_point_iteration(M, b, x, tolerance, 0.0001);
    for (int i = 0; i < result.size(); i++){
        ASSERT_NEAR(result[i], solution[i], 0.01);
    }
}

TEST(Jacobi, _3x3_matrix){
    std::map<std::pair<int, int>, double> v;
    v[{0, 0}] = 12;
    v[{0, 1}] = 17;
    v[{0, 2}] = 3;
    v[{1, 0}] = 17;
    v[{1, 1}] = 15825;
    v[{1, 2}] = 28;
    v[{2, 0}] = 3;
    v[{2, 1}] = 28;
    v[{2, 2}] = 238;

    Matrix M(v);
    std::vector<double> b = {1,2,3};
    std::vector<double> x = {1,1,1};
    double tolerance = pow(10,-12);
    std::vector<double> solution = {0.0804084117,0.0000194982, 0.0115891967};
    std::vector<double> result = Jacobi(M, b, x, tolerance, 3, 3);;
    for (int i = 0; i < result.size(); i++){
        ASSERT_NEAR(result[i], solution[i], 0.01);
    }

}

TEST(Gauss_Seidel, _3x3_matrix){
    std::map<std::pair<int, int>, double> v;
    v[{0, 0}] = 12;
    v[{0, 1}] = 17;
    v[{0, 2}] = 3;
    v[{1, 0}] = 17;
    v[{1, 1}] = 15825;
    v[{1, 2}] = 28;
    v[{2, 0}] = 3;
    v[{2, 1}] = 28;
    v[{2, 2}] = 238;

    Matrix M(v);
    std::vector<double> b = {1,2,3};
    std::vector<double> x = {1,1,1};
    double tolerance = pow(10,-12);
    std::vector<double> solution = {0.0804084117,0.0000194982, 0.0115891967};
    std::vector<double> result = Gauss_seidel(M, b, x, tolerance);
    for (int i = 0; i < result.size(); i++){
        ASSERT_NEAR(result[i], solution[i], 0.01);
    }

}

TEST(MPI_chebyshev, _3x3_matrix){
    std::map<std::pair<int, int>, double> v;
    v[{0, 0}] = 12;
    v[{0, 1}] = 17;
    v[{0, 2}] = 3;
    v[{1, 0}] = 17;
    v[{1, 1}] = 15825;
    v[{1, 2}] = 28;
    v[{2, 0}] = 3;
    v[{2, 1}] = 28;
    v[{2, 2}] = 238;

    Matrix M(v);
    std::vector<double> b = {1,2,3};
    std::vector<double> x = {1,1,1};
    double tolerance = pow(10,-12);
    std::vector<double> solution = {0.0804084117,0.0000194982, 0.0115891967};
    std::vector<double> result = chebyshev_mpi(M, b, x, tolerance, solution.size(), 11.943, 15825.069);
    for (int i = 0; i < result.size(); i++){
        ASSERT_NEAR(result[i], solution[i], 0.01);
    }

}

TEST(SOR, _3x3_matrix){
    std::map<std::pair<int, int>, double> v;
    v[{0, 0}] = 12;
    v[{0, 1}] = 17;
    v[{0, 2}] = 3;
    v[{1, 0}] = 17;
    v[{1, 1}] = 15825;
    v[{1, 2}] = 28;
    v[{2, 0}] = 3;
    v[{2, 1}] = 28;
    v[{2, 2}] = 238;

    Matrix M(v);
    std::vector<double> b = {1,2,3};
    std::vector<double> x = {1,1,1};
    double tolerance = pow(10,-12);
    std::vector<double> solution = {0.0804084117,0.0000194982, 0.0115891967};
    std::vector<double> result = SOR(M, b, x, tolerance,1.019055);
    for (int i = 0; i < result.size(); i++){
        ASSERT_NEAR(result[i], solution[i], 0.01);
    }

}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}