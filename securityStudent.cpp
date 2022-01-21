#include <iostream>
#include "securityStudent.h"
using namespace std;

Degree SecurityStudent::GetDegreeProgram()
{
    return SECURITY;
}

SecurityStudent::SecurityStudent(string ID, string first, string last, string email, int age, int* days, Degree degree) : Student::Student(ID, first, last, email, age, days)
{
    this->SetDegreeProgram(SECURITY);
    return;
}

void SecurityStudent::SetDegreeProgram(Degree degree)
{
    this->degreeType = degree;
    return;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "Degree Program: SECURITY" << endl;
	return;
}
