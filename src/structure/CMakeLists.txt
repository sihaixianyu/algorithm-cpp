cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(fmt REQUIRED)

# LinkedList
set(LINKED_LIST linked-list)
add_executable(${LINKED_LIST} linked_list.cpp)
target_compile_features(${LINKED_LIST} PRIVATE cxx_std_17)
target_link_libraries(${LINKED_LIST} PRIVATE fmt::fmt)

# BinaryTree
set(BINARY_TREE binary-tree)
add_executable(${BINARY_TREE} binary_tree.cpp)
target_compile_features(${BINARY_TREE} PRIVATE cxx_std_17)
target_link_libraries(${BINARY_TREE} PRIVATE fmt::fmt)

include(CTest)
enable_testing()

add_test(NAME test_linked_list  COMMAND ${LINKED_LIST})
add_test(NAME test_binary_tree  COMMAND ${BINARY_TREE})
