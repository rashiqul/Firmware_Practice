cmake_minimum_required(VERSION 3.22)
project(Firmware_Practice VERSION 1.0.0 LANGUAGES C CXX)

# ======================================================
# Build Settings
# ======================================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable debug build (recommended for dev + coverage)
set(CMAKE_BUILD_TYPE Debug)

# Executable name for main()
set(EXECUTABLE_NAME Executable)

# Flag to toggle building main executable
option(COMPILE_EXECUTABLE "Compile the main executable" ON)

# ======================================================
# Subdirectories
# ======================================================

# Core code (inc + src)
add_subdirectory(code)

# Main entry (optional)
if (COMPILE_EXECUTABLE)
    add_subdirectory(main)
endif()

# Always build tests
add_subdirectory(test)
