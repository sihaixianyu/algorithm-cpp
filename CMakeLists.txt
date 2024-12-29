cmake_minimum_required(VERSION 3.30)
project(algorithm-cpp CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-g)
add_compile_options(-O0)
add_compile_options(-Werror)

add_subdirectory(src/algorithm)
add_subdirectory(src/structure)
add_subdirectory(src/leetcode)
