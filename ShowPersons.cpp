#include "ShowPersons.hpp"

#include <iostream>

void ShowPersons::operator()(std::vector<std::shared_ptr<Person>> person) const {
    person.size();
    std::cout << "SHOW PERSON HERE\n";
}