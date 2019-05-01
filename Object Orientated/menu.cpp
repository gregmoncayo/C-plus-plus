//
//  menu.cpp
//  studentRecords
//
//  Created by Gregory Moncayo on 4/2/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "StudentList.h"
using namespace std;
void Menu();

int main()
{
    char choice, fout[30];                  // variable to store the menu choice & character array for file I/O.
    StudentList s;                          // object of StudentList that can direct certain functions.
    ifstream file;                          // for file input.
    ofstream file2;                         // for file output.
    
    // Displays main menu for user entry.
    
    Menu();
    
    do
    {
        cout <<     " > ";
        cin >> choice;
        
        
        // grabs user choice and does what was asked.
        
        switch (choice)
        {
            case 'i':
            case 'I':
                
                // For file input.
                
                cout << " Enter file name: ";
                cin >> fout;
                
                file.open(fout);
                
                // Error message.
                
                if (!file)
                {
                    cout << "Invalid file. No data imported" << endl;
                }
                
                else
                {
                    s.ImportFile(fout); // object S calls function for file input.
                }
                
                break;
            case 's':
            case 'S':
                
                // Displays what was read in from the File.
                
                s.ShowList();
                break;
            case 'e':
            case 'E':
                
                // For file output.
                
                cout << " Enter file name: ";
                cin >> fout;
                
                file2.open(fout);
                
                // Error message.
                
                if (!file2)
                {
                    cout << "Invalid file. No data imported" << endl;
                }
                
                // object s calls function for file output.
                
                else
                {
                    s.CreateReportFile(fout);
                }
                
                break;
            case 'm':
            case 'M':
                
                // Displays menu for user entry.
                
                Menu();
                break;
                
            default:
                break;
        }
    }
    while (choice != 'q' && 'Q');
    
    cout << "Goodbye!" << endl;
    
    return 0;
    
}

// Main menu for user display.

void Menu()
{
    cout <<     "         *** Student List menu ***" << endl;
    
    cout <<     " I       Import students from a file " << endl;
    cout <<     " S       Show student list (brief) " << endl;
    cout <<     " E       Export a grade report (to file) " << endl;
    cout <<     " M       Show this Menu" << endl;
    cout <<     " Q       Quit Program " << endl;
}
