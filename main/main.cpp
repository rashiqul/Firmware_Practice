#include <iostream>

/* Declare functions from C source files */
extern "C" {
    void DynArrAllocMain();
    void FindFirstRepeatElemIntMain();
    void FindRepeatLogMsgMain();
    void RotatedLogSearchMain();
    void SortLogMsgMain();
}


int main(void)
{
    std::cout << "Starting Firmware Practice" << std::endl;
    
    /* Call functions from other source files */
    DynArrAllocMain();
    FindFirstRepeatElemIntMain();
    FindRepeatLogMsgMain();
    RotatedLogSearchMain();
    SortLogMsgMain();

    return 0;
}