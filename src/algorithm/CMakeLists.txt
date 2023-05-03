find_package(GTest REQUIRED)
find_package(fmt REQUIRED)

set(SORT sort)
add_executable(${SORT} sort.cpp)
target_link_libraries(
    ${SORT}
    PRIVATE GTest::gtest_main
    PRIVATE fmt::fmt
)
