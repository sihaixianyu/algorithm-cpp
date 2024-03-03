find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(is-valid is_valid.cpp)
target_link_libraries(
    is-valid
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
