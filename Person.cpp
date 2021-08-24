#include "Person.hpp"
#include <iostream>

Person::Person(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender) 
    : name_(name)
    , surname_(surname)
    , address_(address)
    , peselNumber_(peselNumber)
    , gender_(gender)
{}

Person::~Person() {}

std::string Person::convertPersonGender(const Gender gender) {
    return gender == Gender::female ? "female" : "male";
}

std::string Person::generateCell(std::string cellBody, size_t cellSize) {
    std::string result(cellSize / 2 - cellBody.size() / 2, ' ');
    result += cellBody;
    result.insert(end(result), cellBody.size() % 2, ' ');
    result.insert(end(result), cellSize / 2 - cellBody.size() / 2, ' ');    
    return result;
}

void Person::printBorderTop() {
    std::cout << "|" << generateCell("NAME", sizeNameLimit_) << "|" 
              << generateCell("SURNAME", sizeSurnameLimit_) << "|" 
              << generateCell("ADDRESS", sizeAddressLimit_) << "|" 
              << generateCell("PESEL", sizePeselNumberLimit_) << "|" 
              << generateCell("SALARY", sizeSalaryLimit_) << "|" 
              << generateCell("INDEX", sizeIndexNumberLimit_) << "|" 
              << generateCell("GENDER", sizeGenderLimit_) << "|\n";
}
