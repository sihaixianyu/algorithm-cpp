find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(longest-consecutive longest_consecutive.cpp)
target_link_libraries(
    longest-consecutive
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
