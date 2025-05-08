# =========================================
# CMakeLists.txt for main/ directory
# Builds the main executable from main.cpp + all source modules
# =========================================

# Include main.cpp + all gathered source files
add_executable(${EXECUTABLE_NAME}
    main.cpp
    ${PROJECT_SOURCE_FILES}
)

# Include headers
target_include_directories(${EXECUTABLE_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/code/inc
)

# Optional: organize output
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/main
)
