#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int firstRepeated(int* arrPtr, int size)
{
    /* Initialize hash table */    
    int hash[MAX] = {0};

    /* Traverse the array */
    for(int i = 0; i < size; i++)
    {
        /* Increment the count of the element */
        hash[arrPtr[i]]++;
        if (hash[arrPtr[i]] > 1)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int size  = sizeof(arr)/sizeof(arr[0]);
    int index = firstRepeated(arr, size);

    if (index != -1)
    {
        printf("First Repeating element is %d\n", arr[index]);
    }
    else
    {
        printf("No repeating element found\n");
    }
}