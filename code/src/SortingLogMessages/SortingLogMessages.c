#include <stdio.h>
#include <string.h>

/*
 * Sorting Log Messages with Priority
 * Problem: Given an array of log messages that contain priority levels ("INFO", "WARNING", "ERROR"), 
 * sort the logs in the order of priority.
 * 
 * Solution: Use a custom comparator function to sort the log messages.
 */

#define LOG_LENGTH (100)

void sortLogs(char logs[][LOG_LENGTH], int size)
{
    int low  = 0;
    int high = (size - 1);
    int mid  = 0;

    while (mid <= high)
    {
        if (strstr(logs[mid], "ERROR"))
        {
            /* Swap logs[low] and logs[mid] */
            char temp[LOG_LENGTH];
            strcpy(temp, logs[low]);
            strcpy(logs[low], logs[mid]);
            strcpy(logs[mid], temp);
            low++;
            /* Move mid forward after swapping */
            mid++;
        }
        else if (strstr(logs[mid], "WARNING"))
        {
            /* Move mid forward for "WARNING" */
            mid++;
        }
        else
        {
            /* Swap logs[mid] and logs[high] */
            char temp[LOG_LENGTH];
            strcpy(temp, logs[mid]);
            strcpy(logs[mid], logs[high]);
            strcpy(logs[high], temp);
            /* Move high backward after swapping */
            high--;
            
        }
    }
}

void SortLogMsgMain(void)
{
    char logs[][LOG_LENGTH] = {
                               "INFO: Starting service", 
                               "ERROR: Null pointer",
                               "WARNING: Low memory", 
                               "INFO: Process ended",
                               "ERROR: Disk failure"
                              };

    int size = (sizeof(logs) / sizeof(logs[0]));

    sortLogs(logs, size);

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", logs[i]);
    }
}