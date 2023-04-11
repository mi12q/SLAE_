#include <iostream>
#include "../../src/iteration_methods/MPI.hpp"
#include "../../src/iteration_methods/MPI_chebyshev.hpp"
#include "../../src/iteration_methods/SOR.hpp"
#include "../../src/iteration_methods/SSOR.hpp"
#include "../../src/iteration_methods/Gradient_descent.hpp"
#include "../../src/iteration_methods/Conjugate_gradient.hpp"
#include "gtest/gtest.h"
using namespace std::chrono;


TEST(zad_1, _289x289_matrix) {
    std::map<std::pair<int, int>, double> v;
    std::vector<double> b(289,4);
    std::vector<double> x (289,0);
    int L = 17;

    for (int i = 0; i < 289; i++) {
        for (int j = 0; j < 289; j++) {
            v[{i,j}] = 0;
            if (i == j) {
                v[{i, j}]  = 76.0;
            }
            if (j == i + 1 || i == j + 1) {
                v[{i, j}] = 16.0;
            }
            if (j == i + L || i == j + L) {
                v[{i, j}] = 16.0;
            }

        }
    }
    Matrix M(v);
    double lambda_min = 2*(38-16*2*cos(M_PI/(L+1)));
    double lambda_max = 2*(38+16*2*cos(M_PI/(L+1)));
    double tau = 1/lambda_max;
    double tau2 = 2/(lambda_min+lambda_max);
    double tolerance = pow(10,-13);
    std::cout << MPI(M, b, x, tolerance, tau) << std::endl; //Градиентный спуск с tau = 1 / λmax;
    std::cout << MPI(M, b, x, tolerance, tau2) << std::endl; //Градиентный спуск с оптимальным параметром;
    std::cout << chebyshev_mpi(M, b, x, tolerance, 8, lambda_min, lambda_max).first << std::endl; //Градиентный спуск с ускорением Чебышева
    std::cout << SSOR(M, b, x, tolerance,1.2, 0.05) << std::endl;//Симметризирований метод верхней релаксации

    std::ofstream file;
    file.open("/home/milica/CLionProjects/SLAE_/Tests/KR/time.txt");
    for (auto i = 0; i < 2000; i++){
        lambda_max += 1;
        auto start = high_resolution_clock::now();
        chebyshev_mpi(M, b, x, tolerance, 8, lambda_min, lambda_max);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        file << lambda_max-lambda_min << " "
        << duration.count()<< std::endl;
    }
    file.close();
}


TEST(zad_2, _4x4_matrix){
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
    double lambda_min = 19;
    double lambda_max = 28.5;
    double tau = 0.9 * 2 /lambda_max;
    double opt_tau = 2/(lambda_min+lambda_max);
    double tolerance = pow(10,-13);
    std::vector<double> result1 = MPI(M, b, x, tolerance, tau);
    std::cout << "MPI: " << result1 << std::endl;
    std::vector<double> result2 = MPI(M, b, x, tolerance, opt_tau);
    std::cout << "Optimal tau MPI: " << result2 << std::endl;
    std::vector<double> result3 = Gradient_descent(M, b, x, tolerance);
    std::cout << "Gradient descent: " << result3 << std::endl;
    std::vector<double> result4 = chebyshev_mpi(M, b, x, tolerance, 8, lambda_min, lambda_max).first;
    std::cout << "Chebyshev MPI: " << result4 << std::endl;
    std::vector<double> result5 = Conjugate_gradient(M, b, x, tolerance);
    std::cout << "CG: " << result5 << std::endl;

}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}