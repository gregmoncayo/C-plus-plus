/////////////////////////////////////////////////////////
// Bob Myers
//
// sample.cpp -- sample test program starter for Temperature class
/////////////////////////////////////////////////////////

#include <iostream>
#include "temperature.h"

using namespace std;

int main()
{
    Temperature t1;		// should default to 0 Celsius
    Temperature t2(34.5, 'F');  // should init to 34.5 Fahrenheit
    Temperature t3(31.5, 'F');
    
    // display dates to the screen
    cout << "\nTemperature t1 is: ";
    t1.Show();
    cout << "\nTemperature t2 is: ";
    t2.Show();
    
    t1.Input();			// Allow user to enter a temperature for t1
    cout << "\nTemperature t1 is: ";
    t1.Show();
    
    t1.SetFormat('L');		// change format of t1 to "Long" format
    cout << "\nTemperature t1 is: ";
    t1.Show();
    
    t1.set(90, 'F');
    cout << " \n The temperature for t1 is: ";
    t1.Show();
    
    t2.GetScale();
    cout << "\n Scale for t2 is: ";
    t2.Show();
    
    t2.SetFormat('D');
    cout << "\n Temperature for t2 is: ";
    t2.Show();
    
    t2.convert('C');
    cout << "\n t2 is now: ";
    t2.Show();
    
    t2.convert('K');
    cout << "\n t2 is now: ";
    t2.Show();
    
    t2.convert('F');
    cout << "\n t2 is now: ";
    t2.Show();
    
    t2.convert('K');
    cout << "\n t2 is now: ";
    t2.Show();
    
    t2.convert('C');
    cout << "\n t2 is now: ";
    t2.Show();
    
    cout << "\n";
    t1.compare(t3);
    
    t3.compare(t1);
    
    // and so on.  Add your own tests to fully test the class'
    //   functionality.
}
