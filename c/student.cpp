#include "Student.h"

Student::Student() : _first_name("undefined"), _last_name("undefined"), _homework(new int[1]), _exam(0.0f), _final(0.0f) {}

Student::Student(const std::string &first_name, const std::string &last_name, int *homework, int exam, float final) : _first_name(first_name), _last_name(last_name), _exam(exam), _final(final)
{
    size_t n = sizeof(homework) / sizeof(int);
    delete[] this->_homework;
    this->_homework = new int[n];
    std::copy(homework, homework + n, this->_homework);
}

Student::Student(const Student &other) : _first_name(other._first_name), _last_name(other._last_name), _exam(other._exam), _final(other._final)
{
    size_t n = sizeof(other._homework) / sizeof(int);
    delete[] this->_homework;
    this->_homework = new int[n];
    std::copy(other._homework, other._homework + n, this->_homework);
}

Student &Student::operator=(const Student &other)
{
    Student copy(other);
    this->_first_name = copy._first_name;
    this->_last_name = copy._last_name;
    this->_exam = copy._exam;
    this->_final = copy._final;

    //swap with newly created copy and let its deconstructor take care of deallocation - should be a function
    size_t n = sizeof(copy._homework) / sizeof(int);
    delete[] this->_homework;
    this->_homework = new int[n];
    std::copy(copy._homework, copy._homework + n, this->_homework);

    return *this;
}

Student::~Student()
{
    delete[] this->_homework;
}

void Student::populate()
{
    std::cin >> this->_first_name >> this->_last_name;

    int grade;
    int read = 0;
    size_t n = sizeof(this->_homework) / sizeof(int);
    while (std::cin >> grade)
    {
        if(read == n)
        {
            int* buffer = new int[n];
            std::copy(this->_homework, this->_homework+ n, buffer);
            delete[] this->_homework;
            this->_homework = new int[n*2];
            std::copy(buffer, buffer+ n, this->_homework);
            delete[] buffer;
            n *= 2;
        }

        this->_homework[read++] = grade;
    }
    this->_exam = this->_homework[read - 1];

    float sum = 0.0f;
    int nn = read - 1;
    while(--nn > -1) {
        sum += this->_homework[nn];
    }
    this->_final = 0.4 * sum / (float)(read - 1) + 0.6 * this->_exam;
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