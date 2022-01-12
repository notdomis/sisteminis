#include "helper_functions.h"

namespace hf
{
    void generateSampleFile(int size, const std::string &path)
    {
        std::ofstream os(path);
        std::srand(std::time(0));
        std::cout << size << std::endl;
        while (--size >= 0)
        {
            os << "Name" << size << " Surname" << size
               << " " << rand() % 10 + 1
               << " " << rand() % 10 + 1
               << " " << rand() % 10 + 1
               << " " << rand() % 10 + 1
               << " " << rand() % 10 + 1
               << " " << rand() % 10 + 1
               << '\n';
        }
    }

    void optimizedPartition(std::vector<Student> &students, std::vector<Student> &students_good, std::vector<Student> &students_bad)
    {
        auto it = std::partition(students.begin(), students.end(), [](const Student &s) {return s.isGood();});

        std::copy(students.begin(), it, std::back_inserter(students_good));
        std::copy(it, students.end(), std::back_inserter(students_bad));
    }
}