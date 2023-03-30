cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(PROJECT_NAME algorithm-cpp)

project(algorithm-cpp CXX)

add_subdirectory(src/structure)
add_subdirectory(src/algorithm)

enable_testing()
