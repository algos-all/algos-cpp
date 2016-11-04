find_package(Boost 1.62 REQUIRED COMPONENTS unit_test_framework)

add_subdirectory(sort)
add_subdirectory(graph)

file(
    GLOB TESTFILES
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

foreach(TESTFILE ${TESTFILES})
    string(REPLACE ".cpp" "" TESTNAME ${TESTFILE})
    add_executable(${TESTNAME} ${TESTFILE})
    target_include_directories(${TESTNAME} PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${TESTNAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

    add_test(NAME "${TESTNAME}" COMMAND ${TESTNAME})
endforeach(TESTFILE)
