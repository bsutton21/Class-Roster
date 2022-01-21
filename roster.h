#include <string>
#include <iostream>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#pragma once

const string studentData[] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Blake,Sutton,bsutt23@wgu.edu,28,30,60,60,SOFTWARE"
};

class Roster
{

public:
    Roster(); //default contructor
    
    void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int day0, int day1, int day2, Degree degreeType);
    void Remove(string studentID);
    void PrintAll();
    void PrintDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(int degreeType);
    
    ~Roster(); //destructor

private:
    //Declare array of pointers
    Student *classRosterArray[5];
    int rosterSize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
    int index = 0;
};
