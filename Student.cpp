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

int Student::getBorderSize() const {
    return (6 + sizeNameLimit + sizeSurnameLimit + sizeAddressLimit + sizeIndexNumberLimit + sizePeselNumberLimit + sizeGenderLimit);
}

void Student::printBorderTop() {
    std::string temp = "STUDENTS DATABASE";
    std::cout << ' ' << std::setfill('-') << std::setw (getBorderSize()) << ' ' << "\n";
    std::cout << '|' << std::setfill(' ') << std::setw (getBorderSize() / 2 - temp.size() / 2 + temp.size()) << temp << std::setw (getBorderSize() / 2 - temp.size() / 2 - temp.size() % 2) << '|' << "\n";
    std::cout << ' ' << std::setfill('-') << std::setw (getBorderSize()) << ' ' << "\n";
    temp = "NAME";
    std::cout << std::setfill(' ') << '|' << std::setw(sizeNameLimit / 2 - temp.size() / 2 + temp.size()) << temp << std::setw(sizeNameLimit / 2 - temp.size() / 2 + 1); 
    temp = " SURNAME";
    std::cout << '|' << std::setw(sizeSurnameLimit / 2 - temp.size() / 2 + temp.size()) << temp << std::setw(sizeSurnameLimit / 2 - temp.size() / 2 + 1); 
    temp = " ADDRESS";
    std::cout << '|' << std::setw(sizeAddressLimit / 2 - temp.size() / 2 + temp.size()) << temp << std::setw(sizeAddressLimit / 2 - temp.size() / 2 + 1); 
    temp = " INDEX";
    std::cout << '|' << std::setw(sizeIndexNumberLimit / 2 - temp.size() / 2 + temp.size()) << temp << std::setw(sizeIndexNumberLimit / 2 - temp.size() / 2 + 1); 
    temp = " PESEL";
    std::cout << '|' << std::setw(sizePeselNumberLimit / 2 - temp.size() / 2 + temp.size()) << temp << std::setw(sizePeselNumberLimit / 2 - temp.size() / 2 + 1); 
    temp = "GENDER";
    std::cout << '|' << std::setw(sizeGenderLimit / 2 - temp.size() / 2 + temp.size()) << temp << std::setw(sizeGenderLimit / 2 - temp.size() / 2 + 2) << "|\n"; 
}

void Student::printStudent() {
    std::cout << ' ' << std::setfill('-') << std::setw (getBorderSize()) <<  ' ' << '\n';
    std::cout << std::setfill(' ') << '|' << std::setw(sizeNameLimit / 2 - name_.size() / 2 + name_.size()) << name_ << std::setw(sizeNameLimit / 2 - name_.size() / 2 + 1 - name_.size() % 2) 
              << '|' << std::setw(sizeSurnameLimit / 2 - surname_.size() / 2 + surname_.size()) << surname_ << std::setw(sizeSurnameLimit / 2 - surname_.size() / 2 + 1 - surname_.size() % 2)
              << '|' << std::setw(sizeAddressLimit / 2 - address_.size() / 2 + address_.size()) << address_<< std::setw(sizeAddressLimit / 2 - address_.size() / 2 + 1  - address_.size() % 2)
              << '|' << std::setw(sizeIndexNumberLimit / 2 - indexNumber_.size() / 2 + indexNumber_.size()) << indexNumber_ << std::setw(sizeIndexNumberLimit / 2 - indexNumber_.size() / 2 + 1 - indexNumber_.size() % 2)
              << '|' << std::setw(sizePeselNumberLimit / 2 - peselNumber_.size() / 2 + peselNumber_.size()) << peselNumber_ << std::setw(sizePeselNumberLimit / 2 - peselNumber_.size() / 2 + 1 - peselNumber_.size() % 2)
              << '|' << std::setw(sizeGenderLimit / 2 - convertStudentGender(gender_).size() / 2 + convertStudentGender(gender_).size() % 2 + convertStudentGender(gender_).size()) << convertStudentGender(gender_) << std::setw(sizeGenderLimit / 2 - convertStudentGender(gender_).size() / 2 + 2) << "|\n";
}

void Student::printBorderBotton() {
    std::cout << ' ' << std::setfill('-') << std::setw (getBorderSize()) << ' ' << "\n\n";
}

std::string Student::getGender() { 
    return convertStudentGender(gender_); 
}