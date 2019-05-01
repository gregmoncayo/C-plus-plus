//
//  main.cpp
//  COP3330 Hw #1
//
//  Created by Gregory Moncayo on 9/10/17.
//  Copyright © 2017 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "house.h"
using namespace std;

House:: House(int size2, char charac, char fill)
{
    
    if (size2 < 3)
    {
        size = 3;
    }
    
   else if (size2 > 37)
    {
        size = 37;
    }
    
    else
    {
        size = size2;
    }
   
    border = charac;
    
    filler = fill;
    
}

int House:: GetSize()
{
    return size;
}

int House:: perimeter()
{
    int sum = (size * 5) + 6;
    
    return sum;
}

double House:: area()
{
    double square = size * size;
    
    double triangle = (size * size * 0.5);
    
    return (triangle+square);
}

const int House:: Grow()
{
        size++;
    
    return size;
}


const int House:: Shrink()
{
        size--;
    
    return size;
}

void House:: setborder(char bord)
{
    
    if (bord < 33)
        border = 'X';
    
    if (bord > 126)
        border = 'X';
    
    else
        border = bord;
    
}

void House:: SetFill(char fill)
{
    if (fill < 33)
    {
        filler = '*';
    }
    
    if (fill > 126)
    {
        filler = '*';
    }
    
    else
    {
        filler = fill;
    }
}

void House:: draw()
{
    for (int i = 0; i < size + 2; i++)
    {
        for (int k = 0; k < size-1-i; k++)
        {
            cout << " ";
        }
        
        for (int j = size-1-i; j < size-1; j++)
        {
                cout << ' ' << border;
            
            if (i == 0)
            {
                cout << filler;
            }
            
        }
        
        cout << endl;
    }
    
    for (int row = 0; row < size; row++)
    {
        if (row == size - 1)
        {
            for (int l = 0; l < size; l++)
            {
                cout << ' ' << border;
                
            }
            
        }
        else
        {
        
            for (int z = 0; z < size + 2; z++)
            {
                if (z == 0 || z == size + 1)
                {
                    cout << ' ' << border;
                }
                
                if (z == size-1-row)
                {
                    cout << ' ' << filler;
                }
                
                else
                    cout << filler;
            }
        }
        
        cout << endl;
    }
    
}

void House:: summary()
{
    cout << showpoint;
    cout << fixed;
    cout << " House width and height base to the roof = " << size << " units. " << endl;
    cout << " Perimeter of the house " << size * 6 << " units. " << endl;
    cout << " Area of the house " << setprecision(2) << size * size << " units. " << endl;
    cout << " House looks like " << endl;
    draw();
}
