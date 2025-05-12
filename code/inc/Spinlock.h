/*
 * File:        Spinlock.h
 * Author:      Mohammad Rashiqul Alam
 */

#ifndef SPINLOCK_H
#define SPINLOCK_H


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
#define SPINLOCK_NUM_THREADS 4
#define SPINLOCK_NUM_INCREMENTS 500

// ==========================
//        GLOBAL VARIABLES
// ==========================
extern int spinlockCounter;
extern pthread_spinlock_t spinlock;

// ==========================
//        FUNCTIONS
// ==========================
void* Spinlock_Task(void *arg);
void Spinlock_Init(void);


#ifdef __cplusplus
}
#endif

#endif /* SPINLOCK_H */