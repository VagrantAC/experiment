cmake_minimum_required(VERSION 3.24)
project(main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(nullptr nullptr.cc)
add_executable(constexpr constexpr.cc)
add_executable(variable_and_init variable_and_init.cc)
add_executable(structured_bind structured_bind.cc)
