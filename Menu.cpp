#include "Menu.hpp"
#include "Student.hpp"
#include "AddPerson.hpp"
#include "ShowPersons.hpp"
#include "SearchPerson.hpp"
#include "SortPerson.hpp"
#include "SaveLoadFile.hpp"
#include "GenerateData.hpp"
#include "DeletePerson.hpp"
#include "ExitApp.hpp"
#include <memory>


#include <iostream>

Menu::Menu() {
    valid_ = std::make_shared<ValidationData>();
}

void Menu::startApp() {
    printMenu();
    switchMenu();
}

void Menu::printMenu() {
    menuSize_ = 0;
    std::cout << " --------------------- \n";
    std::cout << "|  STUDENTS DATABASE  |\n";
    std::cout << " --------------------- \n";
    std::cout << ++menuSize_ << ". Add studentTEST\n";
    std::cout << ++menuSize_ << ". Show all students\n";
    std::cout << ++menuSize_ << ". Search students \n";
    std::cout << ++menuSize_ << ". Sort students \n";
    std::cout << ++menuSize_ << ". Save/Load from file\n";
    std::cout << ++menuSize_ << ". Generate data persons\n";
    std::cout << ++menuSize_ << ". Delete record\n";
    std::cout << ++menuSize_ << ". Exit\n\n";
}

void Menu::switchMenu() {
    MenuOptions menuOption { };
    while (true) {
        int choice = 0;
        do {
            std::cout << "Please insert you choice: ";
            std::cin >> choice;
        } while (valid_->isCorrectMenuChoice(choice, menuSize_) == false);
        menuOption = static_cast<MenuOptions>(choice);
        switch (menuOption) {
        case MenuOptions::AddPerson: {
            command_ = std::make_unique<AddPerson>(valid_);
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
            command_ = std::make_unique<ExitApp>();
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