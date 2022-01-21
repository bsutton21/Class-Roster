#include <string>
#include "degree.h"
#include "student.h"
#pragma once
using namespace std;

class NetworkStudent : public Student
{

public:
    NetworkStudent();
    NetworkStudent(string ID, string first, string last, string email, int age, int* days, Degree degree);

    Degree GetDegreeProgram();
    void SetDegreeProgram(Degree degree);
    void print();

    ~NetworkStudent(); // destructor

private:
    Degree degreeType;
};
