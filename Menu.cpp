#include "Menu.hpp"
#include "Student.hpp"

#include <iostream>

void Menu::startApp() {
    printMenu();
    switchMenu();
}

void Menu::printMenu() const {
    size_t optionNumber = {};
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

void Menu::switchMenu() const {
    MenuOptions menuOption { };
    while (true) {
        int choice = 0;
        std::cout << "Please insert you choice: ";
        std::cin >> choice;
        menuOption = static_cast<MenuOptions>(choice);
        switch (menuOption) {
        case MenuOptions::AddPerson: {
        } break;
        case MenuOptions::ShowStudent: {
        } break;
        case MenuOptions::SearchPerson: {
        } break;
        case MenuOptions::SortPerson: {
        } break;
        case MenuOptions::SaveLoadFile: {
        } break;
        case MenuOptions::GenerateData: {
        } break;
        case MenuOptions::DeletePerson: {
        } break;
        case MenuOptions::Exit: {
        } break;
        default:{
            std::cout << "ERROR ... Wrong value\n";
        } break;
        }
    }
}