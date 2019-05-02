//
//  main.cpp
//  recitation example #3
//
//  Created by Gregory Moncayo on 10/31/16.
//  Copyright (c) 2016 Gregory Moncayo. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int arr[5];
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    
    int even = 0, odd = 0, i = 0;
    
    for (i = 0; i < 5; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        
        else
            odd++;
    }
    
    cout << "There are " << even << " numbers & there are " << odd << " numbers " << endl;
    
    return 0;
}
