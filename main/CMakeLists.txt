# Add all source files in the main directory
file(GLOB MAIN_SOURCES "*.cpp")

# Create a library from the main sources
add_library(main ${MAIN_SOURCES})