cmake_minimum_required (VERSION 3.1)
project (EigenBoost)

include (cmake/Common.cmake)

enable_testing()

add_subdirectory (lib)
add_subdirectory (src)
include_directories (src)
add_subdirectory (test)
