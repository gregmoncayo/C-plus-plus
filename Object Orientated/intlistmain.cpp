//
//  Intlistmain.cpp
//  IntList
//
//  Created by Gregory Moncayo on 8/1/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include "intlist.h"
using namespace std;

int main()
{
    Intlist l;
    Intlist l2(2);
    l.Display();
    l2.Display();
    
    l.insert(1, 10);
    l.insert(2,50);
    l.insert(3,750);
    l.insert(4,100000);
    
    l.Display();
    
    l2.insert(1, 25);
    l2.insert(2, 89);
    l2.insert(6, 14);
    l2.Display();
    
    cout << '\n';
    cout << l2.Find(14);
    
    return 0;
}
