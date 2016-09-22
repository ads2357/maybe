cmake_minimum_required (VERSION 3.1.0 FATAL_ERROR)
project (maybe)

set (CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

add_subdirectory (src)
add_subdirectory (test)
