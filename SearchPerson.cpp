#include "SearchPerson.hpp"

#include "ShowPersons.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>

SearchPerson::SearchPerson(std::shared_ptr<ValidationData> validation)
    : validation_(validation)
{
}

void SearchPerson::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SEARCH PERSON HERE\n";
    searchMenu(validationUserInsertDataMenu(), person);
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
    return optionNumber;
}

int SearchPerson::userMenuOptionChoice() {
    std::cout << "Please insert your menu choice\n";
    int userAnswer { };
    std::cin >> userAnswer;
    return userAnswer;
}

int SearchPerson::validationUserInsertDataMenu() {
    int userAnswer { };
    auto menuSize = printSearchMenu();
    do {
        userAnswer = userMenuOptionChoice();
    } while (validation_->isCorrectMenuChoice(userAnswer, menuSize) == false);
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void SearchPerson::copyFoundPersonsForPrint() {
    foundPersons_.clear();
    if (foundPersonsPlusIndexNumber_.size() > foundPersons_.capacity()) {
       foundPersons_.reserve(foundPersonsPlusIndexNumber_.size() - foundPersons_.capacity()); 
    }
    for (const auto & ele : foundPersonsPlusIndexNumber_) {
        foundPersons_.push_back(ele.first);
    }
}

void SearchPerson::printSearchResult() {
    ShowPersons showPerson;
    if (foundPersonsPlusIndexNumber_.size() == 0) {
        std::cout << "Record not found\n";
    } else {
        copyFoundPersonsForPrint();
        showPerson.operator()(foundPersons_);
    }
}

void SearchPerson::deleteRecords(std::vector<std::shared_ptr<Person>>& person) {
    if (foundPersonsPlusIndexNumber_.size() > 0) {
        printDeleteInterface();
        auto userAnswer = deleteInterfaceUserAnswer();
        if (userAnswer == "D" || userAnswer == "d") {
            deleteSingleRecord(person, insertIndexNumberToDelete());
        } else {
            std::cout << "BACK TO MAIN MENU\n";
        }
    }
}

void SearchPerson::deleteSingleRecord(std::vector<std::shared_ptr<Person>>& person, size_t indexNumber) {
    std::swap(person[indexNumber], person.back());
    person.erase(person.end() - 1);
    std::cout << "Deleted record was successful\n";
}

void SearchPerson::printDeleteInterface() {
    printSearchResult();
    std::cout << "If you wanna delete some record press D, to back press B\n";
} 

std::string SearchPerson::deleteInterfaceUserAnswer() {
    std::string userAnswer { };
    do {
        std::cin >> userAnswer;
    } while (validationDeleteInterfaceUserAnswer(userAnswer) == false);
    return userAnswer;
}

bool SearchPerson::validationDeleteInterfaceUserAnswer(std::string userAnswer) {
    if (userAnswer == "D" || userAnswer == "d" || userAnswer == "B" || userAnswer == "b") {
        return true;
    }
    std::cout << "Wrong answer please insert (B)ack or (D)elete\n";
    return false;
}

size_t SearchPerson::insertIndexNumberToDelete() {
    std::cout << "Please insert index number to delete\n";
    size_t userAnswer { };
    do {
        std::cin >> userAnswer;
    } while (validation_->isCorrectMenuChoice(userAnswer, foundPersonsPlusIndexNumber_.size()) == false);
    return userAnswer;
}

void SearchPerson::searchByName(std::string nameToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersonsPlusIndexNumber_.clear();
    for (size_t i = 0; i < person.size(); i++) {
        if (person[i]->getName() == nameToSearch) {
            foundPersonsPlusIndexNumber_.push_back(std::make_pair(person[i], i));
        }
    }
    deleteRecords(person);
}

void SearchPerson::searchBySurname(std::string surnameToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersonsPlusIndexNumber_.clear();
    for (size_t i = 0; i < person.size(); i++) {
        if (person[i]->getSurname() == surnameToSearch) {
            foundPersonsPlusIndexNumber_.push_back(std::make_pair(person[i], i));
        }
    }
    deleteRecords(person);
}

void SearchPerson::searchByAddress(std::string addressToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersonsPlusIndexNumber_.clear();
    for (size_t i = 0; i < person.size(); i++) {
        if (person[i]->getAddress() == addressToSearch) {
            foundPersonsPlusIndexNumber_.push_back(std::make_pair(person[i], i));
        }
    }
    deleteRecords(person);
}

void SearchPerson::searchByPeselNumber(std::string peselToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersonsPlusIndexNumber_.clear();
    for (size_t i = 0; i < person.size(); i++) {
        if (person[i]->getPeselNumber() == peselToSearch) {
            foundPersonsPlusIndexNumber_.push_back(std::make_pair(person[i], i));
        }
    }
    deleteRecords(person);
}

void SearchPerson::searchByGender(std::string genderToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersonsPlusIndexNumber_.clear();
    for (size_t i = 0; i < person.size(); i++) {
        if (person[i]->getGender() == genderToSearch) {
            foundPersonsPlusIndexNumber_.push_back(std::make_pair(person[i], i));
        }
    }
    deleteRecords(person);
}

void SearchPerson::searchByIndexNumber(std::string indexNumberToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersonsPlusIndexNumber_.clear();
    for (size_t i = 0; i < person.size(); i++) {
        if (person[i]->getIndexNumber() == indexNumberToSearch) {
            foundPersonsPlusIndexNumber_.push_back(std::make_pair(person[i], i));
        }
    }
    deleteRecords(person);
}

void SearchPerson::searchBySalary(std::string salaryToSearch, std::vector<std::shared_ptr<Person>>& person) {
    foundPersonsPlusIndexNumber_.clear();
    for (size_t i = 0; i < person.size(); i++) {
        if (person[i]->getSalary() == salaryToSearch) {
            foundPersonsPlusIndexNumber_.push_back(std::make_pair(person[i], i));
        }
    }
    deleteRecords(person);
}