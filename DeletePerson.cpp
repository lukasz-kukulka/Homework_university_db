#include "DeletePerson.hpp"

#include <iostream>

void DeletePerson::operator()(std::vector<std::shared_ptr<Person>>& person)  {
    person.size();
    std::cout << "DELETE PERSON HERE\n";
}