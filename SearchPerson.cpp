#include "SearchPerson.hpp"

#include <iostream>

void SearchPerson::operator()(std::vector<std::shared_ptr<Person>> person) const {
    person.size();
    std::cout << "SEARCH PERSON HERE\n";
}