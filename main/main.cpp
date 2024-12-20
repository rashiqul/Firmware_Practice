#include <iostream>

/* Declare functions from C source files */
extern "C" {
    void countBitsMain();
    void DynArrAllocMain();
    void FindFirstRepeatElemIntMain();
    void FindRepeatLogMsgMain();
    void RotatedLogSearchMain();
    void SortLogMsgMain();
    void FindSubStringMain();
    void SerializeFragmentedDataMain();

}

extern void FaultedMemoryAddressMain();
extern void LinkedListMain();
extern void HashMapMain();
extern void PriorityQueueMain();
extern void FleetDiagnosticSystemMain();

int main(void)
{
    std::cout << "Starting Firmware Practice" << std::endl;
    
    /* 
     * Call functions from other source files
     * Calls should be sorted in order of complexity 
     */
    
    countBitsMain();
    DynArrAllocMain();
    FindFirstRepeatElemIntMain();
    FindRepeatLogMsgMain();
    RotatedLogSearchMain();
    SortLogMsgMain();
    FaultedMemoryAddressMain();
    FindSubStringMain();
    LinkedListMain();
    HashMapMain();
    PriorityQueueMain();
    FleetDiagnosticSystemMain();
    SerializeFragmentedDataMain();

    return 0;
}