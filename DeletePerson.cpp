#include "DeletePerson.hpp"

#include <iostream>

void DeletePerson::operator()(std::vector<std::shared_ptr<Person>> person) const {
    person.size();
    std::cout << "DELETE PERSON HERE\n";
}