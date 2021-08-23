#pragma once

#include <string>

#include "Person.hpp"

class Professor : public Person{
public:
    Professor() = default;
    Professor(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, std::string salary);
    ~Professor(){};

    std::string getSalary() const override { return salary_; }
    size_t getSizeSalaryLimit() const { return sizeSalaryLimit_; }

    void printBorderTop() override;
    void printPerson() override;
    void printBorderBotton() override;
    size_t getBorderSize() override;

private:
    std::string salary_ {};
};