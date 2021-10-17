#include "Person.hpp"
#include <math.h>
#include <iostream>

Person::Person(std::string name, std::string surname, std::string address, std::string peselNumber, std::string gender) 
    : name_(name)
    , surname_(surname)
    , address_(address)
    , peselNumber_(peselNumber)
    , gender_(gender)
{}

Person::~Person() {}

std::string Person::generateCell(std::string cellBody, size_t cellSize) {
    std::string result((cellSize - cellBody.size()) / 2, ' ');
    result += cellBody;
    result.insert(end(result), (cellSize - cellBody.size()) / 2 + (std::labs(cellBody.size() % 2)), ' ');    
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

size_t Person::getBorderSize() {
    return (8 + sizeNameLimit_ + sizeSurnameLimit_ + sizeAddressLimit_ + sizeSalaryLimit_ + sizePeselNumberLimit_ + sizeGenderLimit_ + sizeIndexNumberLimit_);
}

void Person::printBorderLine() {
    std::cout << std::string(getBorderSize(), '-') << '\n';
}