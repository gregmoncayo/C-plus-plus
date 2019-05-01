//
//  mixed.cpp
//  mixed numbers
//
//  Created by Gregory Moncayo on 6/9/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include "mixed.h"
#include <iostream>
#include <iomanip>

using namespace std;

// To display the Mixed fraction

ostream & operator<<(ostream & s, const Mixed & m)
{
    if (m.numerator == 0 && m.denominator == 0)
    {
        s << m.integer << endl;
    }
    
    else if (m.integer == 0)
        s << m.numerator << "/" << m.denominator << endl;
    
    else
        s << m.integer << " " << m.numerator << "/" << m.denominator << endl;
    
    return s;
}

// To insert a new mixed number

istream & operator>>(istream & i, Mixed & m)
{
    char slash;
    
    i >> m.integer >> m.numerator >> slash >> m.denominator;
    
    return i;
}

// operator overloads comparisons operators

// To determined whether the mixed numbers are equal or not, returns true if equal

bool operator==(const Mixed & M1, const Mixed & M2)
{
    if (M1.integer == M2.integer)
    {
        if (M1.integer == M2.integer)
        {
            if (M1.denominator == M2.denominator)
            {
                return true;
            }
        }
    }
    
    return false;
}

// To determine if mixed numbers are not equal, returns true if not equal

bool operator!=(const Mixed & M1, const Mixed & M2)
{
    if (operator==(M1, M2) == false)
    {
        return true;
    }
    
    return false;
}

// Determines whether first mixed number is less than/equal to second mixed number, returns true if this is the case.

bool operator<=(const Mixed & M1, const Mixed & M2)
{
    Mixed answer = M1.integer * M1.numerator * M1.denominator;
    Mixed total = M2.integer * M2.numerator * M2.denominator;
    
    if (M1.integer <= M2.integer)
    {
        return true;
    }
    
    else if (M1.integer == M2.integer)
    {
        if (answer <= total)
        {
            return true;
        }
    }
    
    return false;
}

// Determines whether first mixed number is greather than or equal to second mixed number, returns true if it is.

bool operator>=(const Mixed & M1, const Mixed & M2)
{
    if (operator<=(M1, M2) == false)
    {
        return true;
    }
    
    return false;
}

// Determines whether first mixed number is less than second mixed number, returns true if it is.

bool operator<(const Mixed & M1, const Mixed & M2)
{
    if (M1.integer*M1.numerator*M1.denominator < M2.integer*M2.numerator*M2.denominator)
    {
        return true;
    }
    
    return false;
}

// Determines whether first mixed number is less than second mixed number, returns true if it is.

bool operator>(const Mixed & M1, const Mixed & M2)
{
    if (operator<(M1, M2) == false)
    {
        return true;
    }
    
    return false;
}

//operator overloads arthimetic operations

// Adds the mixed numbers together.

Mixed operator+(const Mixed & M1, const Mixed & M2)
{
    Mixed M;
    
    M.numerator = (M1.numerator*M2.denominator)+(M2.numerator*M1.denominator);
    
    M.denominator = M1.denominator*M2.denominator;
    
    M.integer = M1.integer + M2.integer;
    
    if (M1.denominator == M2.denominator)
    {
        return Mixed(M1.integer+M2.integer, M1.numerator+M2.numerator, M1.denominator+0);
    }
    
    while (M.numerator > M.denominator)
    {
        M.numerator = M.numerator-M.denominator;
        M.integer = M.integer + 1;
    }
    
    return M;
}

// Subtracts the mixed numbers together.

Mixed operator-(const Mixed & M1, const Mixed & M2)
{
    if (M1.denominator == M2.denominator)
    {
        return Mixed(M1.integer-M2.integer, M1.numerator-M2.numerator, M1.denominator-0);
    }
    
    Mixed M;
    
    M.numerator = (M1.numerator*M2.denominator)-(M2.numerator*M1.denominator);
    
    M.denominator = M1.denominator*M2.denominator;
    
    M.integer = M1.integer-M2.integer;
    
    while (M.numerator > M.denominator)
    {
        M.numerator = M.numerator-M.denominator;
        M.integer = M.integer + 1;
    }
    
    return M;
}

// Multiplies the mixed numbers together.

Mixed operator*(const Mixed & M1, const Mixed & M2)
{
    Mixed M;
    
    M.numerator = ((M1.denominator*M1.integer)+M1.numerator)*((M2.denominator*M2.integer)+M2.numerator);
    
    M.denominator = M1.denominator * M2.denominator;
    
    while (M.numerator > M.denominator)
    {
        M.numerator = M.numerator-M.denominator;
        M.integer = M.integer + 1;
    }
  
    return M;
}

// Divides the mixed numbers together.

Mixed operator/(const Mixed & M1, const Mixed & M2)
{
    Mixed M;
    
    M.numerator = ((M1.integer*M1.denominator)+M1.numerator)*(M2.denominator);
    
    M.denominator = M1.denominator * ((M2.integer*M2.denominator)+M2.numerator);
    
    while (M.numerator > M.denominator)
    {
        M.numerator = M.numerator-M.denominator;
        M.integer = M.integer + 1;
    }
    
    return M;
}

// Member functions

// Default constructor with optional parameter

Mixed:: Mixed(int value)
{
    if (value == 0)
    {
        integer = 0;
        numerator = 0;
        denominator = 0;
    }
    
    else
    {
        integer = value;
        numerator = 0;
        denominator = 0;
    }
}

// Constructor with three parameters that sets the member data.

Mixed:: Mixed(int i, int n, int d)
{
    if (d <= 0)
    {
        integer = i;
        numerator = 0;
        denominator = 0;
    }
    
    
    else if (i < 0)
    {
        if (n < 0 || d < 0)
        {
            integer = 0;
            numerator = 0;
            denominator = 0;
        }
        
        if (n > 0 && d > 0)
        {
            integer = i;
            numerator = n;
            denominator = d;
        }
        
    }
    
    else
    {
        integer = i;
        numerator = n;
        denominator = d;
    }
}

// Decimal evaluates the mixed number.

double Mixed:: Evaluate()
{
    double answer = static_cast<double>(numerator)/denominator;
    
    return answer+integer;
}

// To make the mixed fraction into an irregular fraction

void Mixed:: ToFraction()
{
    if (integer < 0)
    {
        numerator = -1*(numerator+(denominator*(integer*-1)));
        integer = 0;
    }
    
    numerator = numerator+(denominator*integer);
    integer = 0;
}

// To simplify the fraction to the lowest term

void Mixed:: Simplify()
{
    while (numerator > denominator)
    {
        numerator = numerator - denominator;
        integer++;
    }
    
    if (numerator > 0 && denominator > 0)
    {
        if (denominator % numerator == 0)
        {
            denominator = denominator/numerator;
            numerator = numerator/numerator;
        }
    }
}

// pre increment

Mixed & Mixed:: operator++()
{
    integer = integer + 1;
    
    return *this;
}

// post increment

Mixed & Mixed:: operator++(int)
{
    Mixed temp = *this;
    integer = integer + 1;
    return temp;
}

// pre increment

Mixed & Mixed:: operator--()
{
    integer = integer - 1;
    
    return *this;
}

// post increment

Mixed & Mixed:: operator--(int)
{
    Mixed temp = *this;
    integer = integer - 1;
    return temp;
}

// Accessors

// returns the whole number
int Mixed:: GetInteger()
{
    return integer;
}

// returns the numerator

int Mixed:: ReturnNum()
{
    return numerator;
}

// returns the denominator

int Mixed:: ReturnDenom()
{
    return denominator;
}
