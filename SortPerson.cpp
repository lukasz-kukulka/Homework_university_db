#include "SortPerson.hpp"

#include <iostream>

void SortPerson::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SORT -- PERSON HERE\n";
}

int SortPerson::printSortMenu() {
    int optionNumber { };
    std::cout << "SORT BY\n";
    std::cout << ++optionNumber << " Name\n";
    std::cout << ++optionNumber << " Surname\n";
    std::cout << ++optionNumber << " Address\n";
    std::cout << ++optionNumber << " PESEL number\n";
    std::cout << ++optionNumber << " Gender\n";
    std::cout << ++optionNumber << " Index Number\n";
    std::cout << ++optionNumber << " Salary\n";
    std::cout << ++optionNumber << " Back to main menu\n";
    return optionNumber;
}

SortPerson::SortMenu SortPerson::userChoice() {

}