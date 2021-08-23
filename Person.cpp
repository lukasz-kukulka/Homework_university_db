#include "Person.hpp"

Person::Person(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, std::string salary, std::string indexNumber) 
    : name_(name)
    , surname_(surname)
    , address_(address)
    , peselNumber_(peselNumber)
    , gender_(gender)
    , salary_(salary)
    , indexNumber_(indexNumber)
{}

Person::~Person() {}

std::string Person::convertPersonGender(const Gender gender) {
    return gender == Gender::female ? "female" : "male";
}
