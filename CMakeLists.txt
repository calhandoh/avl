cmake_minimum_required (VERSION 3.5)

project (test_avl)
add_library (avl src/avl.c)
include_directories ("${PROJECT_SOURCE_DIR}/include")

add_executable (test_avl src/test_avl.c)
target_link_libraries (test_avl avl)