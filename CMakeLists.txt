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

# Add the source directory
add_subdirectory(source)

# Add the executable using the files from the source directory
add_executable(Firmware_Practice ${SOURCE_FILES})

# Link the main executable with the main directory sources
target_link_libraries(Firmware_Practice main)