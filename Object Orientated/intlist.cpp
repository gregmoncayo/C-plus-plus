#include <iostream>
#include "intlist.h"

using namespace std;

Intlist:: Intlist()
{
    current = 0;
    arr[current] = 1;
    current++;
}

Intlist:: Intlist(int n)
{
    current = 0;
    arr[current] = n;
    current++;
}

bool Intlist:: Find(unsigned int value)
{
    for(int i = 0; i < current; i++)
    {
        if(arr[i] == value)
            return i;
    }
    
    return false;
}
bool Intlist:: insert(unsigned int index, int num)
{
    if (index < size)
    {
        arr[current] = num;
        current++;
        return true;
    }
    
    return false;
}

void Intlist::  Display() const
{
    cout << "Summary for the Integer List: " << endl;
    cout << "------------------------------ " << endl;
    for (int i = 0; i < current; i++)
        cout << arr[i] << ' ';
    
    cout << endl;
}
