/*
 Name: Gregory Moncayo
 Course: COP 3330
 Assignment: Assignment # 7
 Due Date: 04/18/2018
 About this Project: To gain experience with bitwise operations, used inside a class. Also will provide further practice with dynamic allocation.
 */

#ifndef _BITARRAY_H
#define _BITARRAY_H

#include <iostream>
using namespace std;

class BitArray
{
    friend ostream& operator<< (ostream& os, const BitArray& a);    // To output the data.
    friend bool operator== (const BitArray& a, const BitArray& b);  // to determine whether the data is equal or not.
    friend bool operator!= (const BitArray& x, const BitArray& y);  // To determine whether the data is not equal.
    
public:
    BitArray(unsigned int n);    // Construct an array that can handle n bits
    BitArray(const BitArray& B) ;   // copy constructor
    ~BitArray();                 // destructor
    
    BitArray& operator= (const BitArray& a);  // assignment operator
    
    unsigned int Length() const;            // return number of bits in bitarray
    
    void Set   (unsigned int index);        // set bit with given index to 1
    void Unset (unsigned int index);        // set bit with given index to 0
    void Flip  (unsigned int index);        // change bit (with given index)
    bool Query (unsigned int index) const;  // return true if the given bit
    //  is set to 1, false otherwise
    
    // accessors
    int ReturnArraySize() const;    // Returns arraySize
    
private:
    unsigned char* barray;           // pointer to the bit array
    int arraySize;                  // Variable to hold size of array
    static const int BitSize = sizeof(unsigned char) * 8;   // Variable to find the size of the bits per byte.
};

#endif
