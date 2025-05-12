/*
 * File:        test_Concurrency.cpp
 * Author:      Mohammad Rashiqul Alam
 */

#include <gtest/gtest.h>
#include "MutexCounter.h"
#include "Spinlock.h"

TEST(MutexCounterTest, MutexCounterIncrement) 
{
    // Act and Arrange
    MutexCounter_Init();

    // Assert 
    // Check if sharedCounter equals THREAD_COUNT × INCREMENTS_PER_THREAD
    EXPECT_EQ(mutexCounter, MUTEX_NUM_THREADS * MUTEX_NUM_INCREMENTS);
}

TEST(SpinlockTest, SpinlockCounterIncrement) 
{
    // Act and Arrange
    Spinlock_Init();

    // Assert 
    // Check if sharedCounter equals THREAD_COUNT × INCREMENTS_PER_THREAD
    EXPECT_EQ(spinlockCounter, SPINLOCK_NUM_THREADS * SPINLOCK_NUM_INCREMENTS);
}
