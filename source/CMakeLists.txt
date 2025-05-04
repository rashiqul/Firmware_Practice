# List all source files with the relative path
set(SOURCE_FILES
    source/CountSetBits/CountSetBits.c
    source/DynArrAlloc/DynArrAlloc.c
    source/FindFirstRepeatElement_Int/FindFirstRepeatElement_Int.c
    source/FindRepeatLogMsg/FindRepeatLogMsg.c
    source/RotatedLogSearch/RotatedLogSearch.c
    source/SortingLogMessages/SortingLogMessages.c
    source/FindSubString/FindSubString.c
    source/SerializeFragmentedData/SerializeFragmentedData.c
    source/FaultedMemoryAddress/FaultedMemoryAddress.cpp
    source/LinkedList/LinkedList.cpp
    source/HashMap/HashMap.cpp
    source/PriorityQueue/PriorityQueue.cpp
    source/FleetDiagnosticSystem/FleetDiagnosticSystem.cpp
    source/TwoSum/TwoSum.cpp
)

# Make `SOURCE_FILES` available to the parent CMakeLists
set(SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)