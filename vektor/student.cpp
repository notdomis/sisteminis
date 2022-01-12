#include "Student.h"

Student::Student() : _first_name("undefined"), _last_name("undefined"), _exam(0.0f), _final(0.0f) {}

Student::Student(const std::string &first_name, const std::string &last_name, std::vector<int> homework, int exam, float final) : _first_name(first_name), _last_name(last_name), _homework(homework), _exam(exam), _final(final) {}

Student::Student(const Student &other) : _first_name(other._first_name), _last_name(other._last_name), _homework(other._homework), _exam(other._exam), _final(other._final) {}

Student& Student::operator=(const Student &other) 
{
    Student copy(other); // will deal with memory deallocation if we had any in first place
    //swap this content with newly created copy - should be a function and is unneccessary for this class
    this->_first_name = copy._first_name;
    this->_last_name = copy._last_name;
    this->_homework = copy._homework;
    this->_exam = copy._exam;
    this->_final = copy._final;

    return *this;
}

Student::~Student()
{
    // we do not allocate any memory ourselves
}

void Student::populate(const bool use_median, const bool random)
{
    std::cin >> this->_first_name >> this->_last_name;

    if(!random)
    {
        int grade;
        // use EOF symbol to end input
        while (std::cin >> grade)
        {
            this->_homework.push_back(grade);
        }
        this->_exam = this->_homework.back();
        this->_homework.pop_back();
    }
    else
    {
        std::srand(std::time(0));

        int grades = rand() % 10 + 2;
        while(--grades)
        {
             this->_homework.push_back(rand() % 10 + 1);
        } 
        this->_exam = rand() % 10 + 1;
    }

    if(!this->_homework.empty()) // avoid division by zero
    {
        auto const count = static_cast<float>(this->_homework.size());
        if(use_median)
        {
            size_t n = count / 2;
            std::nth_element(this->_homework.begin(), this->_homework.begin()+n, this->_homework.end());
            this->_final = 0.4f * this->_homework[n] + 0.6f * this->_exam;
        } 
        else
        {
            float sum = std::accumulate(this->_homework.begin(), this->_homework.end(), 0.0f);
            this->_final = 0.4f * sum / count + 0.6f * this->_exam;
        }
    }
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