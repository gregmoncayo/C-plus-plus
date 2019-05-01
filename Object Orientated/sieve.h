/*
 Name: Gregory Moncayo
 Course: COP 3330
 Assignment: Assignment # 7
 Due Date: 04/18/2018
 About this Project: To gain experience with bitwise operations, used inside a class. Also will provide further practice with dynamic allocation.
 */


#include <iostream>
#include <cmath>

#ifndef sieve_h
#define sieve_h

// sets the bits all to 1 and then sets the 0, 1, 2 to 0 and even prime number equal to 0.

void Sieve (BitArray & b)
{
    for (int i = 0; i < b.Length(); i++)
    {
        b.Set(i);
        
        if (i == 0 || i == 1)
        {
            b.Unset(i);
        }
        
        else
        {
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    b.Unset(i);
                }
            }
        }
    }
    
    
}



#endif /* sieve_h */
