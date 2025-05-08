#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Error Code Tracking using Hash Maps
 * Problem: In an embedded system, error codes are frequently generated during runtime.
 *          Write a function in C that tracks the frequency of error codes using a hash
 *          map and returns the most frequently occurring error code. 
 *
 * Assume: The hash map is implemented as a simple array of linked lists.
 */

#define MAX_HASH      (100)
#define MAX_ERROR_LEN (50)

typedef struct Node
{
    int errorCode;
    int count;
    Node_t *next;
}Node_t;

/* Hash map array */
Node_t* hashMap[MAX_HASH] = {NULL};


int hash(const char *errCode)
{
    int hashValue = 0;
    while (*errCode)
    {
        /*  */
        hashValue = (hashValue + *errCode ) % MAX_SIZE;
        errCode++;
    }
    return hashValue;
}

/*  Function to insert or update error code in the hash map */
void InsertErrorCode(const char *errCode) 
{
    int index = hash(errCode);
    Node_t* temp = hashMap[index];

    /* Traverse linked list at hash_map[index] to find the error code */
    while (temp) 
    {
        if (strcmp(temp->errorCode, errCode) == 0) 
        {
            /* Increment count if found */
            temp->count++;  
            return;
        }
        temp = temp->next;
    }

    /* Create a new node if not found */
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    strcpy(newNode->errorCode, errCode);
    newNode->count = 1;
    newNode->next = hashMap[index];
    hashMap[index] = newNode;
}

/* Function to find the most frequent error-code */
void MostFrequentError(void) 
{
    int maxCount = 0;
    char frequentError[MAX_ERROR_LEN] = "";

    /* Traverse the hash map to find the error code with the highest count */
    for (int i = 0; i < MAX_HASH; i++) 
    {
        Node_t* temp = hashMap[i];
        while (temp) {
            if (temp->count > maxCount) {
                maxCount = temp->count;
                strcpy(frequentError, temp->errorCode);
            }
            temp = temp->next;
        }
    }

    if (maxCount > 0) 
    {
        printf("Most frequent error code: %s, Occurrences: %d\n", frequentError, maxCount);
    } 
    else 
    {
        printf("No error codes found.\n");
    }
}

void ErrorCodeTrackingMain(void)
{
    /* Example error codes */
    const char *errCodes[] = {
        "ERROR_404", "ERROR_500", "ERROR_404", 
        "ERROR_200", "ERROR_500", "ERROR_404", "ERROR_503"
    };

    int size = sizeof(errCodes) / sizeof(errCodes[0]);

    /* Insert error codes into the hash map */
    for (int i = 0; i < size; i++)
    {
        InsertErrorCode(errCodes[i]);
    }

    /* Find and display the most frequent error code */
    MostFrequentError();
}