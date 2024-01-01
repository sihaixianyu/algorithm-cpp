find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

set(SORT sort)
add_executable(${SORT} sort.cpp)
target_link_libraries(
    ${SORT}
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

set(BINARY_SEARCH binary-search)
add_executable(${BINARY_SEARCH} binary_search.cpp)
target_link_libraries(
    ${BINARY_SEARCH}
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
