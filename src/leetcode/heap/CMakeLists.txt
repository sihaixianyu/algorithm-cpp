find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(find-kth-largest find_kth_largest.cpp)
target_link_libraries(
    find-kth-largest
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
