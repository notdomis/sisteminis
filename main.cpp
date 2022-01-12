#include <iostream>
#include <ios>

#include "Student.h"

int main()
{
    std::cout.precision(2);

    Student student;
    student.populate(3);
    student.printToConsole(25);

    return 0;
}