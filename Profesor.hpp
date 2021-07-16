#pragma once

#include <string>

#include "Person.hpp"

class Profesor : public Person{
public:
    Profesor() = default;
    Profesor(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, size_t salary);
    ~Profesor(){};

    size_t getSalary() const { return salary_; }

    size_t getSizeSalaryLimit() const { return sizeSalaryLimit_; }

private:
    std::string convertStudentGender(const Gender);

    size_t salary_ { 1000 };
    size_t sizeSalaryLimit_ { 6 };
};