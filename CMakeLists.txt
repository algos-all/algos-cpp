cmake_minimum_required(VERSION 3.9)
project(algos_cpp CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
