#include "SortPerson.hpp"

#include <iostream>

void SortPerson::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SORT -- PERSON HERE\n";
}

void SortPerson::printMenu() {
    
}