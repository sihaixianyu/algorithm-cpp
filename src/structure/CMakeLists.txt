find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCE_FILES
    linked_list.cpp
    binary_tree.cpp
)

add_library(structure SHARED ${SOURCE_FILES})
target_link_libraries(structure
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(linked-list-test linked_list.cpp)
target_link_libraries(linked-list-test
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(binary-tree-test binary_tree.cpp)
target_link_libraries(binary-tree-test
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(lru-cache-test lru_cache.cpp)
target_link_libraries(lru-cache-test
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
