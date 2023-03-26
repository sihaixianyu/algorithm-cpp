cmake_minimum_required(VERSION 3.0.0)

set(TEST_LINKED_LIST test-linked-list)
set(TEST_BINARY_TREE test-binary-tree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(CTest)
enable_testing()

add_executable(${TEST_LINKED_LIST} linked_list.cpp)
add_executable(${TEST_BINARY_TREE} binary_tree.cpp)

add_test(NAME ${TEST_LINKED_LIST}  COMMAND ${TEST_LINKED_LIST})
add_test(NAME ${TEST_BINARY_TREE}  COMMAND ${TEST_BINARY_TREE})
