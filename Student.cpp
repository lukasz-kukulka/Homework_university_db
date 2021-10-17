#include "Student.hpp"

#include <iomanip>
#include <iostream>

Student::Student(std::string name, std::string surname, std::string address, std::string peselNumber, std::string gender, std::string indexNumber) 
    : Person(name, surname, address, peselNumber, gender)
    , indexNumber_(indexNumber)
{}

void Student::printPerson() {
        std::cout << "|" << generateCell(name_, sizeNameLimit_) << "|" 
              << generateCell(surname_, sizeSurnameLimit_) << "|" 
              << generateCell(address_, sizeAddressLimit_) << "|" 
              << generateCell(peselNumber_, sizePeselNumberLimit_) << "|" 
              << generateCell(salary_, sizeSalaryLimit_) << "|" 
              << generateCell(indexNumber_, sizeIndexNumberLimit_) << "|" 
              << generateCell(gender_, sizeGenderLimit_) << "|\n";
}