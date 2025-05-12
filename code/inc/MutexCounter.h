/*
 * File:        MutexCounter.h
 * Author:      Mohammad Rashiqul Alam
 */

#ifndef MUTEX_COUNTER_H
#define MUTEX_COUNTER_H

#ifdef __cplusplus
extern "C" {
#endif

// ==========================
//        INCLUDES
// ==========================
#include <stdio.h>
#include <pthread.h>

// ==========================
//        LOCAL DEFINES
// ==========================
#define MUTEX_NUM_THREADS 5
#define MUTEX_NUM_INCREMENTS 10000

// ==========================
//        GLOBAL VARIABLES
// ==========================
extern int mutexCounter;
extern pthread_mutex_t counterMutex;

// ==========================
//        FUNCTIONS
// ==========================
void MutexCounter_Init(void);
void *MutexCounterIncrement_Task(void *arg);

#ifdef __cplusplus
}
#endif


#endif /* MUTEX_COUNTER_H */