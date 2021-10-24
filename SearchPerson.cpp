#include "SearchPerson.hpp"

#include <iostream>

void SearchPerson::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SEARCH PERSON HERE\n";
}

int SearchPerson::printSearchMenu() {
    int optionNumber { };
    std::cout << "SEARCH BY\n";
    std::cout << ++optionNumber << " Name\n";
    std::cout << ++optionNumber << " Surname\n";
    std::cout << ++optionNumber << " Address\n";
    std::cout << ++optionNumber << " PESEL number\n";
    std::cout << ++optionNumber << " Gender\n";
    std::cout << ++optionNumber << " Index Number\n";
    std::cout << ++optionNumber << " Salary\n";
    std::cout << ++optionNumber << " Back to main menu\n";
    std::cout << "Insert your choice: ";
    return optionNumber;
}