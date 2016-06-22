cmake_minimum_required(VERSION 3.5)
project(algos_cpp CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
