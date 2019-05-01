//
//  Header.h
//  GasPump
//
//  Created by Gregory Moncayo on 2/12/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//
#include <iostream>

using namespace std;

class Gas
{
    public:
        Gas();
        const void Summary();
        void Input();
    
    // Accessors
    int GetGallons();
    int GetChoice();
    double ReturnStandard();
    double ReturnPrem();
    double ReturnDiseal();
    
    
    private:
        double standard;
        double preminum;
        double diseal;
        char choice;
        int gallons;
};
