#include <string>
#include "degree.h"
using std::string;
#pragma once

class Student
{
public:
    Student();
    Student(string ID, string first, string last, string email, int age, int* days);

    const static int daysArraySize = 3; // sets max size of array for days in course

    string GetStudentID();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddress();
    int GetAge(); 
    int* GetDaysInCourse();
    virtual Degree GetDegreeProgram() = 0; // virtual getDegreeProgram

    void SetStudentID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysInCourse(int day0, int day1, int day2);
    virtual void SetDegreeProgram(Degree degree) = 0; // virtual SetDegreeProgram, later defined in Student, as well as SecurityStudent, NetworkStudent, and SoftwareStudent

    virtual void print() = 0; // virtual print() to print student data

    ~Student(); // destructor

protected:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int day0;
    int day1;
    int day2;
    int days[3];
    Degree type; // from the enumerated value in degree.h
};
