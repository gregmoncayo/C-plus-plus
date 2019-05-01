//
//  template.cpp
//  Template
//
//  Created by Gregory Moncayo on 7/30/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include "Template.h"

using namespace std;

template<class T>
Pizza <T> :: Pizza()
{
    current = 0;
    price = 0.0;
    choice = "Cheese";
    arr[current] = 0;
}

template<class T>
Pizza <T> :: ~Pizza()
{
    cout << "Goodbye! " << endl;
}

template<class T>
bool Pizza <T>:: insert(T value)
{
    if (value > 0)
    {
        price = value;
        arr[current] = value;
        current++;
        return true;
    }
    
    return false;
}

template<class T>
T Pizza <T>:: ReturnPrice()
{
    return price;
}

template<class T>
string Pizza <T>:: ReturnChoice()
{
    return choice;
}

template<class T>
bool Pizza<T>:: Enter(string word)
{
    choice = word;
    
    return true;
}

template<class T>
void Pizza <T>:: Display()
{
    cout << " Summary for your order: " << endl;
    
    for (int i = 0; i < current; i++)
    {
        cout << choice << arr[i] << endl;
    }
}
