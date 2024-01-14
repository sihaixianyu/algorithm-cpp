find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

set(FIND_KTH_LARGEST find_kth_largest)
add_executable(${FIND_KTH_LARGEST} find_kth_largest.cpp)
target_link_libraries(
    ${FIND_KTH_LARGEST}
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
