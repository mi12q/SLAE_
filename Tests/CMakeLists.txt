cmake_minimum_required(VERSION 3.5)

add_subdirectory(googletest)

add_executable(tests tests.cpp)
target_link_libraries(tests SLAE_ gtest gtest_main)

add_executable(CSR_tests CSR_tests.cpp)
target_link_libraries(CSR_tests SLAE_ gtest gtest_main)