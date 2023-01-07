# List all source (.cpp) files
file(GLOB sources_list CONFIGURE_DEPENDS "*.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(libfastmergesort SHARED ${sources_list})

# Add OpenMP library
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(libfastmergesort PUBLIC OpenMP::OpenMP_CXX)
endif()

# Include specific directory, so the compiler knows where to seek for header files
target_include_directories(libfastmergesort PUBLIC ../inc)
