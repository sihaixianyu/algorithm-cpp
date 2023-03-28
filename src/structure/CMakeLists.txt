cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(LINKED_LIST linked-list)
set(BINARY_TREE binary-tree)

add_executable(${LINKED_LIST} linked_list.cpp)
add_executable(${BINARY_TREE} binary_tree.cpp)

include(CTest)
enable_testing()

add_test(NAME test_linked_list  COMMAND ${LINKED_LIST})
add_test(NAME test_binary_tree  COMMAND ${BINARY_TREE})
