#include <iostream>
#include <vector>

#include "student.h"
#include "helper_functions.h"

int main()
{
    std::cout.precision(2);

    std::vector<Student> students;
    hf::populateFromFile(students, "./input.txt");
    std::sort(students.begin(), students.end()); // sort before pirnting
    hf::print(students, 15);

    return 0;
}