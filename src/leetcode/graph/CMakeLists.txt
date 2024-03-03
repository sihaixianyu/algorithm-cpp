find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(num-islands num_islands.cpp)
target_link_libraries(
    num-islands
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
