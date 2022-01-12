#ifndef GUARD_student_h
#define GUARD_student_h
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

class Student
{
private:
    std::string _first_name;
    std::string _last_name;
    std::vector<int> _homework;
    int _exam;
    float _final;

public:
    Student();
    Student(const std::string &, const std::string &, std::vector<int>, int, float);
    Student(const Student &);                                             // 1/3: Copy Ctor
    Student &operator=(const Student &);                                  // 2/3: Copy Assignment
    ~Student();                                                           // 3/3: Dtor

    std::istream& populate(std::istream&, const bool = false, const bool = false);       // input
    void printToConsole(const size_t) const;                                             // output

    bool operator < (const Student&) const;                                              // sorting
};
#endif