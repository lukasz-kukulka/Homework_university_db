#include "SortPerson.hpp"

#include <iostream>

void SortPerson::operator()(std::vector<std::shared_ptr<Person>> person) const {
    person.size();
    std::cout << "SHOW PERSON HERE\n";
}