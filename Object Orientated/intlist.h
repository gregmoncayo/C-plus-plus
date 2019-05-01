#include <iostream>

using namespace std;

const int size = 10;

class Intlist
{
public:
    Intlist();
    Intlist(int n);
    bool Find(unsigned int value);
    bool insert(unsigned int index, int num);
    void Display() const;
    
private:
    int arr[size];
    int current;
};
