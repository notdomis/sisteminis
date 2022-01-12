#include "helper_functions.h"

namespace hf
{   
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
}