#include "Student.hpp"

#include <iomanip>
#include <iostream>

Student::Student(std::string name, std::string surname, std::string address, std::string indexNumber, std::string peselNumber, Gender gender) 
    : name_(name)
    , surname_(surname)
    , address_(address)
    , indexNumber_(indexNumber)
    , peselNumber_(peselNumber)
    , gender_(gender)
{}

std::string Student::convertStudentGender(const Gender gender) {
    return gender == Gender::female ? "female" : "male";
}

void Student::printStudent() {
    std::cout << '|' << std::setw(sizeNameLimit/2 - name_.size()/2 - name_.size() % 2) << name_ << std::setw(sizeNameLimit/2 - name_.size()/2) 
              << '|' << std::setw(sizeSurnameLimit/2 - surname_.size()/2 - surname_.size() % 2) << surname_ << std::setw(sizeSurnameLimit/2 - surname_.size()/2)
              << '|' << std::setw(sizeAddressLimit/2 - address_.size()/2 - address_.size() % 2) << address_<< std::setw(sizeAddressLimit/2 - address_.size()/2)
              << '|' << std::setw(sizeIndexNumberLimit/2 - indexNumber_.size()/2 - indexNumber_.size() % 2) << indexNumber_ << std::setw(sizeIndexNumberLimit/2 - indexNumber_.size()/2)
              << '|' << std::setw(sizePeselNumberLimit/2 - peselNumber_.size()/2 - peselNumber_.size() % 2) << peselNumber_ << std::setw(sizePeselNumberLimit/2 - peselNumber_.size()/2)
              << '|' << std::setw(sizeGenderLimit/2 - convertStudentGender(gender_).size()/2 - convertStudentGender(gender_).size() % 2) << convertStudentGender(gender_) << std::setw(sizeGenderLimit/2 - convertStudentGender(gender_).size()/2) << '\n';
}