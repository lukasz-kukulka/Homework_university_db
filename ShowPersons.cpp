#include "ShowPersons.hpp"

#include <iostream>

void ShowPersons::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SHOW PERSON HERE\n";
}