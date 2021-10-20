#include "ShowPersons.hpp"

#include <iostream>

ShowPersons::ShowPersons(std::shared_ptr<ValidationData> validation) 
    : validation_(validation)
{
}

void ShowPersons::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SHOW PERSON HERE\n";
}

void ShowPersons::printSingleRecord(const std::shared_ptr<Person>& singlePerson) {
    if (singlePerson) { // only for compile

    }
}