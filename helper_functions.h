#ifndef GUARD_helper_functions_h
#define GUARD_helper_functions_h
#include "student.h"
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

namespace hf
{
    extern void populateFromFile(std::vector<Student> &, const std::string &);
    extern void generateSampleFile(int, const std::string &);
    extern void sort(const std::vector<Student>&, std::vector<Student>&, std::vector<Student>&);
    extern std::ostream& write(std::ostream&, const std::vector<Student>&, const size_t);
}

#endif