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
    std::cout << '|' << std::setw(sizeNameLimit/2 - name_.size()/2 - name_.size() % 2) << name_ << std::setw(sizeNameLimit/2 - name_.size()/2) 
              << '|' << std::setw(sizeSurnameLimit/2 - surname_.size()/2 - surname_.size() % 2) << surname_ << std::setw(sizeSurnameLimit/2 - surname_.size()/2)
              << '|' << std::setw(sizeIndexNumberLimit/2 - indexNumber_.size()/2 - indexNumber_.size() % 2) << indexNumber_ << std::setw(sizeIndexNumberLimit/2 - indexNumber_.size()/2)
              << '|' << std::setw(sizePeselNumberLimit/2 - peselNumber_.size()/2 - peselNumber_.size() % 2) << peselNumber_ << std::setw(sizePeselNumberLimit/2 - peselNumber_.size()/2)
              << '|' << std::setw(sizeGenderLimit/2 - gender_.size()/2 - gender_.size() % 2) << gender_ << std::setw(sizeGenderLimit/2 - gender_.size()/2) << '\n';
}