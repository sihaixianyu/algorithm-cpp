find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(max-sliding-window max_sliding_window.cpp)
target_link_libraries(
    max-sliding-window
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
