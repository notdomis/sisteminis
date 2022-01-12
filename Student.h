#ifndef GUARD_Student_h
#define GUARD_Student_h
#include <string>
#include <iostream>
#include <iomanip>

class Student
{
private:
    std::string _first_name;
    std::string _last_name;
    float _Agg_homework;
    float _exam;
    float _final;

public:
    Student();
    Student(const std::string &, const std::string &, float, float, float);
    Student(const Student &);                    // 1/3: Copy Ctor
    Student &operator=(const Student &);         // 2/3: Copy Assignment
    ~Student();                                  // 3/3: Dtor

    void populate(const size_t);                 // input
    void printToConsole(const size_t) const;     // output
};
#endif