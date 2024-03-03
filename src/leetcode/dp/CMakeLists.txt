find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(max-profit max_profit.cpp)
target_link_libraries(
    max-profit
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
