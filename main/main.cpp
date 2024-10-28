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

}

extern void FaultedMemoryAddressMain();


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

    return 0;
}