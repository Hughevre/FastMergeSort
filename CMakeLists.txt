cmake_minimum_required(VERSION 3.0.0)
project(FastMergeSort 
        VERSION 1.0.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Jump to the library sources
add_subdirectory(src)

# Jump to the tests sources
enable_testing()
add_subdirectory(tests)

# Setup CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
