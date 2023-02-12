cmake_minimum_required(VERSION 3.23)
project(SLAE_)

set(CMAKE_CXX_STANDARD 17)

add_executable(SLAE_ Tridiag_matrix/Tridiagonal_matrix.cpp Tridiag_matrix/Tridiagonal_matrix.h Solve/solve.hpp Tests/tests.cpp)


enable_testing()
#add_subdirectory(googletest)
target_link_libraries(SLAE_ gtest gmock pthread)
target_link_libraries(SLAE_ gtest_main gmock_main)

add_subdirectory(Tests)
