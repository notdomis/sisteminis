#include "Student.h"

Student::Student() : _first_name("undefined"), _last_name("undefined"), _Agg_homework(0.0f), _exam(0.0f), _final(0.0f) {}

Student::Student(const std::string &first_name, const std::string &last_name, float Agg_homework, float exam, float final) : _first_name(first_name), _last_name(last_name), _Agg_homework(Agg_homework), _exam(exam), _final(final) {}

Student::Student(const Student &other) : _first_name(other._first_name), _last_name(other._last_name), _Agg_homework(other._Agg_homework), _exam(other._exam), _final(other._final) {}

Student& Student::operator=(const Student &other) 
{
    Student copy(other); // will deal with memory deallocation if we had any in first place
    //swap this content with newly created copy - should be a function and is unneccessary for this class
    this->_first_name = copy._first_name;
    this->_last_name = copy._last_name;
    this->_Agg_homework = copy._Agg_homework;
    this->_exam = copy._exam;
    this->_final = copy._final;

    return *this;
}

Student::~Student()
{
    // we do not allocate any memory ourselves
}

void Student::populate(const size_t c_homework)
{
    std::cin >> this->_first_name >> this->_last_name;

    size_t c = c_homework;
    while (c)
    {
        float grade;
        std::cin >> grade;
        this->_Agg_homework += grade;
        --c;
    }
    std::cin >> this->_exam;
    this->_final = 0.4 * (this->_Agg_homework / c_homework) + 0.6 * this->_exam;
}

void Student::printToConsole(const size_t word_length) const
{
    std::cout << std::fixed
              << std::right
              << std::setw(word_length) << this->_first_name
              << " "
              << std::setw(word_length) << this->_last_name
              << " "
              << std::left
              << std::setw(word_length) << this->_final << '\n';
}