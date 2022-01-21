#include <string>
#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <vector>
#include <sstream>
using namespace std;


Roster::Roster()
{
    return;
}

// adding student info to the classRosterArray
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int day0, int day1, int day2, Degree degreeType)
{
    int daysInCourse[] = {day0, day1, day2};
    if (degreeType == NETWORKING) {
        classRosterArray[index] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeType);
    }
    if (degreeType == SECURITY) {
        classRosterArray[index] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeType);
    }
    if (degreeType == SOFTWARE) {
        classRosterArray[index] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeType);
    }
    index++;
    return;
}

// removing student info from classRosterArray
void Roster::Remove(string studentID)
{
    bool remove = false;

    for (int i = 0; i < rosterSize; ++i) {
        if (classRosterArray[i] != NULL && studentID == classRosterArray[i]->Student::GetStudentID()) {
            classRosterArray[i] = nullptr;
            remove = true;
            cout << "Student " << studentID << " has been removed from the list." << endl;
            break;
        }
    }
    if (!remove) {
        cout << "Invalid student ID. Student ID " << studentID << " does not exist." << endl;
    }
    return;
}

// printing formatted list of student data
void Roster::PrintAll()
{
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
    return;
}

// prints a student's average number of days in the three courses
void Roster::PrintDaysInCourse(string studentID)
{
    for (int i = 0; i < rosterSize; ++i) {
        if (classRosterArray[i]->Student::GetStudentID() == studentID) {
            int avg = (classRosterArray[i]->Student::GetDaysInCourse()[0] + classRosterArray[i]->Student::GetDaysInCourse()[1] + classRosterArray[i]->Student::GetDaysInCourse()[2]) / 3;
            cout << "Average days in the three courses: " << avg << endl;
        }
    }
    return;
}

// verifies student email address and displays all invalid email address to the user
void Roster::PrintInvalidEmails()
{
    for (int i = 0; i < rosterSize; ++i) {
        string email = classRosterArray[i]->Student::GetEmailAddress();
        if ((email.find("@") == string::npos) || (email.find(".") == string::npos) || (email.find(" ") != string::npos)) {
            cout << "Invalid email address: " << email << endl;
        }
    }
    return;
}

// prints out student information for a degree program specifid by an enum type
void Roster::PrintByDegreeProgram(int degreeType)
{
    for (int i = 0; i < rosterSize; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeType) {
            classRosterArray[i]->print();
            cout << endl;
        }
    }
    return;
}

// main portion of program - demostrates the program's required functionality
int main() 
{
    // Creating the instance of the Roster class called classRoster
    Roster classRoster;
    Degree degree;
    cout << "*------------------------ STUDENT INFO -------------------------*" << endl;
    cout << "* Course title: C867 - Scripting and Programming - Applications *" << endl;
    cout << "* Language used: C++                                            *" << endl;
    cout << "* Student ID: 001109490                                         *" << endl;
    cout << "* Name: Blake Sutton                                            *" << endl;
    cout << "*---------------------------------------------------------------*" << endl;

    int studentDataSize = sizeof(studentData) / sizeof(studentData[0]); // populating the array
    for (int i = 0; i < studentDataSize; ++i) {
        stringstream ss(studentData[i]);
        vector<string> studentVector;

        while (ss.good()) {
            string studentSubString;
            getline(ss, studentSubString, ',');
            studentVector.push_back(studentSubString);
        }

        // set degree type
        if (studentVector.at(8) == "SECURITY") {
            degree = Degree::SECURITY;
        }
        if (studentVector.at(8) == "NETWORKING") {
            degree = Degree::NETWORKING;
        }
        if (studentVector.at(8) == "SOFTWARE") {
            degree = Degree::SOFTWARE;
        }

        // Add vector data to class roster object
        classRoster.Add(studentVector.at(0), studentVector.at(1), studentVector.at(2), studentVector.at(3), stoi(studentVector.at(4)), 
        stoi(studentVector.at(5)), stoi(studentVector.at(6)), stoi(studentVector.at(7)), degree);
    }
    cout << endl;

    cout << "Printing the full student roster:" << endl; // PrintAll() function
    classRoster.PrintAll();
    cout << endl;

    cout << "Finding and printing invalid email addresses:" << endl; // PrintInvalidEmails() function
    classRoster.PrintInvalidEmails();
    cout << endl;

    cout << "Printing average days in courses:" << endl; // PrintDaysInCourse function
    //loop through classRosterArray and for each element:
    for (int i = 1; i <= 5; ++i) {
        string tempID = "A" + to_string(i);
        cout << "Student " << tempID << "--> ";
        classRoster.PrintDaysInCourse(tempID);
    }
    cout << endl;

    cout << "Printing students in the SOFTWARE program: " << endl;
    classRoster.PrintByDegreeProgram(SOFTWARE); // PrintByDegreeProgram function

    cout << "Removing data with Student ID A3" << endl; // Remove() function
    classRoster.Remove("A3");
    cout << endl;

    cout << "Testing that it only removes student A3" << endl;
    classRoster.PrintAll();

    cout << "Attempting to remove student info for Student ID A3:" << endl; // second (invalid) Remove() function
    classRoster.Remove("A3");
    cout << endl;

    classRoster.~Roster();

    return 0;
}

// destructor to release roster memory
Roster::~Roster()
{
    for (int i = 0; i < rosterSize; ++i) {
        delete this->classRosterArray[i];
    }
}