# Tests need to be added as executables first
add_executable(TestsSession FMSSanityTest.cpp)

# The C++ 17 is being used in the test
target_compile_features(TestsSession PRIVATE cxx_std_17)

# These tests can use the Catch2-provided main
target_link_libraries(TestsSession PRIVATE LibFastMergeSort Catch2::Catch2WithMain)
