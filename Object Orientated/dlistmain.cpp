#include <iostream>
#include "dlist.h"
using namespace std;

int main()
{
    DList d;
    cout << "Initial list:\n";
    d.Print();
    
    d.Insert(5.4);
    d.Insert(2.3);
    d.Insert(10.67);
    d.Print();
    
    d.Sum();
    d.Average();
    d.Max();
    d.Greater(6);
    d.Clear();
    
    return 0;
    
}
