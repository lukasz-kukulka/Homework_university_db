#include "Menu.hpp"

#include <iostream>

void Menu::operator()(std::vector<Person>*person) const {
    if (person) {

    }    
}

void Menu::printMenu() const {
    size_t optionNumber = { };
    std::cout << " --------------------- \n";
    std::cout << "|  STUDENTS DATABASE  |\n";
    std::cout << " --------------------- \n";
    std::cout << ++optionNumber << ". Add studentTEST\n";
    std::cout << ++optionNumber << ". Show all students\n";
    std::cout << ++optionNumber << ". Search students \n";
    std::cout << ++optionNumber << ". Sort students \n";
    std::cout << ++optionNumber << ". Save/Load from file\n";
    std::cout << ++optionNumber << ". Generate data persons\n";
    std::cout << ++optionNumber << ". Delete record\n";
    std::cout << ++optionNumber << ". Exit\n\n";
}