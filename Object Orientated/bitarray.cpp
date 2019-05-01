/*
 Name: Gregory Moncayo
 Course: COP 3330
 Assignment: Assignment # 7
 Due Date: 04/18/2018
 About this Project: To gain experience with bitwise operations, used inside a class. Also will provide further practice with dynamic allocation.
 */

#include <iostream>
#include "bitarray.h"

// friend function to output the bits.

ostream& operator<< (ostream& os, const BitArray& a)
{
    for (int i = 0; i < a.Length(); i++)
    {
        os << a.Query(i);
    }
    
    return os;
}

// comparison operator that determines whether data a is equal to data b.

bool operator== (const BitArray& a, const BitArray& b)
{
    for (int i = 0; i < a.arraySize; i++)
    {
        if (a.barray[i] == b.barray[i])
        {
            return true;
        }
    }
    
    return false;
}

// comparison operator that determines whether data x is not equal to data y.

bool operator!= (const BitArray& x, const BitArray& y)
{
    for (int i = 0; i < x.arraySize; i++)
    {
        if (x.barray[i] != y.barray[i])
        {
            return false;
        }
    }
    
    return false;
}

// Constructor with single paramter that initialiaze the data and sets the array dynamically.

BitArray:: BitArray(unsigned int n)
{
    barray = 0;
    arraySize = ((n-1)/BitSize)+1;
    
    barray = new unsigned char [arraySize];
    
    for (int i = 0; i < arraySize; i++)
    {
        barray[i] = 0;
    }
}

// copy constructor

BitArray:: BitArray(const BitArray& B)
{
    arraySize = B.arraySize;
    
    // allocates new entry of arrays
    barray = new unsigned char [arraySize];
    
    
    // Copies the list over from Parameter
    for (int i = 0; i < arraySize; i++)
    {
        barray[i] = B.barray[i];
    }
}

// destructor that cleans up the memory.

BitArray:: ~BitArray()
{
    delete [] barray;
}

// assignment operator

BitArray& BitArray:: operator= (const BitArray& a)
{
    if (this != &a)
    {
        // step 1: delete exisiting array
        delete [] barray;
        
        // step 2: copy as if the copy constructor
        arraySize = a.arraySize;
        
        // Step 3: allocate a new entry of arrays
        barray = new unsigned char [arraySize];
        
        // Step 4: Copy the list over from the parameter
        for (int i = 0; i < arraySize; i++)
        {
            barray[i] = a.barray[i];
        }
    }
    
    return *this;
}

// returns the length of the bits.

unsigned int BitArray:: Length() const
{
    return sizeof(unsigned char)*8*arraySize;
}

// sets the bit numbers from 0 to 1

void BitArray:: Set (unsigned int index)
{
    barray[index/BitSize] = barray[index/BitSize] | (1 << (index % BitSize));
}

// sets the bit numbers to 0.

void BitArray:: Unset (unsigned int index)
{
    barray[index/BitSize] = barray[index/BitSize] & ~(1 << (index % BitSize));
}

// sets the number to the complete opposite. 0's turns to 1's while 1's turn to zeros.

void BitArray:: Flip (unsigned int index)
{
    barray[index/BitSize] = barray[index/BitSize] ^ (1 << (index % BitSize));
}

// returns true if bit number is 1 and false if otherwise.

bool BitArray:: Query (unsigned int index) const
{
    if (barray[index/BitSize] & (1 << (index % BitSize)))
    {
        return true;
    }
    
    return false;
}

// Returns the size of the array

int BitArray:: ReturnArraySize() const
{
    return arraySize;
}

