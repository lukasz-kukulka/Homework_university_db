#include "Professor.hpp"

#include <iomanip>
#include <iostream>

Professor::Professor(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, std::string salary) 
    : Person(name, surname, address, peselNumber, gender)
    , salary_(salary)
{}

void Professor::printPerson() {
    std::cout << "|" << generateCell(name_, sizeNameLimit_) << "|" 
              << generateCell(surname_, sizeSurnameLimit_) << "|" 
              << generateCell(address_, sizeAddressLimit_) << "|" 
              << generateCell(peselNumber_, sizePeselNumberLimit_) << "|" 
              << generateCell(salary_, sizeSalaryLimit_) << "|" 
              << generateCell(indexNumber_, sizeIndexNumberLimit_) << "|" 
              << generateCell(convertPersonGender(gender_), sizeGenderLimit_) << "|\n";
}
