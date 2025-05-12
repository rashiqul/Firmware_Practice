/*
 * File:        Spinlock.c
 * Author:      Mohammad Rashiqul Alam
 * Description: Thread-safe counter using pthread spinlock
 */

// ==========================
//        INCLUDES
// ========================== 
#include "Spinlock.h"

// ==========================
//        GLOBAL VARIABLES
// ==========================
int spinlockCounter = 0;
pthread_spinlock_t spinlock;

// ==========================
//        FUNCTIONS
// ==========================
void* Spinlock_Task(void *arg)
{
    // Increment the counter NUM_INCREMENTS times and lock the spinlock
    for (int i = 0; i < SPINLOCK_NUM_INCREMENTS; i++)
    {
        // Lock the spinlock
        pthread_spin_lock(&spinlock);
        // Critical section
        spinlockCounter++;
        printf("[Spinlock] Thread %ld incremented counter to %d\n", pthread_self(), spinlockCounter);
        // Unlock the spinlock
        pthread_spin_unlock(&spinlock);
    }
    return NULL;
}

void Spinlock_Init(void)
{
    // locals
    pthread_t threads[SPINLOCK_NUM_THREADS];
    // Initialize the spinlock    
    pthread_spin_init(&spinlock, 0);
    // Create threads iteratively
    for(int i = 0; i < SPINLOCK_NUM_THREADS; i++)
    {
        // Create threads
        pthread_create(&threads[i], NULL, Spinlock_Task, NULL);
    }
    // Wait for all threads to finish
    for(int i = 0; i < SPINLOCK_NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    // Destroy the spinlock
    pthread_spin_destroy(&spinlock);
}
