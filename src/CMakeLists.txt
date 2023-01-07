#file(GLOB headers_list CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/inc/*.h")
file(GLOB sources_list CONFIGURE_DEPENDS "*.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(libfastmergesort SHARED ${sources_list})

# Include specific directory, so the compiler knows where to seek for header files
target_include_directories(libfastmergesort PUBLIC ../inc)
