file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/inc/*.h")

# Make an automatic library - will be static or dynamic based on user setting
add_library(libfastmergesort FastMergeSortAlgorithm.cpp ${HEADER_LIST})

# Include specific directory, so the compiler knows where to seek for header files
target_include_directories(libfastmergesort PUBLIC ../inc)
