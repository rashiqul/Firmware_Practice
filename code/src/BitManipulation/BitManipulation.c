/*
 * File:        BitManipulation.c
 * Author:      Mohammad Rashiqul Alam
 */

// ==========================
//        INCLUDES
// ==========================
#include "BitManipulation.h"

// ==========================
//        FUNCTIONS
// ==========================
uint32_t setBit(uint32_t regValue, uint8_t pos)
{
    regValue |= (1 << pos);
    return regValue;
}

uint32_t clearBit(uint32_t regValue, uint8_t pos)
{
    regValue &= ~(1 << pos);
    return regValue;
}

uint32_t toggleBit(uint32_t regValue, uint8_t pos)
{
    regValue ^= (1 << pos);
    return regValue;
}

uint32_t readBit(uint32_t regValue, uint8_t pos)
{
    return ((regValue >> pos) & 1);
}

uint32_t writeBitField(uint32_t regVal, uint8_t pos, uint8_t width, uint8_t fieldVal)
{
   // Clear the bits in the field
   // (1 << width) - 1) is a mask with the width of the field
    uint32_t mask = ((1 << width) - 1) << pos;
    regVal &= ~mask;
    // Set the new value in the field
    // (fieldVal << pos) shifts the field value to the correct position
    // & mask ensures that only the bits in the field are set
    regVal |= (fieldVal << pos) & mask;

    return regVal;
}

