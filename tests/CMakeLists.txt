# Tests need to be added as executables first
add_executable(TestsSession FMSTest.cpp)

# The C++ 17 is being used to compile the tests sources
target_compile_features(TestsSession PRIVATE cxx_std_17)

# These tests can use the Catch2-provided main
target_link_libraries(TestsSession PRIVATE LibFastMergeSort Catch2::Catch2WithMain)

# Register Catch tests in CMake
include(CTest)
include(Catch)
catch_discover_tests(TestsSession)
