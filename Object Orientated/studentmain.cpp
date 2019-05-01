#include "studentEx.h"
#include <iostream>

using namespace std;

int main()
{
    Student s("Jonny", "Smith");
    
    s.Display();
    
    cout << "About to set some grades... " << endl;
    
    s.SetTests(95, 85);
    
    s.SetQuizzes(40, 80, 70);
    
    cout << "...... & Done! " << endl;
    
    s.Display();
    
    s.CalculateFinalGrade();
    
    cout << "little bit of this & that... " << '\n';
    
    s.Display();
    
    return 0;
}
