find_package(Boost 1.60 REQUIRED COMPONENTS unit_test_framework)

add_executable(test_binsearch test_binsearch.cpp)
target_include_directories(test_binsearch PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(test_binsearch ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME "binary_search_test" COMMAND test_binsearch)
