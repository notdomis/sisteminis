#ifndef GUARD_Student_h
#define GUARD_Student_h
#include <string>
#include <iostream>
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
    Student(const Student &);                    // 1/3: Copy Ctor
    Student &operator=(const Student &);         // 2/3: Copy Assignment
    ~Student();                                  // 3/3: Dtor

    void populate(const bool, const bool);       // input
    void printToConsole(const size_t) const;     // output
};
#endif