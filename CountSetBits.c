#include <stdio.h>
#include <stdint.h>

#define MAX_BYTES        (4)

/*
 * Problem: Count the number of set bits in a given number
 *          Return -1 if the number of bytes exceeds MAX_BYTES
 * 
 * Assumption: No NULL pointer is being passed
 */


#define TRIVIAL_SOLUTION (1)

#if TRIVIAL_SOLUTION
int countBits (void* address, int length)
{   
    int count      = 0;
    uint8_t byte   = 0;
    uint8_t* bytes = NULL; 
    /* Check for overflow condition */
    if (length > MAX_BYTES)
    {
        return -1;
    }

    bytes = (uint8_t*)address;

    for (int i = 0; i < length; i++)
    {
        /* Extract each byte from the given bytes */
        byte = bytes[i];
        while (byte)
        {
            /* Count the set bits in the current byte */
            count += (byte & 1);
            byte >>= 1;
        }
    }
    
    return count;
}
#endif /* TRIVIAL_SOLUTION */


void countBitsMain(void)
{   
    
    uint32_t numbers[] = {
                            100,                // 7-bit number
                            0xF0F0F0F0,         // 32-bit number
                            0xFFFFFFFF,         // 32-bit boundary
                            255                 // 8-bit number 
                         };

    int length = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i < length; i++)
    {
        printf("Number: 0x%X\n", numbers[i]);
        printf("Number of set bits: %d\n", countBits(&numbers[i], sizeof(numbers[i])));
    }
}