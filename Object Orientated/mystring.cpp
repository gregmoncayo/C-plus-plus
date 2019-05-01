//
//  mystring.cpp
//  MyString
//
//  Created by Gregory Moncayo on 7/6/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include "mystring.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

// Friend Functions

// Displays the output

ostream & operator<< (ostream & O, const MyString & M )
{
    for (int i = 0; i < M.CurrentSize; i++)
    {
        O << M.str[i];
    }
    cout << endl;
    
    return O;
}

// For user input

istream & operator>> (istream & i, MyString & M )
{
    M.CurrentSize = 0;
    M.str = 0;
    
    delete [] M.str;
    
    M.str = new char [M.CurrentSize];
    
    while (isspace(i.peek()))
        i.ignore();
    
    while (!isspace(i.peek()))
    {
        M.CurrentSize++;
        M.str[M.CurrentSize] = i.get();
        
        if (M.CurrentSize == M.length)
        {
            M.Grow();
        }
    }
    
    M.str[M.CurrentSize+1] = '\0';

    return i;
}

// For user input and reads the entire line

istream & getline (istream & i, MyString & M , char delim)
{
    delete [] M.str;
    M.CurrentSize = 0;
    int size = 0;
    
    M.str = new char[size];
    
    while (i.peek()!= delim)
    {
        if (!i.eof())
        {
            M.str[M.CurrentSize] = i.get();
            M.CurrentSize++;
            size++;
            
            if (M.CurrentSize == M.length)
            {
                M.Grow();
            }
        }
    }
   
    M.str[M.CurrentSize] = '\0';
    
    return i;
}
 
// Adds data of M1 & M2

MyString operator+ (const MyString & M1 , const MyString & M2)
{
    MyString M = M1;
    
    MyString * S = new MyString[M1.CurrentSize];
    MyString * Mtr = new MyString[M2.CurrentSize];
    
    for (int i = 0; i < M1.CurrentSize; i++)
    {
        S[i] = MyString(M1.str[i]);
        cout << S[i];
    }
    
    for (int j = 0; j < M2.CurrentSize; j++)
    {
        Mtr[j] = MyString(M2.str[j]);
    }
    
    M += *Mtr;
    
    delete [] S;
    delete [] Mtr;
    
    return M;
}

// Compares MyString objects M1 & M2, returns true if M1 is less than M2

bool operator< (const MyString & M1, const MyString & M2)
{
    for (int i = 0; i < M1.CurrentSize; i++)
    {
        
        if (int(M1.str[i]) < int(M2.str[i]))
        {
            return true;
        }
    }
    
    return false;
}

// Compares MyString M1 & M2 and returns true if M1 is greater than M2

bool operator> (const MyString & M1, const MyString & M2)
{
    if (operator<(M1,M2) == false)
    {
        return true;
    }
    
    return false;
}

// Compares MyString M1 & M2 and returns true if M1 is less than/equal to M2

bool operator<=(const MyString & M1, const MyString & M2)
{
    for (int i = 0; i < M1.CurrentSize; i++)
    {
        if (int(M1.str[i]) <= int(M2.str[i]))
        {
            return true;
        }
    }
    
    return false;
}

// Compares MyString M1 & M2 and returns true if M1 is greater than/equal to M2

bool operator>=(const MyString & M1, const MyString & M2)
{
    for (int i = 0; i < M1.length; i++)
    {
        if (int(M1.str[i]) >= int(M2.str[i]))
        {
            return true;
        }
    }
    
    return false;
}

// Determines whether M1 & M2 are equal

bool operator==(const MyString & M1 , const MyString & M2)
{
    for (int i = 0; i < M1.length; i++)
    {
        if (int(M1.str[i]) == int(M2.str[i]))
        {
            return true;
        }
    }
    
    return false;
}

// Determines whether M1 & M2 are not equal

bool operator!=(const MyString & M1, const MyString & M2)
{
    if (operator==(M1,M2) == false)
    {
        return true;
    }
    
    return false;
}

// Member Functions


// Default Constructor

MyString:: MyString()
{
    CurrentSize = 0;
    str = 0;
    length = 0;
}

// Constructor with a Character parametere

MyString:: MyString(const char * C)
{
    CurrentSize = 0;
    length = 0;
    
    int size = strlen(C);
    
    str = new char [size];
    
    strcpy(str, C);
    
    for (int i = 0; i < size; i++)
    {
        CurrentSize++;
    }
    
    str[size+1] = '\0';
    
}

// Constructor with an Int Parameter

MyString:: MyString(int M)
{
    length = 0;
    CurrentSize = 0;
    int digit = M;
    
    str = new char[CurrentSize];
    
    while (digit != 0)
    {
        str[CurrentSize] = char((digit % 10)+48);
        digit /= 10;
        CurrentSize++;
    }
    
}

// Destructor

MyString:: ~MyString()
{
    delete [] str;
}

// Copy Constructor

MyString:: MyString(const MyString& M)
{
    length = M.length;
    
    CurrentSize = M.CurrentSize;
    
    // allocates new array of MyString Objects
    str = new char[length];
    
    // Copies the list over
    for (int i = 0; i < CurrentSize; i++)
    {
        str[i] = M.str[i];
    }
    
}

// assignment operator

MyString& MyString:: operator=(const MyString& M)
{
    // Makes copy if the original is not the same
    if (this != &M)
    {
        // Deletes old array
        delete [] str;
        
        // Copies data
        length = M.length;
        
        CurrentSize = M.CurrentSize;
        
        // Declares new array
        str = new char[length];
        
        // copies array from object array
        for (int i = 0; i < CurrentSize; i++)
        {
            str[i] = M.str[i];
        }
    }
    
    return *this;       // Returns object
}

// concatenation operator
MyString& MyString:: operator+=(const MyString& M)
{
    MyString * temp = new MyString[length+M.length];
    
    for (int i = 0; i < length; i++)
    {
        temp[i] = MyString(str[i]);
    }
    
    for (int j = 0; j < length; j++)
    {
        temp[length+j] = MyString(M.str[j]);
    }
    
    delete [] temp;
    
    return *this;
}

// bracket operators to access char positions
char& MyString:: operator[] (unsigned int index)
{
    for (int i = 0; i < CurrentSize; i++)
    {
        str[index] = str[i];
    }
    
    return str[index];
}

// bracket operator to access char position

const char& MyString:: operator[] (unsigned int index) const
{
    for (int i = 0; i < CurrentSize; i++)
    {
        if (str[i] == str[index])
        {
            return str[i];
        }
    }
    
    return str[index+1];
}

// insert s into the string at position "index"
MyString& MyString:: insert(unsigned int index, const MyString& s)
{
    if (length == CurrentSize)
    {
        Grow();
    }
    
    if (index > CurrentSize)
    {
        for (int i = 0; i < length; i++)
        {
            str[i] = s[i];
        }
        
    }
    
    return *this;
}


// find index of the first occurrence of s inside the string
//  return the index, or -1 if not found
int MyString:: indexOf(const MyString& s) const
{
    for (int i = 0; i < CurrentSize; i++)
    {
        if (str[i] == s[i])
        {
            return i;
        }
    }
    
    return -1;
}

// Accessors


// Returns the length of the string
int MyString:: getLength() const
{
    return length;
}

// Returns the string
const char* MyString:: getCString() const
{
    return str;
}

// Substrings the array from index a to index b

MyString MyString:: substring(unsigned int s, unsigned int z) const
{
    MyString M;
    
    for (int i = 0; i < CurrentSize; i++)
    {
        if (str[i] == str[s] && str[i] == str[z])
        {
            return M.str[z-s];
        }

    }
 
    return M;
}

// Substrings the array from index a & on

MyString MyString:: substring(unsigned int s) const
{
    for (int i = 0; i < CurrentSize; i++)
    {
        if (str[i] == str[s])
        {
            return i;
        }
    }
    
    return s;
}

// Grows the array

void MyString:: Grow()
{
    length = length + 5;
    
    char * newlist = new char[length];
    
    for (int i = 0; i < CurrentSize; i++)
    {
        newlist[i] = str[i];
    }
    
    delete str;
    
    str = newlist;
}

// Returns the current size of the array

int MyString:: GetCurrent() const
{
    return CurrentSize;
}
