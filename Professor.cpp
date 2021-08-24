#include "Professor.hpp"

#include <iomanip>
#include <iostream>

Professor::Professor(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, std::string salary) 
    : Person(name, surname, address, peselNumber, gender)
    , salary_(salary)
{}

size_t Professor::getBorderSize() {
    return (6 + sizeNameLimit_ + sizeSurnameLimit_ + sizeAddressLimit_ + sizeSalaryLimit_ + sizePeselNumberLimit_ + sizeGenderLimit_);
}

// void Professor::printBorderTop() {
//     //std::cout << generateCell("NAME", 30) << "|" << generateCell("SURNAME", 30)
// }

void Professor::printPerson() {
    Person::printBorderTop();
    std::cout << ' ' << std::setfill('-') << std::setw (static_cast<int>(getBorderSize())) <<  ' ' << '\n';
    std::cout << std::setfill(' ') << '|' << std::setw(static_cast<int>(sizeNameLimit_ / 2 - name_.size() / 2 + name_.size()))
              << name_ << std::setw(static_cast<int>(sizeNameLimit_ / 2 - name_.size() / 2 + 1 - name_.size() % 2)) 
              << '|' << std::setw(static_cast<int>(sizeSurnameLimit_ / 2 - surname_.size() / 2 + surname_.size())) 
              << surname_ << std::setw(static_cast<int>(sizeSurnameLimit_ / 2 - surname_.size() / 2 + 1 - surname_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizeAddressLimit_ / 2 - address_.size() / 2 + address_.size()))
              << address_ << std::setw(static_cast<int>(sizeAddressLimit_ / 2 - address_.size() / 2 + 1  - address_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizeSalaryLimit_ / 2 - salary_.size() / 2 + salary_.size()))
              << salary_ << std::setw(static_cast<int>(sizeSalaryLimit_ / 2 - salary_.size() / 2 + 1 - salary_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizePeselNumberLimit_ / 2 - peselNumber_.size() / 2 + peselNumber_.size()))
              << indexNumber_ << std::setw(static_cast<int>(sizeSalaryLimit_ / 2 - salary_.size() / 2 + 1 - salary_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizePeselNumberLimit_ / 2 - peselNumber_.size() / 2 + peselNumber_.size()))
              << peselNumber_ << std::setw(static_cast<int>(sizePeselNumberLimit_ / 2 - peselNumber_.size() / 2 + 1 - peselNumber_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizeGenderLimit_ / 2 - convertPersonGender(gender_).size() / 2 + convertPersonGender(gender_).size() % 2 + convertPersonGender(gender_).size()))
              << convertPersonGender(gender_) << std::setw(static_cast<int>(sizeGenderLimit_ / 2 - convertPersonGender(gender_).size() / 2 + 2)) << "|\n";
}

void Professor::printBorderBotton() {
    std::cout << ' ' << std::setfill('-') << std::setw (static_cast<int>(getBorderSize())) << ' ' << "\n\n";
}