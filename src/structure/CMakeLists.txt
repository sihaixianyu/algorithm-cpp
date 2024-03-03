find_package(GTest REQUIRED)
find_package(fmt REQUIRED)

# LinkedList
add_executable(linked-list linked_list.cpp)
target_link_libraries(
    linked-list
    PRIVATE GTest::gtest_main
    PRIVATE fmt::fmt
)

# BinaryTree
add_executable(binary-tree binary_tree.cpp)
target_link_libraries(
    binary-tree
    PRIVATE GTest::gtest_main
    PRIVATE fmt::fmt
)
