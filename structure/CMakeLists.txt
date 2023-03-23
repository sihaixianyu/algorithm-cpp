cmake_minimum_required(VERSION 3.0.0)

set(TEST_LINKED_LIST test-linked-list)
set(TEST_BINARY_TREE test-binary-tree)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)

include(CTest)
enable_testing()

add_executable(${TEST_LINKED_LIST} linked_list.c)
add_executable(${TEST_BINARY_TREE} binary_tree.c)

add_test(NAME ${TEST_LINKED_LIST}  COMMAND ${TEST_LINKED_LIST})
add_test(NAME ${TEST_BINARY_TREE}  COMMAND ${TEST_BINARY_TREE})
