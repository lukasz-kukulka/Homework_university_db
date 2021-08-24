#include "Student.hpp"

#include <iomanip>
#include <iostream>

Student::Student(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, std::string indexNumber) 
    : Person(name, surname, address, peselNumber, gender)
    , indexNumber_(indexNumber)
{}

// size_t Student::getBorderSize() {
//     return (8 + sizeNameLimit_ + sizeSurnameLimit_ + sizeAddressLimit_ + sizeIndexNumberLimit_ + sizePeselNumberLimit_ + sizeGenderLimit_ + sa);
// }

// void Student::printBorderTop() {

// }

void Student::printPerson() {
    std::cout << ' ' << std::setfill('-') << std::setw (static_cast<int>(getBorderSize())) <<  ' ' << '\n';
    std::cout << std::setfill(' ') << '|' << std::setw(static_cast<int>(sizeNameLimit_ / 2 - name_.size() / 2 + name_.size()))
              << name_ << std::setw(static_cast<int>(sizeNameLimit_ / 2 - name_.size() / 2 + 1 - name_.size() % 2)) 
              << '|' << std::setw(static_cast<int>(sizeSurnameLimit_ / 2 - surname_.size() / 2 + surname_.size())) 
              << surname_ << std::setw(static_cast<int>(sizeSurnameLimit_ / 2 - surname_.size() / 2 + 1 - surname_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizeAddressLimit_ / 2 - address_.size() / 2 + address_.size()))
              << address_ << std::setw(static_cast<int>(sizeAddressLimit_ / 2 - address_.size() / 2 + 1  - address_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizeIndexNumberLimit_ / 2 - indexNumber_.size() / 2 + indexNumber_.size()))
              << salary_ << std::setw(static_cast<int>(sizeSalaryLimit_ / 2 - salary_.size() / 2 + 1 - salary_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizePeselNumberLimit_ / 2 - peselNumber_.size() / 2 + peselNumber_.size()))
              << indexNumber_ << std::setw(static_cast<int>(sizeIndexNumberLimit_ / 2 - indexNumber_.size() / 2 + 1 - indexNumber_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizePeselNumberLimit_ / 2 - peselNumber_.size() / 2 + peselNumber_.size()))
              << peselNumber_ << std::setw(static_cast<int>(sizePeselNumberLimit_ / 2 - peselNumber_.size() / 2 + 1 - peselNumber_.size() % 2))
              << '|' << std::setw(static_cast<int>(sizeGenderLimit_ / 2 - convertPersonGender(gender_).size() / 2 + convertPersonGender(gender_).size() % 2 + convertPersonGender(gender_).size()))
              << convertPersonGender(gender_) << std::setw(static_cast<int>(sizeGenderLimit_ / 2 - convertPersonGender(gender_).size() / 2 + 2)) << "|\n";
}

// void Student::printBorderBotton() {
//     std::cout << ' ' << std::setfill('-') << std::setw (static_cast<int>(getBorderSize())) << ' ' << "\n\n";
// }