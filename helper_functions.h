#ifndef GUARD_helper_functions_h
#define GUARD_helper_functions_h
#include "student.h"
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdexcept>

namespace hf
{
    extern void populateFromFile(std::vector<Student> &, const std::string &);
    extern void print(const std::vector<Student>&, const size_t);
}

#endif