#include <iostream>
#include "../src/iteration_methods/MPI.hpp"
#include "../src/iteration_methods/Jacobi.hpp"
#include "../src/iteration_methods/gauss_seidel.hpp"
#include "../src/iteration_methods/MPI_chebyshev.hpp"
#include "../src/iteration_methods/SOR.hpp"
#include "../src/iteration_methods/SSOR.hpp"
#include "../src/iteration_methods/Gradient_descent.hpp"
#include "../src/iteration_methods/Conjugate_gradient.hpp"
#include "gtest/gtest.h"

TEST(zad_2, _3x3_matrix){
    std::map<std::pair<int, int>, double> v;
    v[{0, 0}] = 19;
    v[{0, 1}] = 0;
    v[{0, 2}] = 0;
    v[{0, 3}] = 0;
    v[{1, 0}] = 0;
    v[{1, 1}] = 22;
    v[{1, 2}] = 0;
    v[{1, 3}] = 0;
    v[{2, 0}] = 0;
    v[{2, 1}] = 0;
    v[{2, 2}] = 25;
    v[{2, 3}] = 0;
    v[{3, 0}] = 0;
    v[{3, 1}] = 0;
    v[{3, 2}] = 0;
    v[{3, 3}] = 28.5;


    Matrix M(v);
    std::vector<double> b = {6,6,6,6};
    std::vector<double> x = {0,0,0,0};
    double tau = 0.9 * 2 /28.5;
    double opt_tau = 2/(28.5+19);
    double tolerance = pow(10,-13);
    std::vector<double> result2 = MPI(M, b, x, tolerance, tau);
    std::cout << "MPI: " << result2 << std::endl;
    std::vector<double> result5 = MPI(M, b, x, tolerance, opt_tau);
    std::cout << "Optimal tau MPI: " << result5 << std::endl;
    std::vector<double> result1 = Gradient_descent(M, b, x, tolerance);
    std::cout << "Gradient descent: " << result1 << std::endl;
    std::vector<double> result3 = chebyshev_mpi(M, b, x, tolerance, b.size(), 19, 28.5);
    std::cout << "Chebyshev MPI: " << result3 << std::endl;
    std::vector<double> result4 = Conjugate_gradient(M, b, x, tolerance);
    std::cout << "CG: " << result4 << std::endl;

}

TEST(zad_1, _3x3_matrix) {
    std::map<std::pair<int, int>, double> v;
    std::vector<double> b(289,4);
    std::vector<double> x (289,0);

    for (int i = 0; i < 288; i++) {
        for (int j = 0; j < 288; j++) {
            v[{i,j}] = 0;
            if (i == j) {
                v[{i, j}]  = 72;
            }
            if (j == i + 1 || i == j + 1) {
                v[{i, j}] = 16.0;
            }
            if (j == i + 17 || i == j + 17) {
                v[{i, j}] = 16.0;
            }

        }
    }
    Matrix M(v);
    double tau = 1/72;
    double opt_tau = 2/(16+2*38.0);
    double tolerance = pow(10,-13);
    std::cout << MPI(M, b, x, tolerance, tau);
    std::cout << MPI(M, b, x, tolerance, opt_tau);
    //std::cout << chebyshev_mpi(M, b, x, tolerance, b.size(), 16, 72);
    //std::cout << "Gradient descent: " << result1 << std::endl;

    }



//


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}