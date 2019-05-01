#include <iostream>

using namespace std;

class Student {
public:
    Student(string first, string last);
    bool SetQuizzes(int q1, int q2, int q3);
    bool SetTests(int t1, int t2);
    bool CalculateFinalGrade();
    
    string GetName();
    double GetFinalGrade();
    void Display();
    
private:
    string firstname, lastname;
    int quiz1, quiz2, quiz3;
    int test1, test2;
    double finalGrade;
};
