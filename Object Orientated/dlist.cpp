#include <iostream>
#include "dlist.h"

using namespace std;

DList::DList()
{
    current = 0;
}

bool DList::Insert(double item)
{
    if (current < MAX)
    {
        array[current] = item;
        current++;
        return true;
    }
    else
        return false;
}

double DList::GetElement(unsigned int n) const
{
    if (n >= current)		// only can get items from used slots
        n = current - 1;
    return array[n];
}

void DList::Print() const
{
    if (current == 0)
    {	cout << "Empty List" << endl;
        return;
    }
    int i;
    for (i = 0; i < current-1; i++)
        cout << array[i] << ", ";
    cout << array[i] << endl;
}

int DList::GetSize() const
{
    return current;
}

bool DList:: Delete(int n)
{
    
    
    return false;
}

double DList:: Sum()
{
    double sum = 0.0;
    
    for (int i = 0; i < current; i++)
    {
        sum += array[i];
    }
    
    cout << sum << endl;
    
    return sum;
}

double DList:: Average()
{
    double average = 0.0;
    
    for (int i = 0; i < current; i++)
    {
        average += array[i] / current;
    }
    
    cout << average << endl;
    
    return average;
}

double DList:: Max()
{
    double max = 0.0;
    
    for (int i = 0; i < current; i++)
    {
        if (array[i] > array[current])
        {
            max = array[i];
        }
    }
    
    cout << max << endl;
    
    return max;
}

void DList:: Clear()
{
    for (int i = 0; i < current; i++)
    {
        array[i] = 0;
    }
}

int DList:: Greater(double x)
{
    int count = 0;
    
    for (int i = 0; i < current; i++)
    {
        if (array[i] < x)
        {
            count++;
        }
    }
    
    cout << count << endl;
    
    return count;
}
