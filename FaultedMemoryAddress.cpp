#include <iostream>
#include <vector>
#include <string>

/*
 * Binary Search for Faulty Memory Address
 * Problem: Given a vector of memory address, write a function to perform a 
 *          binary search to find the faulty memory address
 */

using namespace std;

int binarySearch(vector<string>& addresses, string target)
{
    int low  = 0;
    int high = (addresses.size() - 1);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if (addresses[mid] == target)
        {
            return mid;
        }
        else if (addresses[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

void FaultedMemoryAddressMain(void)
{
    /* Example of sorted memory address */
    vector<string> memoryAddresses = {
        "0x1A3F", "0x1A4B", "0x1A5C", "0x1A6D", "0x1A7E", 
        "0x1A8F", "0x1B00", "0x1B11", "0x1B22"
    };

    string target = "0x1A6D";

    /* Perform binary search */
    int index = binarySearch(memoryAddresses, target);

    if (index != -1) 
    {
        cout << "Faulty memory address found at index " << index << endl;
    } 
    else 
    {
        cout << "Memory address not found!" << endl;
    }
}