#include "AddPerson.hpp"

#include <iostream>

// void AddPerson::operator()(std::vector<Person>& person) const {
//     person.size();
//     std::cout << "ADD PERSON HERE\n";
// }

void AddPerson::operator()(std::vector<std::shared_ptr<Person>> person) const {
    person.size();
    std::cout << "ADD PERSON HERE\n";
}