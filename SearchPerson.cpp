#include "SearchPerson.hpp"

#include <iostream>

void SearchPerson::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    auto* ptr = person->
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

int SearchPerson::validationUserInsertDataMenu(int userAnswer) {
    //TO DO
    return userAnswer;
}

SearchPerson::SearchMenu SearchPerson::searchMenu(int userChoice) {
    //TO DO
    return static_cast<SearchMenu>(userChoice);
}

void SearchPerson::searchByName(std::string nameToSearch) {
    //TO DO
    foundPersons_.clear();
}

void SearchPerson::searchBySurname(std::string surnameToSearch) {
    //TO DO
}

void SearchPerson::searchByAddress() {
    //TO DO
}

void SearchPerson::searchByPeselNumber() {
    //TO DO
}