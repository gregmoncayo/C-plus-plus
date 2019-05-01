#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

// Student Class

class Student
{
public:
    Student(string lastname, string firstname, string course);   // That reads lastname, firstname, & course from file.
    virtual double Average()=0;  // Compute and returns the average
    virtual double ReturnFinal()=0; // Return final Exam grade
    string ReturnLast();        // Returns last name of student
    string ReturnFirst();       // Returns first name of student
    string ReturnSubject();     // Returns course of student.
    
protected:
    string last;                // Protected member-data for other classes to use student's last name.
    string first;               // Protected member-data for derived classes to use student's first name.
    string subject;             // Protected member-data for child classes to user student's course.
private:
    
};

// StudentList class to help dynamically allocate data in certain memory of the computer.

class StudentList
{
public:
    StudentList();        // starts out empty
    ~StudentList();        // cleanup (destructor)
    
    bool ImportFile(const char* filename);          // reads file for file input.
    bool CreateReportFile(const char* filename);    // outputs data into a separate file.
    void ShowList() const;    // print basic list data.
    
private:
    Student ** list;            // Pointer to allocate Student information.
    int size;                  // variable to keep track of size of array & size of file.
    
};

// Class history (child class, parent class is student) where it inputs data used to input student's grade.

class History : public Student
{
    
public:
    // Constructor to help determine student, grade, and what class they are taking.
    History(double term, double mid, double exam, string lastname, string firstname, string course);
    double Average();   // Totals student's grade.
    double ReturnFinal(); // Returns final exam
    double ReturnPaper();  // Returns paper grade
    double GetMidterm();    // Returns midterm
    
private:
    double fin;             // final exam grade
    double paper;           // term paper grade
    double midterm;         // midterm grade
};

// English Class (derived class, student class is base class) where it inputs data used to input student's grade.

class English : public Student
{
public:
    
    // Constructor with parameters that are used to determined grade, name, lastname, course
    English(double attend, double proj, double midterm, double exam, string lastname, string firstname, string course);
    double Average();       // Student's english grade
    double ReturnFinal(); // Returns final
    double GetAttend(); // Returns attendance grade.
    double GetProject();    // Returns project grade.
    double GetMid();        // Returns Midterm grade.
    
private:
    double attendance;      // attendance grade
    double project;         // project grade
    double mid;             // midterm grade
    double test;            // final exam grade
};

// Math Class (derived class, student class is base class) where it inputs data used to input student's grade.

class Math : public Student
{
public:
    
    // Constructor to read data from input file & to extract it to output file.
    Math(double one, double two, double three, double four, double five, double test1, double test2, double test3, string lastname, string firstname, string course);
    double Average();           // Final math Grade
    double ReturnFinal(); // Returns final
    double ReturnQuizs(); // Returns quiz total;
    double ReturnTest(); // Returns test 1
    double ReturnMidterm(); // Returns midterm grade
    
private:
    double quiz;            // quiz 1 grade
    double quiz2;           // quiz 2 grade
    double quiz3;           // quiz 3 grade
    double quiz4;           // quiz 4 grade
    double quiz5;           // quiz 5 grade
    double quizTotal;       // Total quiz average
    double test;            // Test 1 grade
    double midterm;         // mid term grade
    double exam;            // final exam grade
};
