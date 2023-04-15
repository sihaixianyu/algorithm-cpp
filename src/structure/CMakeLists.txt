find_package(GTest REQUIRED)
find_package(fmt REQUIRED)

include(GoogleTest)

# LinkedList
set(LINKED_LIST linked-list)
add_executable(${LINKED_LIST} linked_list.cpp)
target_link_libraries(
    ${LINKED_LIST}
    PRIVATE GTest::gtest_main
    PRIVATE fmt::fmt
)

# BinaryTree
set(BINARY_TREE binary-tree)
add_executable(${BINARY_TREE} binary_tree.cpp)
target_link_libraries(
    ${BINARY_TREE}
    PRIVATE GTest::gtest_main
    PRIVATE fmt::fmt
)

enable_testing()
add_test(NAME test-linked-list  COMMAND ${LINKED_LIST})
add_test(NAME test-binary-tree  COMMAND ${BINARY_TREE})
