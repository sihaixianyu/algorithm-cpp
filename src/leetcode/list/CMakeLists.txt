find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/structure)

add_executable(reverse-linked-list reverse_linked_list.cpp)
target_link_libraries(reverse-linked-list
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
