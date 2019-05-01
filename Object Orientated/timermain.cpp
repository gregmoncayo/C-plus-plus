//
//  main.cpp
//  COP3330 timer example
//
//  Created by Gregory Moncayo on 2/12/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

//-------------- main.cpp --------------

#include <iostream>      // for cout, cin
#include "timer.h"    // for our Timer and Display classes

using namespace std;

void timerInput(Timer& t, const char* label);
void tick(Timer& t, const char* which, int howMany);
void showTimers(const Timer& t1, const Timer& t2);

int main()
{
    Timer t1;           // Create and initialize a Timer object named "t1."
    Timer t2(12, 57);
    
    cout << "Here are the initial value of the timers: \n";
    showTimers(t1, t2);
    
    timerInput(t1, "first");
    timerInput(t2, "second");
    showTimers(t1, t2);
    
    // Testing add()
    cout << "The two timers added together = ";
    t1.add(t2).show();
    cout << "\n\n";
    
    // Testing increment()
    int num;
    
    cout << "How many minutes should we advance the timers? ";
    cin >> num;
    tick(t1, "first", num);
    tick(t2, "second", num);
    
    return 0;
    
}


void timerInput(Timer& t, const char* label)
{
    int h, m;
    bool success;
    
    do
    {
        cout << "Enter hours for " << label << " timer: ";
        cin >> h;
        cout << "Enter minutes for " << label << " timer: ";
        cin >> m;
        success = t.set(h,m);
        
        if (!success)
            cout << "Invalid timer values. Try again.\n";
        
    } while (!success);
    
    cout << '\n';
}

void tick(Timer& t, const char* which, int howMany)
{
    cout << "Incrementing " << which << " timer by "
    << howMany << " minutes\n";
    cout << "Initial timer value = ";
    t.show();
    cout << '\n';
    
    for (int i = 0; i < howMany; i++)
    {
        t.increment();
        t.show();
        cout << '\n';
    }
    
}

void showTimers(const Timer& t1, const Timer& t2)
{
    cout << "t1 = ";
    t1.show();
    cout << "\n";
    
    cout << "t2 = ";
    t2.show();
    cout << "\n\n";
}
