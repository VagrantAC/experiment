cmake_minimum_required(VERSION 3.24)
project(main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(nullptr nullptr.cc)
add_executable(constexpr constexpr.cc)
