#include <string>
#include "degree.h"
#include "student.h"
#pragma once

class SecurityStudent : public Student
{

public:
    SecurityStudent();
    SecurityStudent(string ID, string first, string last, string email, int age, int* days, Degree degree);

    Degree GetDegreeProgram();
    void SetDegreeProgram(Degree degree);
    void print();

    ~SecurityStudent(); // destructor

private:
    Degree degreeType;
};
