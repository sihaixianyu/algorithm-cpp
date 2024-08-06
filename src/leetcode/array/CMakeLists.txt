find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(three-sum three_sum.cpp)
target_link_libraries(
    three-sum
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
