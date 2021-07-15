#include "Profesor.hpp"

Profesor::Profesor(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, size_t salary) 
    : Person(name, surname, address, peselNumber, gender)
    , salary_(salary)
{}