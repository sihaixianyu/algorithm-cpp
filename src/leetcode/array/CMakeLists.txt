find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(three-sum three_sum.cpp)
target_link_libraries(
    three-sum
    PRIVATE GTest::gtest_main
)

add_executable(trap trap.cpp)
target_link_libraries(
    trap
    PRIVATE GTest::gtest_main
)

add_executable(merge-intervals merge_intervals.cpp)
target_link_libraries(
    merge-intervals
    PRIVATE GTest::gtest_main
)

add_executable(rotate-array rotate_array.cpp)
target_link_libraries(
    rotate-array
    PRIVATE GTest::gtest_main
)

add_executable(product-except-self product_except_self.cpp)
target_link_libraries(
    product-except-self
    PRIVATE GTest::gtest_main
)

add_executable(first-missing-positive first_missing_positive.cpp)
target_link_libraries(
    first-missing-positive
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
