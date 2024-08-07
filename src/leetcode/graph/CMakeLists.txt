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

add_executable(surrounded-regions surrounded_regions.cpp)
target_link_libraries(
    surrounded-regions
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(all-paths-source-target all_paths_source_target.cpp)
target_link_libraries(
    all-paths-source-target
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(rotted-oranges rotted_oranges.cpp)
target_link_libraries(
    rotted-oranges
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(can-finish can_finish.cpp)
target_link_libraries(
    can-finish
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(trie trie.cpp)
target_link_libraries(
    trie
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
