# =========================================
# CMakeLists.txt for test/ directory
# Uses GoogleTest only (NO CTest)
# Author: Rashiqul
# =========================================

cmake_minimum_required(VERSION 3.14)

# -----------------------------------------
# GoogleTest Download + Setup
# -----------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # MSVC-specific, safe to keep
FetchContent_MakeAvailable(googletest)

# -----------------------------------------
# Enable Code Coverage in Debug mode (GCC/Clang only)
# -----------------------------------------
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message(STATUS "✅ Code coverage enabled for GCC/Clang in Debug mode")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 --coverage")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    endif()
endif()

# -----------------------------------------
# Collect test sources (*.cpp files in test/)
# -----------------------------------------
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# -----------------------------------------
# Import all real source .c/.cpp files for coverage
# NOTE: This assumes code/src/CMakeLists.txt defines PROJECT_SOURCE_FILES
# -----------------------------------------
file(GLOB_RECURSE CODE_SOURCES_CPP ${CMAKE_SOURCE_DIR}/code/src/*.cpp)
file(GLOB_RECURSE CODE_SOURCES_C   ${CMAKE_SOURCE_DIR}/code/src/*.c)

set(CODE_SOURCES ${CODE_SOURCES_CPP} ${CODE_SOURCES_C})
# -----------------------------------------
# Build TestExecutable from tests + actual implementation .cpp files
# -----------------------------------------
add_executable(TestExecutable
    ${TEST_SOURCES}
    ${CODE_SOURCES}
)

# -----------------------------------------
# Include public headers from main source
# -----------------------------------------
target_include_directories(TestExecutable
    PRIVATE
    ${CMAKE_SOURCE_DIR}/code/inc
)

# -----------------------------------------
# Link GTest only (no CTest, no external targets)
# -----------------------------------------
target_link_libraries(TestExecutable
    PRIVATE
    gtest
    gtest_main
)

# -----------------------------------------
# Put test binary in build/test/TestExecutable
# -----------------------------------------
set_target_properties(TestExecutable PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
)
