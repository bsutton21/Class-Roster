#include <iostream>
#include <string>
#include "networkStudent.h"
using namespace std;

Degree NetworkStudent::GetDegreeProgram()
{
    return NETWORKING;
}

NetworkStudent::NetworkStudent(string ID, string first, string last, string email, int age, int* days, Degree degree) : Student::Student(ID, first, last, email, age, days)
{
    this->SetDegreeProgram(NETWORKING);
    return;
}

void NetworkStudent::SetDegreeProgram(Degree degree)
{
    this->degreeType = degree;
    return;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "Degree Program: NETWORKING" << endl;
	return;
}
