/*
 * File:        test_BitManipulation.cpp
 * Author:      Mohammad Rashiqul Alam
 */

#include <gtest/gtest.h>
#include "BitManipulation.h"

TEST(BitManipulationTest, SetBit)
{
    // Arrange
    // Initial value of the register
    uint32_t regVal = 0x00000000;
    uint8_t bitPos  = 3; 

    // Act
    regVal = setBit(regVal, bitPos);

    // Assert
    EXPECT_EQ(regVal, 0x0000008);
}

TEST(BitManipulationTest, ClearBit)
{
    // Arrange
    // Initial value of the register
    uint32_t regVal = 0x00000008;
    uint8_t bitPos  = 3; 

    // Act
    regVal = clearBit(regVal, bitPos);

    // Assert
    EXPECT_EQ(regVal, 0x00000000);
}

TEST(BitManipulationTest, ToggleBit)
{
    // Arrange
    // Initial value of the register
    uint32_t regVal = 0x00000003;
    uint8_t bitPos  = 3; 

    // Act
    regVal = toggleBit(regVal, bitPos);

    // Assert
    EXPECT_EQ(regVal, 0x0000000B);
}

TEST(BitManipulationTest, ReadBit)
{
    // Arrange
    // Initial value of the register
    uint32_t regVal = 0x00000003;
    uint8_t bitPos  = 3; 

    // Act
    uint32_t bitValue = readBit(regVal, bitPos);

    // Assert
    EXPECT_EQ(bitValue, 0);
}