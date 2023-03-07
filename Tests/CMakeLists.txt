cmake_minimum_required(VERSION 3.5)

add_subdirectory(googletest)

add_executable(Tridiagonal_tests Tridiagonal_tests.cpp)
target_link_libraries(Tridiagonal_tests SLAE_ gtest gtest_main)

add_executable(CSR_tests CSR_tests.cpp Iteration_methods_tests.cpp)
target_link_libraries(CSR_tests SLAE_ gtest gtest_main)

add_executable(Dense_matrix_tests Dense_matrix_tests.cpp)
target_link_libraries(Dense_matrix_tests SLAE_ gtest gtest_main)

add_executable(Householder Householder.cpp)
target_link_libraries(Householder SLAE_ gtest gtest_main)

add_executable(Iteration_methods_tests Iteration_methods_tests.cpp)
target_link_libraries(Iteration_methods_tests SLAE_ gtest gtest_main)


