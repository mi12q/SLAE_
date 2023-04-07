cmake_minimum_required(VERSION 3.23)
project(SLAE_)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE src *.hpp *.h *.cpp)
add_library(SLAE_ INTERFACE ${src} iteration_methods/MPI_chebyshev.hpp iteration_methods/SOR.hpp iteration_methods/SSOR.hpp iteration_methods/Gradient_descent.hpp iteration_methods/Conjugate_gradient.hpp)