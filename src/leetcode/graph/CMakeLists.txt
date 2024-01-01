find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

set(NUM_ISLANDS num_islands)
add_executable(${NUM_ISLANDS} num_islands.cpp)
target_link_libraries(
    ${NUM_ISLANDS}
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
