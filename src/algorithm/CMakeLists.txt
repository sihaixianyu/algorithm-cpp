find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(sort sort.cpp)
target_link_libraries(
    sort
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(binary-search binary_search.cpp)
target_link_libraries(
    binary-search
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
