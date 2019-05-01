#include <iostream>
using namespace std;

#include "complex.h"

void PrintComplex(const char* label, Complex c);

int main()
{
    // test object construction
    
    Complex c1;			// 0 + 0i
    Complex c2(7.5);		// 7.5 + 0i
    Complex c3(3.6, 2.1);	// 3.6 + 2.1i
    Complex c4(5, -8);		// 5 - 8i
    Complex c5(0, 8.4);		// 0 + 8.4i
    Complex c6(0, -9.3);		// 0 - 9.3i
    
    // test output (insertion operator << )
    
    PrintComplex("c1", c1);
    PrintComplex("c2", c2);
    PrintComplex("c3", c3);
    PrintComplex("c4", c4);
    PrintComplex("c5", c5);
    PrintComplex("c6", c6);
    
    
    // test input (extraction operator >> )
    
    cout << "Enter new value for c1: ";
    cin >> c1;
    cout << "Enter new value for c2: ";
    cin >> c2;
    
    cout << "\nYou entered:\n";
    PrintComplex("c1", c1);
    PrintComplex("c2", c2);
    
    
    
}

void PrintComplex(const char* label, Complex c)
// for testing output
{
    cout << label << ": " << c << '\n';
}
