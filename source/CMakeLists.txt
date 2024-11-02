# List all source files with the relative path
set(SOURCE_FILES
    source/CountSetBits.c
    source/DynArrAlloc.c
    source/FindFirstRepeatElement_Int.c
    source/FindRepeatLogMsg.c
    source/RotatedLogSearch.c
    source/SortingLogMessages.c
    source/FindSubString.c
    source/FaultedMemoryAddress.cpp
)

# Make `SOURCE_FILES` available to the parent CMakeLists
set(SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)