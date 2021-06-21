#include "Student.hpp"

#include <iomanip>
#include <iostream>

Student::Student(std::string name, std::string surname, std::string indexNumber, std::string peselNumber, Gender gender) 
    : name_(name)
    , surname_(surname)
    , indexNumber_(indexNumber)
    , peselNumber_(peselNumber)
    , gender_(gender)
{}

void Student::printStudent() {
    std::cout << '|' << std::setw(sizeNameLimit/2 - name_.size()/2 - name_.size() % 2) << name_ << std::setw(sizeNameLimit/2 - name_.size()/2) << '|' ;
}