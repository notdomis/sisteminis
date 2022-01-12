#include <iostream>
#include "Student.h"

int main()
{
    std::cout.precision(2);

    Student student;
    student.populate(false, true);
    student.printToConsole(25);

    return 0;
}