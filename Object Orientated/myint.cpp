#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "myint.h"

/*
 Name: Gregory Moncayo
 Course: COP 3330
 Assignment: Assignment # 5
 Due Date: 03/26/2018
 About this Project: To learn more about dynamic allocation.
 */

using namespace std;

// Adds up the integers.

MyInt operator+(const MyInt& x, const MyInt & y)
{
    int sum = 0;
    int total = 0;
    int whole = 0;
    
    for (int i = 0; i < x.size; i++)
    {
        sum = x.arr[i];
    }
    
    for (int j = 0; j < y.size; j++)
    {
        total = y.arr[j];
    }
   
    if (x.arr < y.arr)
    {
        for (int i = 0; i < x.size; i++)
        {
            for (int j = y.size; j <= y.size; j--)
            {
                total = y.arr[j]+x.arr[i];
            }
        }
    }
    
    whole = total + sum;
    
    return whole;
}

// Subtracts the intgers.

MyInt operator-(const MyInt & x, const MyInt & y)
{
    int difference = 0;
    int different = 0;
    int diff = 0;
    
    for (int i = 0; i < x.size; i++)
    {
        difference = x.arr[i];
    }
    
    for (int j = 0; j < y.size; j++)
    {
        different = y.arr[j];
    }
    
    diff = difference - different;
    
    return diff;
}

// Multiplies the integers.

MyInt operator*(const MyInt & x, const MyInt & y)
{
    int multiply = 0;
    int mult = 0;
    int total = 0;
    
    for (int i = 0; i < x.size; i++)
    {
        multiply = x.arr[i] % 10;
    }
    
    for (int j = 0; j < y.size; j++)
    {
        mult = y.arr[j] % 10;
    }
    
    return multiply;
}

// shows the remainder between the two integers.

MyInt operator%(const MyInt & x, const MyInt & y)
{
    int total = 0;
    
    for (int i = 0; i < 4; i++)
    {
        total = x.arr[i] % y.arr[i];
    }
    
    return total;
}

// Outputs the data.

ostream & operator << (ostream & f, MyInt i)
{
    for (int j = 0; j < i.size; j++)
    {
        f << i.arr[j];
    }
    
    return f;
}

// Inputs the data.

istream & operator >> (istream & s,  MyInt & i)
{
    for (int j = 0; i < i.size; j++)
    {
        s.peek();
        
        if (s.peek() != ' ')
        {
            s >> i.arr[j];
        }
    }
    
    return s;
}

// Compares whether the first parameter is less than the second parameter.

bool operator< (const MyInt & x, const MyInt & y)
{
        if (x.arr < y.arr)
        {
            return true;
        }
    
    return false;
}

// Compares whether the first parameter is greater than the second parameter.

bool operator> (const MyInt & x, const MyInt & y)
{
        if (x.arr > y.arr)
        {
            return true;
        }
    
    
    return false;
}

// Compares whether the first parameter is greater than or equal to the second parameter.

bool operator>= (const MyInt & x, const MyInt & y)
{
        if (x.arr >= y.arr)
        {
            return true;
        }
    
    return false;
}

// Compares whether the second parameter is less than or equal to the second parameter.

bool operator<= (const MyInt & x, const MyInt & y)
{
        if (x.arr <= y.arr)
        {
            return true;
        }
    
    return false;
}

// Determines whether both parameters are equal.

bool operator== (const MyInt & x, const MyInt & y)
{
        if (x.arr == y.arr)
        {
            return true;
        }
    
    return false;
}

// Determines whether if both parameters are not equal.

bool operator != (const MyInt & x, const MyInt & y)
{
        if (x.arr != y.arr)
        {
            return true;
        }
    
    return false;
}

// first constructor with integer paramter

MyInt:: MyInt(int n)
{
    arr = 0;
    size = 0;
    int temp = n;
    
    if (n < 0)
    {
        size = 1;
        arr = new int [size];
        arr[0] = 0;
    }
    
    else if (!n)
    {
        size = 1;
        arr = new int [size];
        arr[0] = 0;
    }
    
    else
    {
        arr = new int [size];
        
        
        while (temp != 0)
        {
            arr[size] = temp % 10;
            temp /= 10;
            size++;
        }
        
    }
    
}

// second constructor with character string

MyInt:: MyInt(char s[])
{
    size = static_cast<unsigned>(strlen(s));
    
    arr = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        
        if (s[i] > '0' || s[i] < '9')
        {
            arr[i] = C2I(s[i]);
        }
        
        else if (!isalnum(s[i]))
        {
            arr[0] = 0;
        }
        
        else
        {
            arr[0] = '0';
        }
    }
    
}

// destructor

MyInt:: ~MyInt()
{
    delete [] arr;
}

// copy constructor

MyInt:: MyInt(const MyInt & i)
{
    size = i.size;
    arr = new int [size];
    
    for (int j = 0; j < size; j++)
    {
        arr[j] = i.arr[j];
    }
}

// assignment operator

MyInt & MyInt:: operator=(const MyInt & i)
{
    if (this != &i)
    {
        delete [] arr;
        
        size = i.size;
        
        arr = new int[size];
        
        for (int j = 0; j < size; j++)
        {
            arr[j] = i.arr[j];
        }
   
    }
    
    return *this;
}

// Pre increment

MyInt & MyInt:: operator++()
{
    size = 1 + size;
    
    int * grow = new int [size];
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = grow[i];
    }
    
    delete [] arr;
    
    arr = grow;
    
    return *this;
}

// post increment

MyInt MyInt:: operator++(int)
{
    size = size + 1;
    
    int * ptr = new int [size];
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = ptr[i];
    }
    
    delete [] arr;
    
    arr = ptr;
    
    return *this;
}

int MyInt:: C2I(char c)
// converts character into integer (returns -1 for error)
{
    if (c < '0' || c > '9')	return -1;	// error
    return (c - '0');				// success
}

char MyInt:: I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
    if (x < 0 || x > 9)		return '\0';	// error
    return (static_cast<char>(x) + '0'); 	// success
}

// returns value of the pointer

int MyInt:: GetArr()
{
    return *arr;
}

// returns size

int MyInt:: GetSize()
{
    return size;
}

// Add in operator overload and member function definitions
