#include "Student.hpp"

Student::Student(std::string name, std::string surname, size_t indexNumber, uint64_t peselNumber, Gender gender) 
    : name_(name)
    , surname_(surname)
    , indexNumber_(indexNumber)
    , peselNumber_(peselNumber)
    , gender_(gender)
{}