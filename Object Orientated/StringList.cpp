//
//  StringList.cpp
//  StringList
//
//  Created by Gregory Moncayo on 7/31/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include "StringList.h"

ostream& operator<<( ostream& o, const StringList& S)
{
    for (int i = 0; i < S.current; i++)
    {
        o << S.array[i];
    }
    o << endl;
    
    return o;
}

istream& operator>>(istream& i, const StringList& S)
{
    while (!isspace(i.peek()))
    {
        i.ignore();
        
        i.get();
    }
    
    return i;
}

StringList:: StringList()
{
    current = 0;
    S = "Hello";
    array[current] = '\0';
}

StringList:: StringList(const char * C)
{
    current = strlen(C);
    
    strcpy(array, C);
}

bool StringList:: Find(unsigned int value)
{
    for (int i = 0; i < current; i++)
    {
        if (array[i] == value)
        {
            return i;
        }
    }
    
    return false;
}

bool StringList:: insert(unsigned int value)
{
    if (current != 10)
    {
        array[current+1] = value;
        return true;
    }
    
    return false;
}

string StringList:: GetString() const
{
    return S;
}

char StringList:: GetArr() const
{
    return * array;
}

int StringList:: ReturnCurrent() const
{
    return current;
}
