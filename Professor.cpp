#include "Professor.hpp"

#include <iomanip>
#include <iostream>

Professor::Professor(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, std::string salary) 
    : Person(name, surname, address, peselNumber, gender, salary)
{}

size_t Professor::getBorderSize() {
    return (6 + sizeNameLimit_ + sizeSurnameLimit_ + sizeAddressLimit_ + sizeSalaryLimit_ + sizePeselNumberLimit_ + sizeGenderLimit_);
}

void Professor::printBorderTop() {
    std::string temp = "STUDENTS DATABASE";
    std::cout << ' ' << std::setfill('-') << std::setw (static_cast<int>(getBorderSize())) << ' ' << "\n";
    std::cout << '|' << std::setfill(' ') << std::setw (static_cast<int>(getBorderSize() / 2 - temp.size() / 2 + temp.size())) 
              << temp << std::setw (static_cast<int>(getBorderSize() / 2 - temp.size() / 2 - temp.size() % 2)) << '|' << "\n";
    std::cout << ' ' << std::setfill('-') << std::setw (static_cast<int>(getBorderSize())) << ' ' << "\n";
    temp = "NAME";
    std::cout << std::setfill(' ') << '|' << std::setw(static_cast<int>(sizeNameLimit_ / 2 - temp.size() / 2 + temp.size())) 
              << temp << std::setw(static_cast<int>(sizeNameLimit_ / 2 - temp.size() / 2 + 1)); 
    temp = " SURNAME";
    std::cout << '|' << std::setw(static_cast<int>(sizeSurnameLimit_ / 2 - temp.size() / 2 + temp.size())) 
              << temp << std::setw(static_cast<int>(sizeSurnameLimit_ / 2 - temp.size() / 2 + 1)); 
    temp = " ADDRESS";
    std::cout << '|' << std::setw(static_cast<int>(sizeAddressLimit_ / 2 - temp.size() / 2 + temp.size())) 
              << temp << std::setw(static_cast<int>(sizeAddressLimit_ / 2 - temp.size() / 2 + 1)); 
    temp = " SALARY";
    std::cout << '|' << std::setw(static_cast<int>(sizeSalaryLimit_ / 2 - temp.size() / 2 + temp.size())) 
              << temp << std::setw(static_cast<int>(sizeSalaryLimit_ / 2 - temp.size() / 2 + 1)); 
    temp = " PESEL";
    std::cout << '|' << std::setw(static_cast<int>(sizePeselNumberLimit_ / 2 - temp.size() / 2 + temp.size())) 
              << temp << std::setw(static_cast<int>(sizePeselNumberLimit_ / 2 - temp.size() / 2 + 1)); 
    temp = "GENDER";
    std::cout << '|' << std::setw(static_cast<int>(sizeGenderLimit_ / 2 - temp.size() / 2 + temp.size())) 
              << temp << std::setw(static_cast<int>(sizeGenderLimit_ / 2 - temp.size() / 2 + 2)) << "|\n"; 
}

void Professor::printPerson() {
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