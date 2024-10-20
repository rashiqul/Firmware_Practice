#include <stdio.h>
#include <string.h>

/*
 * Search for a Specific Error Message in a Rotated Logs
 * Problem: You are given an array of log messages that has been rotated (e.g. after a system reboot). Write a  
 *          function to find the index of a target error message in the rotated log.
 * 
 * Solution: Use a modified binary search to handle rotated strings.    
 */

#define LOG_LENGTH (100)

int rotatedLogSearch(char logs[][LOG_LENGTH], int low, int high, char *target)
{
    while (low <= high)
    {

        int mid = (low + (high - low) / 2);

        /* Check if the middle is the target */
        if (strcmp(logs[mid], target) == 0)
        {
            return mid;
        }

        /* If left half is sorted */
        if (strcmp(logs[low], logs[mid]) <= 0)
        {
            /* Check if the target is in the left half */
            if ((strcmp(target, logs[low]) >= 0) && (strcmp(target, logs[mid]) < 0))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        /* if right half is sorted */
        if (strcmp(target, logs[mid]) >= 0 && strcmp(target, logs[high]) <= 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

int RotatedLogSearchMain(void)
{
    char logs[][LOG_LENGTH] = {
                                "INFO: Starting service", 
                                "WARNING: High temperature", 
                                "ERROR: Disk failure", 
                                "ERROR: Memory leak", 
                                "INFO: Boot complete"
                              };
    
    int size = sizeof(logs) / sizeof(logs[0]);
    char target[] = "ERROR: Memory leak";

    /* Perform a rotated log search */
    int low = 0;
    int high = (size - 1);

    int index = rotatedLogSearch(logs, low, high, target);

    if (index != -1)
    {
        printf("Target log message found at index: %d\n", index);
    }
    else
    {
        printf("Target log message not found!\n");
    }

}
