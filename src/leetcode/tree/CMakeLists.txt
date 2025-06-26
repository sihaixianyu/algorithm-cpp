find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(sorted-array-to-bst sorted_array_to_bst.cpp)
target_link_libraries(
    sorted-array-to-bst
    PRIVATE structure
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
