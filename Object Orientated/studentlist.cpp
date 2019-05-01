//
//  main.cpp
//  studentRecords
//
//  Created by Gregory Moncayo on 3/27/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <cctype>
#include "StudentList.h"

using namespace std;

// Student list class

StudentList:: StudentList()
{
    list = 0;
    size = 0;
}

// Destructor to clean up dynomically at the end.

StudentList:: ~StudentList()
{
    delete [] list;
}

// To read file and input it.

bool StudentList:: ImportFile(const char* filename)
{
    ifstream fin;
    string lastname, firstname, course;
    
    fin.open(filename);
    
    if (!fin)
    {
        return false;
    }
        fin >> size;
        
        list = new Student*[size];
    
        for (int i = 0; i < size; i++)
        {
            getline(fin, lastname, ',');
            getline(fin, firstname);
            
            fin >> course;
            
            if (course == "math" || course == "Math")
            {
                int quiz1, quiz2, quiz3, quiz4, quiz5, test, mid, exam;
                fin >> quiz1;
                fin >> quiz2;
                fin >> quiz3;
                fin >> quiz4;
                fin >> quiz5;
                fin >> test;
                fin >> mid;
                fin >> exam;
                
                Math stu = Math(quiz1, quiz2, quiz3, quiz4, quiz5, test, mid, exam, lastname, firstname, course);
                
                list[i] = &stu;
                
            }
        
        
        else if (course == "history" || course == "History")
        {
            int paper, mid, exam;
            fin >> paper;
            fin >> mid;
            fin >> exam;
            
            History hi = History(paper, mid, exam, lastname, firstname, course);
            
            list[i] = &hi;
        }
        
        else if (course == "english" || course == "English")
        {
            int show, project, mid, exam;
            fin >> show;
            fin >> project;
            fin >> mid;
            fin >> exam;
            
            English En = English(show, project, mid, exam, lastname, firstname, course);
            
            list[i] = &En;
        }
            
        }
   
    fin.close();
    
    return true;
}

// To read file and output it to a different .txt file.

bool StudentList:: CreateReportFile(const char* filename)
{
    ofstream fout;
    
    fout.open(filename);
    
    if (!fout)
    {
        return false;
    }

    if (!fout.eof())
    {
        fout << "Student's Grade Summary" << endl;
        fout << "-----------------------" << endl;
        fout << '\n';
        
        for (int i = 0; i < size; i++)
        {
            if (list[i]->ReturnSubject() == "Math" || list[i]->ReturnSubject() == "math")
            {
                fout << "MATH CLASS \n" << endl;
                fout << "Student                                   Final Final   Letter \n" << endl;
                fout << "Name                                      Exam  Avg     Grade \n" << endl;
                fout << "---------------------------------------------------------------------- \n" << endl;
                fout << list[i]->ReturnLast() << list[i]->ReturnFirst() << endl;
            }
        }
        
        for (int i = 0; i < size; i++)
        {
            if (list[i]->ReturnSubject() == "History" || list[i]->ReturnSubject() == "history")
            {
                fout << "HISTORY CLASS \n" << endl;
                fout << "Student                                   Final Final   Letter \n" << endl;
                fout << "Name                                      Exam  Avg     Grade \n" << endl;
                fout << "---------------------------------------------------------------------- \n" << endl;
                fout << list[i]->ReturnLast() << list[i]->ReturnFirst() << endl;
            }
        }
        
        for (int i = 0; i < size; i++)
        {
            if (list[i]->ReturnSubject() == "English" || list[i]->ReturnSubject() == "english")
            {
                fout << "ENGLISH CLASS \n" << endl;
                fout << "Student                                   Final Final   Letter \n" << endl;
                fout << "Name                                      Exam  Avg     Grade \n" << endl;
                fout << "---------------------------------------------------------------------- \n" << endl;
                fout << list[i]->ReturnLast() << list[i]->ReturnFirst() << endl;
            }
        }
        
    }
    
    fout.close();
    
    return true;
}

// Display Student's first name, last name, and what course they're in by doing this dynomically.

void StudentList:: ShowList() const
{
    cout << "First \t\t " << " Last \t\t " << " Course \t\t " << endl;
    cout << '\n';
    
    for (int i = 0; i < size; i++)
    {
        cout << list[i]->ReturnLast() << "\t\t" << setw(2) << list[i]->ReturnFirst() << "\t\t" << setw(2)
         << list[i]->ReturnSubject();
    }
    
    cout << endl;
    
}
// Student Class

Student:: Student(string lastname, string firstname, string course)     // Constructor
{
    last = lastname;
    first = firstname;
    subject = course;
}

// Virtual function since no definition will be needed since every class has a different weighed grade.

double Student:: Average()
{
    
    
    return 0;
}


// Virtual function

double Student:: ReturnFinal()
{
    return 0;
}

// Returns student's last name

string Student:: ReturnLast()
{
    return last;
}

// Returns student's first name

string Student:: ReturnFirst()
{
    return first;
}

// Return student's course

string Student:: ReturnSubject()
{
    return subject;
}

// History Class

// Constructor with student base class to share similiar data.
History :: History(double term, double mid, double exam, string lastname, string firstname, string course) : Student(lastname, firstname, course)
{
    paper = term;
    midterm = mid;
    fin = exam;
    
    last = lastname;
    first = firstname;
    subject = course;
}

// Calculates the average for the history class.

double History:: Average()
{
    return (fin*.04+paper+midterm/100);
}

// Returns final exam

double History:: ReturnFinal()
{
    return fin;
}

// Returns paper grade

double History:: ReturnPaper()
{
    return paper;
}

// Returns midterm

double History:: GetMidterm()
{
    return midterm;
}

// English Class

// Constructor to determine student, course, and final grade.
English:: English(double attend, double proj, double midterm, double exam, string lastname, string firstname, string course) : Student(lastname, firstname, course)
{
    attendance = attend;
    project = proj;
    mid = midterm;
    test = exam;
    
    last = lastname;
    first = firstname;
    subject = course;
    
}

// Returns student's English grade

double English:: Average()
{
    return ((attendance*.01+project*.03+mid*.03+test*.03)/100);
}

// Returns final

double English:: ReturnFinal()
{
    return test;
}

// Returns attendance grade.

double English:: GetAttend()
{
    return attendance;
}

// Returns project grade.

double English:: GetProject()
{
    return project;
}

// Returns Midterm grade.

double English:: GetMid()
{
    return mid;
}

// Math Class


Math:: Math(double one, double two, double three, double four, double five, double test1, double test2, double test3, string lastname, string firstname, string course) : Student(lastname, firstname, course)
{
    quiz = one;
    quiz2 = two;
    quiz3 = three;
    quiz4 = four;
    quiz5 = five;
    quizTotal = quiz+quiz2+quiz3+quiz4+quiz5;
    
    
    test = test1;
    midterm = test2;
    exam = test3;
    
    last = lastname;
    first = firstname;
    subject = course;
    
}

// Math grade for Student's who are attending.

double Math:: Average()
{
    return (quizTotal*.15+test*.25+midterm*.25+exam*.35)/100;
}

// Returns final

double Math:: ReturnFinal()
{
    return exam;
}

// Returns quiz total;

double Math:: ReturnQuizs()
{
    return quizTotal;
}

// Returns test 1

double Math:: ReturnTest()
{
    return test;
}

// Returns midterm grade

double Math:: ReturnMidterm()
{
    return midterm;
}
