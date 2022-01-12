#include "helper_functions.h"

namespace hf
{
    void populateFromFile(std::vector<Student> &d, const std::string &path)
    {
        std::string line;
        try
        {
            std::ifstream is(path);
            if(is.fail()){
                throw std::invalid_argument( "received nonexisting file path!");
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
    
    std::ostream& write(std::ostream& os, const std::vector<Student> &students, const size_t field_length)
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

    void generateSampleFile(int size, const std::string & path)
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

    void sort(const std::vector<Student>& students, std::vector<Student>& students_good, std::vector<Student>& students_bad)
    {
        for (const auto &student : students)
        {
            if(student.isGood())
            {
                students_good.push_back(student);
            }
            else
            {
                students_bad.push_back(student);
            }
        }
    }
}