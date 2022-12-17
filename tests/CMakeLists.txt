# Add Catch2 testing library
find_package(Catch2 2 REQUIRED)

# Tests need to be added as executables first
set(EXECUTABLE_NAME "FMSTests")
add_executable(${EXECUTABLE_NAME} IntegersTest.cpp)

# The compiler has to use C++ 17 to compile the tests sources
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)

# Add support for the code coverage
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake_modules)
if (CMAKE_BUILD_TYPE MATCHES Debug)
    include(CodeCoverage)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

    SETUP_TARGET_FOR_COVERAGE(${EXECUTABLE_NAME}Coverage 
                              ${EXECUTABLE_NAME} 
                              CoverageTestSuite)
endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"

# These tests can use the Catch2-provided main
target_link_libraries(${EXECUTABLE_NAME} PRIVATE libfastmergesort Catch2::Catch2WithMain)

# Register Catch2-based tests in CMake build system
include(CTest)
include(Catch)
enable_testing()
catch_discover_tests(${EXECUTABLE_NAME})
