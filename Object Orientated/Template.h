//
//  Template.h
//  Template
//
//  Created by Gregory Moncayo on 7/30/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#ifndef Template_h
#define Template_h

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int SIZE = 10;

template <class T>
class Pizza
{
    public:
    Pizza();
    ~Pizza();
    bool Enter(string word);
    bool insert(T value);
    T ReturnPrice();
    string ReturnChoice();
    void Display();
    
    private:
    T price;
    string choice;
    T arr[SIZE];
    int current;
};

#endif
