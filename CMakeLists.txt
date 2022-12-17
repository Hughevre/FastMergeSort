cmake_minimum_required(VERSION 3.0.0)
project(FastMergeSort 
        VERSION 0.1.0
        LANGUAGES CXX)

# Add Catch2 testing library
find_package(Catch2 2 REQUIRED)

# Jump to the library sources
add_subdirectory(src)

# Jump to the tests sources
add_subdirectory(tests)

# Setup CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
