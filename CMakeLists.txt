cmake_minimum_required(VERSION 3.10)
project(algos_cpp CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
