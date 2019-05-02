//
//  main.cpp
//  Recitation Exercise #1
//
//  Created by Gregory Moncayo on 9/19/16.
//  Copyright (c) 2016 Gregory Moncayo. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
 
    int num = 0;
    
    cout << "Enter an integer value: ";
    cin >> num;
    
    if (num > 0)
    {
        cout << num << " is positive." << endl;
    }
    
    else if (num < 0)
    {
        cout << num << " is negative. " << endl;
    }
    
    if (num % 5 == 0)
    {
        cout << num << " is divisible by 5. " << endl;
    }
    
    else
    {
        cout << num << " is not divisible by 5. " << endl;
    }
    
    if (num % 2 == 0)
    {
        cout << num << " is even. " << endl;
    }
    
    else if (num % 2 != 0)
    {
        cout << num << " is odd. " << endl;
    }
        
    return 0;
}
