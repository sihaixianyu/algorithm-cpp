cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(SORT sort)

add_executable(${SORT} sort.cpp)

include(CTest)
enable_testing()

add_test(NAME test_sort  COMMAND ${SORT})
