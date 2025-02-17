find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

# LinkedList
add_executable(linked-list linked_list.cpp)
target_link_libraries(linked-list
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

# BinaryTree
add_executable(binary-tree binary_tree.cpp)
target_link_libraries(binary-tree
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
