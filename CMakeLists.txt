cmake_minimum_required(VERSION 3.20)
project(algorithm-cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-g)
add_compile_options(-O0)

add_subdirectory(src/algorithm)
add_subdirectory(src/structure)
add_subdirectory(src/leetcode)
