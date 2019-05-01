// Bob Myers
// driver.cpp -- driver program to demonstrate the behavior of
// 	  	 the House class

#include <iostream>
#include "house.h"

using namespace std;

int main()
{
    // create some Houses
    House h1( -5 ), h2( 7, '^' ), h3( 12, 'W', 'o' ), h4( 50 , '$' , '-');
    // display original Houses
    
    cout << "h1 has size = " << h1.GetSize() << " units.\n";
    h1.draw();
    cout << "\nh2 has size = " << h2.GetSize() << " units.\n";
    h2.draw();
    cout << "\nh3 has size = " << h3.GetSize() << " units.\n";
    h3.draw();
    cout << "\nh4 has size = " << h4.GetSize() << " units.\n";
    h4.draw();
    cout << '\n';
    
    h1.Shrink(); // demonstrate shrink
    h2.Shrink();
    h3.Grow(); // and grow
    h4.Grow();
    cout << "h1 now has size = " << h1.GetSize() << " units.\n";
    cout << "h2 now has size = " << h2.GetSize() << " units.\n";
    cout << "h3 now has size = " << h3.GetSize() << " units.\n";
    cout << "h4 now has size = " << h4.GetSize() << " units.\n";
    
    // demonstrate perimeter
    cout << "h2 has perimeter = " << h2.perimeter() << " units.\n";
    cout << "h3 has perimeter = " << h3.perimeter() << " units.\n";
    // and area
    cout << "h2 has area = " << h2.area() << " square units.\n\n";
    cout << "h3 has area = " << h3.area() << " square units.\n\n";
    
    h1.draw();
    h1.Grow();               // show that fill character
    cout << "h1 grows:\n";   // appears only when size
    h1.draw();               // is at least 3
    h1.Grow();
    cout << "... and grows:\n";
    h1.draw();
    cout << '\n';
    
    h1 = h2; // demonstrate the default overload of the
    // assignment operator
    cout << "h1 now has size = " << h1.GetSize() << " units.\n";
    h1.draw();
    
    // demonstrate the changing of border and fill characters
    h2.setborder('@');
    h2.SetFill('-');
    cout << "h2 now looks like:\n";
    h2.draw();
    cout << '\n';
    h2.setborder('\n');	 // illegal border
    h2.SetFill('\a');	 // illegal fill
    cout << "h2 now looks like:\n";
    h2.draw();
    cout << '\n';
    
    cout << "\nHere is a summary on h3:\n"; // demonstrate summary
    h3.summary();
    
    return 0;
}
