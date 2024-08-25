find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(find-anagrams find_anagrams.cpp)
target_link_libraries(
    find-anagrams
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)

add_executable(min-window min_window.cpp)
target_link_libraries(
    min-window
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
