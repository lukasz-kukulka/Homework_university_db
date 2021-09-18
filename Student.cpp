#include "Student.hpp"

#include <iomanip>
#include <iostream>

Student::Student(std::string name, std::string surname, std::string address, std::string peselNumber, char gender, std::string indexNumber) 
    : Person(name, surname, address, peselNumber, gender)
    , indexNumber_(indexNumber)
{}

// size_t Student::getBorderSize() {
//     return (8 + sizeNameLimit_ + sizeSurnameLimit_ + sizeAddressLimit_ + sizeIndexNumberLimit_ + sizePeselNumberLimit_ + sizeGenderLimit_ + sa);
// }

// void Student::printBorderTop() {

// }

void Student::printPerson() {
        std::cout << "|" << generateCell(name_, sizeNameLimit_) << "|" 
              << generateCell(surname_, sizeSurnameLimit_) << "|" 
              << generateCell(address_, sizeAddressLimit_) << "|" 
              << generateCell(peselNumber_, sizePeselNumberLimit_) << "|" 
              << generateCell(salary_, sizeSalaryLimit_) << "|" 
              << generateCell(indexNumber_, sizeIndexNumberLimit_) << "|" 
              << generateCell(convertPersonGender(gender_), sizeGenderLimit_) << "|\n";
}

// void Student::printBorderBotton() {
//     std::cout << ' ' << std::setfill('-') << std::setw (static_cast<int>(getBorderSize())) << ' ' << "\n\n";
// }