# Use the latest version of CMake
cmake_minimum_required(VERSION 3.22)

# Set the project name, version, and languages
project(Firmware_Practice VERSION 1.0.0 LANGUAGES C CXX)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# Set the C standard to C99
set(CMAKE_C_STANDARD          99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS        OFF)

# Enable debug symbols
set(CMAKE_BUILD_TYPE Debug)

# Add the code directory
add_subdirectory(main)

# Add all source files in the root directory
file(GLOB ROOT_SOURCES "*.c")



# Add all source files in the root directory
set(ROOT_SOURCES
    DynArrAlloc.c
    FindFirstRepeatElement_Int.c
    FindRepeatLogMsg.c
    RotatedLogSearch.c
    SortingLogMessages.c
)

# Combine all source files
set(SOURCES ${ROOT_SOURCES})

# Add the executable
add_executable(Firmware_Practice ${SOURCES})

# Link the main executable with the main directory sources
target_link_libraries(Firmware_Practice main)