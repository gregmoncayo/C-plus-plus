//
//  main.cpp
//  recitation example #2
//
//  Created by Gregory Moncayo on 10/17/16.
//  Copyright (c) 2016 Gregory Moncayo. All rights reserved.
//

#include <iostream>
using namespace std;

//Put the function prototype for a function named printValues here.
//The function printValues can be called with 0, 1, 2 or 3 int parameters.
//Default values for the three parameters are 1 2 3, respectively.

void printValues (int one = 1, int two = 2, int three = 3);

int main()
{
    printValues();
    printValues(10);
    printValues(14,-3);
    printValues(7,48,29);
    
    return 0;
}


void printValues (int one, int two, int three)
{
    cout << one << ", " << two << ", " << three << ", ";
}

//Write your definition of printValues here. This function's job is to print
//any values it's given, seperated by commas.
