#include "SortPerson.hpp"

#include <iostream>

SortPerson::SortPerson(std::shared_ptr<ValidationData> validation) 
    : validation_(validation) {}

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
    auto menuSize = printSortMenu();
    int userAnswer { };
    std::cout << "Please insert your how you wanna sort database\n";
    do {
        std::cin >> userAnswer;
    } while (true); // to do: validation 
    // to do: menu
}

SortPerson::SortMenu SortPerson::sortMenu(int userChoice, std::vector<std::shared_ptr<Person>>& person) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (static_cast<SortMenu>(userChoice)) {
        case SortMenu::SortByName : {
            // to do
        } break;
        case SortMenu::SortBySurname : {
            // to do
        } break;       
        case SortMenu::SortByAddress : {
            // to do
        } break; 
        case SortMenu::SortByPeselNumber : {
            // to do
        } break; 
        case SortMenu::SortByGender : {
            // to do
        } break; 
        case SortMenu::SortByIndex : {
            // to do
        } break;         
        case SortMenu::SortBySalary : {
            // to do
        } break;  
        case SortMenu::Back : {
            std::cout << "BACK TO MAIN MENU\n";
        } break; 
        default : {
            std::cout << "ERROR ... WRONG ANSWER(SWITCH)\n";
        } break;
    }
    return static_cast<SortMenu>(userChoice);
}