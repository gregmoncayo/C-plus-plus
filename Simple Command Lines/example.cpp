//
//  main.cpp
//  ovoFBG
//
//  Created by Gregory Moncayo on 10/6/16.
//  Copyright (c) 2016 Gregory Moncayo. All rights reserved.
//
#include <iostream>

using namespace std;

int main()
{
    int num;
    int sum = 0;
    
    cout << " Enter a number : ";
    cin >> num;
    
    while ( num > 0 )
    {
        sum += num % 10;
        num /= 10;
    }
    
    cout << "Sum = " << sum;
    
    return 0;
}