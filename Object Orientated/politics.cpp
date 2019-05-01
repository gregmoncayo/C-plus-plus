//
//  main.cpp
//  Politics as usual
//
//  Created by Gregory Moncayo on 7/13/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include "votes.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    votes v1("Bill Cosby");
    votes v("Hilary Clinton");
    votes v2("Gregory Moncayo");
    
    cout << "The 2018 presidental candidates are: " << endl;
    cout << v1 << endl;
    cout << v << endl;
    cout << v2 << endl;
    
    v1.AddPrecinct(69);
    v.AddPrecinct(2500);
    v2.AddPrecinct(2501);
    
    cout << "The votes are in! " << endl;
    cout << "------------------" << endl;
    cout << v1;
    cout << v2;
    cout << v << endl;
    
    cout << "Greg Moncayo wins!!!" << endl;
    
    return 0;
}
