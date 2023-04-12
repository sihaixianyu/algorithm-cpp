find_package(fmt REQUIRED)

# Sort
set(SORT sort)
add_executable(${SORT} sort.cpp)
target_link_libraries(${SORT} PRIVATE fmt::fmt)

include(CTest)
enable_testing()

add_test(NAME test_sort  COMMAND ${SORT})
