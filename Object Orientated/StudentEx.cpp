//
//  main.cpp
//  StudentExample
//
//  Created by Gregory Moncayo on 5/3/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include "studentEx.h"

using namespace std;

Student:: Student(string first, string last)
{
    firstname = first;
    lastname = last;
    quiz1 = 0;
    quiz2 = 0;
    quiz3 = 0;
    test1 = 0;
    test2 = 0;
    finalGrade = 0;
}

bool Student:: SetQuizzes(int q1, int q2, int q3)
{
    if (q1 > 0 && q2 > 0 && q3 > 0)
    {
        quiz1 = q1;
        quiz2 = q2;
        quiz3 = q3;
        return true;
    }
    
    return false;
}


bool Student:: SetTests(int t1, int t2)
{
    if (t1 > 0 && t2 > 0)
    {
        test1 = t1;
        test2 = t2;
    }
    
    return false;
}


bool Student:: CalculateFinalGrade()
{
    if (test1 <= 0 && test2 <= 0)
    {
        return false;
    }
    
    if (quiz1 <= 0 && quiz2 <= 0 && quiz3 <= 0)
    {
        return false;
    }
    
    double testfinal = (test1*37.5)+(test2*37.5);
    double quizfinal = (quiz1*8.3)+(quiz2*8.3)+(quiz3*8.3);
    
    finalGrade = (testfinal+quizfinal)/100;
    
    return true;
    
}

string Student:: GetName()
{
    return firstname+' '+lastname;
}

double Student:: GetFinalGrade()
{
    return finalGrade;
}

void Student:: Display()
{
    cout << "Name: " << GetName() << endl;
    cout << "Grade: " << GetFinalGrade() << endl;
}

