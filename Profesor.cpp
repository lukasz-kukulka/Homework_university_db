#include "Profesor.hpp"

Profesor::Profesor(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, size_t salary) 
    : name_(name)
    , surname_(surname)
    , address_(address)
    , peselNumber_(peselNumber)
    , gender_(gender)
    , salary_(salary)
{}