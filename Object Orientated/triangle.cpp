//
//  main.cpp
//  COP 3330 Triangle
//
//  Created by Gregory Moncayo on 1/22/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "triangle.h"
using namespace std;

// Default constructor that sets the size, border, and filler parameter.

Triangle:: Triangle (int Size, char border, char filler)
{
    bord = border;
    fill = filler;
    
    if (Size < 1)
    {
        size = 1;
    }
    
    else if (Size > 39)
    {
        size = 39;
    }
    
    else
    {
        size = Size;
    }
    
}

// Returns the size

int Triangle:: GetSize()
{
    return size;
}

// Returns the perimeter

int Triangle:: Perimeter()
{
    return (size*3);
}

// Returns the area

double Triangle:: Area()
{
    return ((size*size)/2);
}

// Grows the triangle

const int Triangle:: Grow()
{
    size++;
    
    return size;
}

// Shrinks the triangle

const int Triangle:: Shrink()
{
    size--;
    
    return size;
}

// Sets rules for the outside border.

void Triangle:: SetBorder(char bore)
{
    if (bore >= 33 && bore <= 126)
    {
        bord = bore;
    }
    
    else
        bord = '#';
}

// Sets rules for the inside filler.

void Triangle:: SetFill(char full)
{
    if (full >= 33 && full <= 126)
    {
        fill = full;
    }
    
    else
        fill = '*';
        
}

// To help explicity draw the triangle.

void Triangle:: Draw()
{
    for (int i = 0; i < size; i++)
    {
        cout << " ";
        
        for (int k = 0; k < size-i; k++)
        {
            cout << " ";
        }
        
        for (int j = 0; j <= i; j++)
        {
            
            cout << " ";
            
            if (j == 0 || j == i || i == size-1)
            {
                cout << bord;
            }
            
            else
            {
                cout << fill;
            }
        }
        cout << endl;
    }
    
}

// To print the summarization of the triangle aspects.

void Triangle:: Summary()
{
    cout << showpoint;
    cout << fixed;
    cout << " Size of triangle's side = " << size << " units." << endl;
    cout << " Perimter of triangle = " << Perimeter() << " units." << endl;
    cout << " Area of triangle = " << setprecision(2) << Area() << " units." << endl;
    cout << " Triangle looks like " << endl;
    Draw();
}
