#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*
 * Memory Management - Dynamic Array Allocation
 * Problem: Implement a custom memory allocator that mimics the behavior of malloc using a fixed-size memory pool. 
 *          Then, modify the original function to utilize this custom allocator instead of the standard malloc    
 */

/* Define a size of the memory pool, default is 1024 bytes */
#define MEMORY_POOL_SIZE 1024

static char memoryPool[MEMORY_POOL_SIZE];

/* Pointer to keep track of the next free block */
static char* memoryPoolPtr = memoryPool;


void* custom_malloc(size_t size)
{
    /* Check if memory is available */
    if ((memoryPoolPtr + size) > (memoryPool + MEMORY_POOL_SIZE))
    {
        printf("Memory pool is full!\n");
        return NULL;
    }

    /* Allocate memory from the pool */
    void* allocatedMemory = (void*)memoryPoolPtr;
    memoryPoolPtr += size;

    return allocatedMemory;
}


int* createDynamicArray(int size)
{
    int* array = (int*)custom_malloc(size * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    /* Initialize each element to its index value */
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }

    return array;
}

void resetMemoryPool(void)
{
    memoryPoolPtr = memoryPool;
}


 int main(void)
 {
    int size = 10;
    int* array = createDynamicArray(size);

    /* Check for NULL */
    if (array != NULL)
    {
        /* Print the elements in the array */
        for (int i = 0; i < size; i++)
        {
            printf("array[%d] = %d\n", i, array[i]);
        }
    }

    resetMemoryPool();
 }