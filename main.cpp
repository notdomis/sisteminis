#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <deque>
#include <list>

#include "student.h"
#include "helper_functions.h"


int main()
{
    std::cout.precision(2);

    std::vector<Student> students, students_good, students_bad;
    //hf::generateSampleFile(100000, "./input.txt");
    hf::populateFromFile(students, "./input.txt");
    hf::memoryPartition(students, students_good, students_bad);
    
    // sort before printing - vector deque
    std::sort(students_good.begin(), students_good.end()); 
    std::sort(students_bad.begin(), students_bad.end()); 
    // sort before printing - list
    //students_good.sort(); 
    //students_bad.sort();

    std::ofstream os_good("./good_students.txt");
    std::ofstream os_bad("./bad_students.txt");
    os_good.precision(2);
    os_bad.precision(2);

    hf::write(os_good, students_good, 25);
    hf::write(os_bad, students_bad, 25);

    return 0;
}