#include <iostream>
#include "softwareStudent.h"
using namespace std;

Degree SoftwareStudent::GetDegreeProgram()
{
    return SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string ID, string first, string last, string email, int age, int* days, Degree degree) : Student::Student(ID, first, last, email, age, days)
{
    this->SetDegreeProgram(SOFTWARE);
    return;
}

void SoftwareStudent::SetDegreeProgram(Degree degree)
{
    this->degreeType = degree;
    return;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "Degree Program: SOFTWARE" << endl;
	return;
}
