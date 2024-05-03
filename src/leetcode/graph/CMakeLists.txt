find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(num-islands num_islands.cpp)
target_link_libraries(
    num-islands
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(num-enclaves num_enclaves.cpp)
target_link_libraries(
    num-enclaves
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(all-paths-source-target all_paths_source_target.cpp)
target_link_libraries(
    all-paths-source-target
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
