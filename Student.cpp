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
    std::cout << ' ' << std::setfill('-') << std::setw (4 + sizeNameLimit + sizeSurnameLimit + sizeAddressLimit + sizeIndexNumberLimit + sizePeselNumberLimit + sizeGenderLimit
                                                        + name_.size() % 2 + surname_.size() % 2 + address_.size() % 2 + indexNumber_.size() % 2 + peselNumber_.size() % 2 + convertStudentGender(gender_).size() % 2) << ' ' << '\n';
    std::cout << std::setfill(' ') << '|' << std::setw(sizeNameLimit/2 - name_.size()/2 + name_.size()) << name_ << std::setw(sizeNameLimit/2 - name_.size()/2 + 1) 
              << '|' << std::setw(sizeSurnameLimit/2 - surname_.size()/2 + surname_.size()) << surname_ << std::setw(sizeSurnameLimit/2 - surname_.size()/2 + 1)
              << '|' << std::setw(sizeAddressLimit/2 - address_.size()/2 + address_.size()) << address_<< std::setw(sizeAddressLimit/2 - address_.size()/2 + 1)
              << '|' << std::setw(sizeIndexNumberLimit/2 - indexNumber_.size()/2 + indexNumber_.size()) << indexNumber_ << std::setw(sizeIndexNumberLimit/2 - indexNumber_.size()/2 + 1)
              << '|' << std::setw(sizePeselNumberLimit/2 - peselNumber_.size()/2 + peselNumber_.size()) << peselNumber_ << std::setw(sizePeselNumberLimit/2 - peselNumber_.size()/2 + 1)
              << '|' << std::setw(sizeGenderLimit/2 - convertStudentGender(gender_).size()/2 + convertStudentGender(gender_).size() % 2 + convertStudentGender(gender_).size()) << convertStudentGender(gender_) << std::setw(sizeGenderLimit/2 - convertStudentGender(gender_).size()/2 + 2) << "|\n";
}

void Student::printBorderBotton() {
    std::cout << ' ' << std::setfill('-') << std::setw (4 + sizeNameLimit + sizeSurnameLimit + sizeAddressLimit + sizeIndexNumberLimit + sizePeselNumberLimit + sizeGenderLimit
                                                        + name_.size() % 2 + surname_.size() % 2 + address_.size() % 2 + indexNumber_.size() % 2 + peselNumber_.size() % 2 + convertStudentGender(gender_).size() % 2) << ' ' << '\n\n';
}