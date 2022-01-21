#include <iostream>
#include "student.h"
#include <iomanip>
using namespace std;

Student::Student()
{

}

Student::Student(string ID, string first, string last, string email, int age, int* days)
{
    this->studentID = ID;
    this->firstName = first;
    this->lastName = last;
    this->emailAddress = email;
    this->age = age;
    this->days[0] = days[0];
    this->days[1] = days[1];
    this->days[2] = days[2];
}

// accessors / "getters":

string Student::GetStudentID()
{
    return studentID;
}

string Student::GetFirstName()
{
    return firstName;
}

string Student::GetLastName()
{
    return lastName;
}

string Student::GetEmailAddress()
{
    return emailAddress;
}

int Student::GetAge()
{
    return age;
}

int* Student::GetDaysInCourse()
{
    return this->days;
}

// mutators / "setters": 

void Student::SetStudentID(string ID)
{
    this->studentID = ID;
    return;
}

void Student::SetFirstName(string first)
{
    this->firstName = first;
    return;
}

void Student::SetLastName(string last)
{
    this->lastName = last;
    return;
}

void Student::SetEmailAddress(string email)
{
    this->emailAddress = email;
    return;
}

void Student::SetAge(int age)
{
    this->age = age;
    return;
}

void Student::SetDaysInCourse(int day0, int day1, int day2)
{
    this->days[0] = day0;
    this->days[1] = day1;
    this->days[2] = day2;
    return;
}

void Student::print() // prints all but the degree type which prints in the corresponding student subsets
{
    cout << left << GetStudentID() << "\t";
    cout << left << "First Name: " << GetFirstName() << "\t";
    cout << left << "Last Name: " << GetLastName() << "\t";
    cout << left << "Age: " << GetAge() << "\t";
    cout << left << "daysInCourse: " << "{" << GetDaysInCourse()[0] << ", " << GetDaysInCourse()[1] << ", " << GetDaysInCourse()[2] << "} ";
    return;
}

Student::~Student()
{
    // deliberately empty
}
