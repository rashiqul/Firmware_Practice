#include <stdio.h>
#include <string.h>

#define MAX        (1000)
#define LOG_LENGTH (100)

/* djb2 hash function */
int hashFunction(const char *log)
{
    /* 
     * Initialize the hash to a large prime number 
     * to avoid collisions and ensure a good distribution
     */
    int hash = 5381;
    char charValue = 0;

    while ((charValue = *log++)) 
    {
        /* 
         * Update the hash value using the formula:
         * hash = hash * 33 + c
         * This can be optimized as:
         * hash = ((hash << 5) + hash) + c
         * where (hash << 5) is equivalent to hash * 32
         * and adding hash again makes it hash * 33.
         */
        hash = ((hash << 5) + hash) + charValue;
    }

    /* Return the hash value modulo MAX to ensure it fits within the hash map size */
    return (hash % MAX);
}


int firstRepeatedLog(const char logs[][LOG_LENGTH], const int size)
{
    /* Create a hash map to track log occurance */
    int hash[MAX] = {0};
    int hashValue = 0;

    /* Traverse the array of logs */
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; logs[i][j] != '\0'; j++)
        {
            /* Calculate a robust hash value for the current log message */
            hashValue = hashFunction(logs[i]);
        }

        /* Increment the count in the hashmap */
        hash[hashValue]++;

        if (hash[hashValue] > 1)
        {
            return i;
        }
    }

    return -1;


}

int main()
{
    char logs[][LOG_LENGTH] = {"INFO: Starting process", "ERROR: Null pointer",
                               "WARNING: Low memory", "ERROR: Null pointer",
                               "INFO: Process ended"};
    
    int logSize = sizeof(logs) / sizeof(logs[0]);
    int index = firstRepeatedLog(logs, logSize);

    if (index != -1)
    {
        printf("First repeated log message at index %d\n", index);
        printf("Repeated log: %s\n", logs[index]);
    }
    else
    {
        printf("No repeating log message found\n");
    }

    return 0;
}