#include "SearchPerson.hpp"
#include "ShowPersons.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

SearchPerson::SearchPerson(std::shared_ptr<ValidationData> validation)
    : validation_(validation)
{
}

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

int SearchPerson::validationUserInsertDataMenu(int userAnswer) {
    //TO DO
    return userAnswer;
}

std::string SearchPerson::insertSearchData(std::string searchChoice) {
    std::string userAnswer;
    do {
        std::cout << "Please insert " << searchChoice << " to search.\n";
        std::getline(std::cin, userAnswer);
    } while (validation_->validationIsAlpabet(userAnswer) == false);
    return userAnswer;
}

SearchPerson::SearchMenu SearchPerson::searchMenu(int userChoice, std::vector<std::shared_ptr<Person>>& person) {
    switch (static_cast<SearchMenu>(userChoice)) {
        case SearchMenu::SearchByName : {
            searchByName(insertSearchData("name"), person);
        } break;
        case SearchMenu::SearchBySurname : {
            searchBySurname(insertSearchData("surname"), person);
        } break;       
        case SearchMenu::SearchByAddress : {
            searchByAddress(insertSearchData("address"), person);
        } break; 
        case SearchMenu::SearchByPeselNumber : {
            searchByPeselNumber(insertSearchData("PESEL number"), person);
        } break; 
        case SearchMenu::SearchByGender : {
            searchByGender(insertSearchData("gender"), person);
        } break; 
        case SearchMenu::SearchByIndex : {
            searchByIndexNumber(insertSearchData("index"), person);
        } break;         
        case SearchMenu::SearchBySalary : {
            searchBySalary(insertSearchData("salary"), person);
        } break;  
        case SearchMenu::Back : {
            std::cout << "BACK TO MAIN MENU\n";
        } break; 
        default : {
            std::cout << "ERROR ... WRONG ANSWER(SWITCH)\n";
        } break;
    }
    return static_cast<SearchMenu>(userChoice);
}

void SearchPerson::printSearchResult() {
    ShowPersons showPerson;
    if (foundPersons_.size() == 0) {
        std::cout << "Record not found\n";
    } else {
        showPerson.operator()(foundPersons_);
    }
}

void SearchPerson::searchByName(std::string nameToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersons_.clear();
    std::copy_if(begin(person), end(person), std::back_inserter(foundPersons_), [&](auto ele){ return ele->getName() == nameToSearch; });
}

void SearchPerson::searchBySurname(std::string surnameToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersons_.clear();
    std::copy_if(begin(person), end(person), std::back_inserter(foundPersons_), [&](auto ele){ return ele->getName() == surnameToSearch; });
}

void SearchPerson::searchByAddress(std::string addressToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersons_.clear();
    std::copy_if(begin(person), end(person), std::back_inserter(foundPersons_), [&](auto ele){ return ele->getName() == addressToSearch; });
}

void SearchPerson::searchByPeselNumber(std::string peselToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersons_.clear();
    std::copy_if(begin(person), end(person), std::back_inserter(foundPersons_), [&](auto ele){ return ele->getName() == peselToSearch; });
}

void SearchPerson::searchByGender(std::string genderToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersons_.clear();
    std::copy_if(begin(person), end(person), std::back_inserter(foundPersons_), [&](auto ele){ return ele->getName() == genderToSearch; });
}

void SearchPerson::searchByIndexNumber(std::string indexNumberToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersons_.clear();
    std::copy_if(begin(person), end(person), std::back_inserter(foundPersons_), [&](auto ele){ return ele->getName() == indexNumberToSearch; });
}

void SearchPerson::searchBySalary(std::string salaryToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersons_.clear();
    std::copy_if(begin(person), end(person), std::back_inserter(foundPersons_), [&](auto ele){ return ele->getName() == salaryToSearch; });
}