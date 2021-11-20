#include "SortPerson.hpp"

#include <algorithm>
#include <iostream>

SortPerson::SortPerson(std::shared_ptr<ValidationData> validation) 
    : validation_(validation) {}

void SortPerson::operator()(std::vector<std::shared_ptr<Person>>& person) {
    sortMenu(userChoice(), person);
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

SortPerson::SortMenuOption SortPerson::userChoice() {
    auto menuSize = printSortMenu();
    int userAnswer { };
    std::cout << "Please insert your how you wanna sort database\n";
    do {
        std::cin >> userAnswer;
    } while (validation_->isCorrectMenuChoice(userAnswer, menuSize));
    return static_cast<SortMenuOption>(userAnswer);
}

SortPerson::SortMenuOption SortPerson::sortMenu(SortMenuOption userChoice, std::vector<std::shared_ptr<Person>>& person) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (userChoice) {
        case SortMenuOption::SortByName : {
            sortByName(person);
        } break;
        case SortMenuOption::SortBySurname : {
            sortBySurname(person);
        } break;       
        case SortMenuOption::SortByAddress : {
            sortByAddress(person);
        } break; 
        case SortMenuOption::SortByPeselNumber : {
            sortByPeselNumber(person);
        } break; 
        case SortMenuOption::SortByGender : {
            sortByGender(person);
        } break; 
        case SortMenuOption::SortByIndex : {
            sortByIndexNumber(person);
        } break;         
        case SortMenuOption::SortBySalary : {
            sortBySalary(person);
        } break;  
        case SortMenuOption::Back : {
            std::cout << "BACK TO MAIN MENU\n";
        } break; 
        default : {
            std::cout << "ERROR ... WRONG ANSWER(SWITCH)\n";
        } break;
    }
    person.size(); // delete
    return static_cast<SortMenuOption>(userChoice);
}

void SortPerson::sortByName(std::vector<std::shared_ptr<Person>>& person) {
    std::sort(begin(person), end(person), [&person](std::shared_ptr<Person> ele1, auto ele2){ return ele1->getName() < ele2->getName();});
}

void SortPerson::sortBySurname(std::vector<std::shared_ptr<Person>>& person) {
    std::sort(begin(person), end(person), [&person](std::shared_ptr<Person> ele1, auto ele2){ return ele1->getSurname() < ele2->getSurname();});
}

void SortPerson::sortByAddress(std::vector<std::shared_ptr<Person>>& person) {
    std::sort(begin(person), end(person), [&person](std::shared_ptr<Person> ele1, auto ele2){ return ele1->getAddress() < ele2->getAddress();});
}

void SortPerson::sortByPeselNumber(std::vector<std::shared_ptr<Person>>& person) {
    std::sort(begin(person), end(person), [&person](std::shared_ptr<Person> ele1, auto ele2){ return ele1->getPeselNumber() < ele2->getPeselNumber();});
}

void SortPerson::sortByGender(std::vector<std::shared_ptr<Person>>& person) {
    std::sort(begin(person), end(person), [&person](std::shared_ptr<Person> ele1, auto ele2){ return ele1->getGender() < ele2->getGender();});
}

void SortPerson::sortByIndexNumber(std::vector<std::shared_ptr<Person>>& person) {
    std::sort(begin(person), end(person), [&person](std::shared_ptr<Person> ele1, auto ele2){ return ele1->getIndexNumber() < ele2->getIndexNumber();});
}

void SortPerson::sortBySalary(std::vector<std::shared_ptr<Person>>& person) {
    std::sort(begin(person), end(person), [&person](std::shared_ptr<Person> ele1, auto ele2){ return ele1->getSalary() < ele2->getSalary();});
}
