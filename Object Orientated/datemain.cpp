/////////////////////////////////////////////////////////
// Bob Myers
//
// sample.cpp -- sample test program starter for Date class
/////////////////////////////////////////////////////////

#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    Date d1;		// should default to 1/1/2000
    Date d2(4,10,1992);  // should init to 4/10/1992
    
    // display dates to the screen
    cout << "\nDate d1 is: ";
    d1.Show();
    cout << "\nDate d2 is: ";
    d2.Show();
    
    d1.Input();			// Allow user to enter a date for d1
    cout << "\nDate d1 is: ";
    d1.Show();
    
    d1.SetFormat('L');		// change format of d1 to "Long" format
    cout << "\nDate d1 is: ";
    d1.Show();			// print d1 -- should show now in long format
    
    d2.Input();
    cout << "Date for d2: ";
    d2.SetFormat('T');
    d2.Show();
    d2.SetFormat('D');
    d2.Show();
    
    cout << " Enter a date for d1: ";
    d1.Input();
    d1.Increment();
    d1.Show();
    
    cout << "D2: ";
    d2.Input();
    d2.Increment(5);
    d2.Show();
    
    d1.compare(d2);
    
    // and so on.  Add your own tests to fully test the class'
    //   functionality.
}
