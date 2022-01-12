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
    template <typename T>
    void populateFromFile(T &d, const std::string &path)
    {
        std::string line;
        try
        {
            std::ifstream is(path);
            if (is.fail())
            {
                throw std::invalid_argument("received nonexisting file path!");
            }

            int i = 0;
            while (!is.eof())
            {
                Student stud;
                stud.populate(is);
                d.push_back(stud);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    template <typename T>
    void memoryPartition(const T &students, T &students_good, T &students_bad)
    {
        for (const auto &student : students)
        {
            if (student.isGood())
            {
                students_good.push_back(student);
            }
            else
            {
                students_bad.push_back(student);
            }
        }
    }

    template <typename T>
    void deletionPartition(T &students_good, T &students_bad)
    {
        typename T::iterator it = students_good.begin();
        while (it != students_good.end())
        {
            if (!(*it).isGood())
            {
                students_bad.push_back(*it);
                students_good.erase(it++);
            }
            else
            {
                ++it;
            }
        }
    }

    template <typename T>
    std::ostream &write(std::ostream &os, const T &students, const size_t field_length)
    {
        os << std::left
           << std::setw(field_length)
           << "Vardas"
           << std::setw(field_length)
           << "Pavarde"
           << std::setw(field_length)
           << std::right
           << "Galutinis" << '\n'
           << std::string(field_length * 3, '-') << '\n';

        for (const auto &student : students)
        {
            student.write(os, field_length);
        }
        return os;
    }

    extern void generateSampleFile(int, const std::string &);
    extern void optimizedPartition(std::vector<Student> &, std::vector<Student> &, std::vector<Student> &);
}

#endif