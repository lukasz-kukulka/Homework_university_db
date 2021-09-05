#include "Menu.hpp"
#include "Student.hpp"
#include "AddPerson.hpp"
#include "ShowPersons.hpp"
#include "SearchPerson.hpp"
#include "SortPerson.hpp"
#include "SaveLoadFile.hpp"
#include "GenerateData.hpp"
#include "DeletePerson.hpp"

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

void Menu::switchMenu() {
    MenuOptions menuOption { };
    while (true) {
        int choice = 0;
        std::cout << "Please insert you choice: ";
        std::cin >> choice;
        menuOption = static_cast<MenuOptions>(choice);
        switch (menuOption) {
        case MenuOptions::AddPerson: {
            command_ = std::make_unique<AddPerson>();
        } break;
        case MenuOptions::ShowPersons: {
            command_ = std::make_unique<ShowPersons>();
        } break;
        case MenuOptions::SearchPerson: {
            command_ = std::make_unique<SearchPerson>();
        } break;
        case MenuOptions::SortPerson: {
            command_ = std::make_unique<SortPerson>();
        } break;
        case MenuOptions::SaveLoadFile: {
            command_ = std::make_unique<SaveLoadFile>();
        } break;
        case MenuOptions::GenerateData: {
            command_ = std::make_unique<GenerateData>();
        } break;
        case MenuOptions::DeletePerson: {
            command_ = std::make_unique<DeletePerson>();
        } break;
        case MenuOptions::Exit: {

        } break;
        default:{
            std::cout << "ERROR ... Wrong value\n";
        } break;
        }
        if (command_) {
            (*command_)(person_);
            command_ = nullptr;
        }
    }
}