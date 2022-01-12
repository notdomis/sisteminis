#include "Student.h"

Student::Student() : _first_name("undefined"), _last_name("undefined"), _exam(0.0f), _final(0.0f) {}

Student::Student(const std::string &first_name, const std::string &last_name, std::vector<int> homework, int exam, float final) : _first_name(first_name), _last_name(last_name), _homework(homework), _exam(exam), _final(final) {}

Student::Student(const Student &other) : _first_name(other._first_name), _last_name(other._last_name), _homework(other._homework), _exam(other._exam), _final(other._final) {}

Student &Student::operator=(const Student &other)
{
    this->_first_name = other._first_name;
    this->_last_name = other._last_name;
    this->_homework = other._homework;
    this->_exam = other._exam;
    this->_final = other._final;

    return *this;
}

Student::~Student()
{
    // we do not allocate any memory ourselves
}

std::istream &Student::populate(std::istream &is, const bool use_median)
{
    is >> this->_first_name >> this->_last_name;
    int grades = 5 + 1;
    int grade;

    while (--grades)
    {
        is >> grade;
        this->_homework.push_back(grade);
    }
    is >> this->_exam;

    if (!this->_homework.empty()) // avoid division by zero
    {
        auto const count = static_cast<float>(this->_homework.size());
        if (use_median)
        {
            size_t n = count / 2;
            std::nth_element(this->_homework.begin(), this->_homework.begin() + n, this->_homework.end());
            this->_final = 0.4f * this->_homework[n] + 0.6f * this->_exam;
        }
        else
        {
            float sum = std::accumulate(this->_homework.begin(), this->_homework.end(), 0.0f);
            this->_final = 0.4f * sum / count + 0.6f * this->_exam;
        }
    }

    return is;
}

std::ostream& Student::write(std::ostream& os, const size_t field_length) const
{
    os << std::fixed
        << std::left
        << std::setw(field_length)
        << this->_first_name
        << std::setw(field_length)
        << this->_last_name
        << std::right
        << std::setw(field_length) << this->_final << '\n';
    return os;
}

bool Student::operator<(const Student &other) const
{
    return this->_first_name < other._first_name;
}

bool Student::isGood() const
{
    return this->_final >= 5;
}