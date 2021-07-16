#include "Person.hpp"

Person::Person(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender) 
    : name_(name)
    , surname_(surname)
    , address_(address)
    , peselNumber_(peselNumber)
    , gender_(gender)
{}

Person::~Person() {}