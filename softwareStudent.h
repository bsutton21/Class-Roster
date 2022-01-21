#include <string>
#include "degree.h"
#include "student.h"
#pragma once

class SoftwareStudent : public Student
{

public:
    SoftwareStudent();
    SoftwareStudent(string ID, string first, string last, string email, int age, int* days, Degree degree);

    Degree GetDegreeProgram();
    void SetDegreeProgram(Degree degree);
    void print();

    ~SoftwareStudent(); // destructor

private:
    Degree degreeType;
};
