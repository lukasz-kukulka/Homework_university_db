#include "SearchPerson.hpp"
#include "ShowPersons.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

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

SearchPerson::SearchMenu SearchPerson::searchMenu(int userChoice) {
    switch (static_cast<SearchMenu>(userChoice)) {
        case SearchMenu::SearchByName : {
            //TO DO
        } break;
        case SearchMenu::SearchBySurname : {
            //TO DO
        } break;       
        case SearchMenu::SearchByAddress : {
            //TO DO
        } break; 
        case SearchMenu::SearchByPeselNumber : {
            //TO DO
        } break; 
        case SearchMenu::SearchByGender : {
            //TO DO
        } break; 
        case SearchMenu::SearchByIndex : {
            //TO DO
        } break;         
        case SearchMenu::SearchBySalary : {
            //TO DO
        } break;  
        case SearchMenu::Back : {
            //TO DO
        } break; 
        default : {
            //TO DO
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