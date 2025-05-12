/*
 * File:        MutexCounter.c
 * Author:      Mohammad Rashiqul Alam
 * Description: Increment a shared counter using threads and pthread mutex
 */

// ==========================
//        INCLUDES
// ========================== 
#include "MutexCounter.h"
#include <pthread.h>

// ==========================
//        GLOBAL VARIABLES
// ==========================
int mutexCounter = 0;
pthread_mutex_t counterMutex;

// ==========================
//        FUNCTIONS
// ==========================
void* MutexCounterIncrement_Task(void *arg)
{
    for (int i = 0; i < MUTEX_NUM_INCREMENTS; i++)
    {
        // Lock the mutex beofre accessing the shared counter
        pthread_mutex_lock(&counterMutex);
        // Increment the shared counter
        mutexCounter++;
        printf("[Mutex] Thread %ld incremented counter to %d\n", pthread_self(), mutexCounter);
        // Unlock the mutex
        pthread_mutex_unlock(&counterMutex);
    }
    return NULL;
}



void MutexCounter_Init(void)
{
    // locals
    pthread_t threads[MUTEX_NUM_THREADS];

    // Initialize the mutex
    pthread_mutex_init(&counterMutex, NULL);

    // Create threads iteratively
    for(int i = 0; i < MUTEX_NUM_THREADS; i++)
    {
        // Create threads
        pthread_create(&threads[i], NULL, MutexCounterIncrement_Task, NULL);
    }

    // Wait for all threads to finish
    for(int i = 0; i < MUTEX_NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&counterMutex);
}






