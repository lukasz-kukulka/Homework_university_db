#include "SearchPerson.hpp"

#include <iostream>

void SearchPerson::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SEARCH PERSON HERE\n";
}