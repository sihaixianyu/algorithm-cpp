find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

set(IS_VALID is_valid)
add_executable(${IS_VALID} is_valid.cpp)
target_link_libraries(
    ${IS_VALID}
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
