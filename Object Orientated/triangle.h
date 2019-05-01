//
//  Header.h
//  COP 3330 Triangle
//
//  Created by Gregory Moncayo on 1/22/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

class Triangle
{
    public:
    Triangle(int Size, char border = '#', char filler = '*'); // Constructor
    
    // member functions
    int GetSize();
    int Perimeter();
    double Area();
    const int Grow();
    const int Shrink();
    void SetBorder(char bore);
    void SetFill(char full);
    
    // Standard input/output functions
    void Draw();
    void Summary();
    
    
    private:
    int size;
    char bord;
    char fill;
};
