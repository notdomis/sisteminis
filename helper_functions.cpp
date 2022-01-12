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

    void print(const std::vector<Student> &students, const size_t field_length)
    {
        std::cout << std::left
                  << std::setw(field_length)
                  << "Vardas"
                  << std::setw(field_length)
                  << "Pavarde"
                  << std::setw(field_length)
                  << std::right
                  << "Galutinis" << '\n';
        std::cout << std::string('-', field_length * 3) << '\n';

        for (const auto &student : students)
        {
            student.printToConsole(field_length);
        }
    }
}