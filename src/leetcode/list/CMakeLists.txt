find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(reverse-list reverse_list.cpp)
target_link_libraries(reverse-list
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
    PRIVATE structure
)
