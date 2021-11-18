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
    switchMenu();
}

void Menu::printMenu() {
    menuSize_ = 0;
    std::cout << " --------------------- \n";
    std::cout << "|  STUDENTS DATABASE  |\n";
    std::cout << " --------------------- \n";
    std::cout << ++menuSize_ << ". Add person\n";
    std::cout << ++menuSize_ << ". Show all persons\n";
    std::cout << ++menuSize_ << ". Search persons \n";
    std::cout << ++menuSize_ << ". Sort persons \n";
    std::cout << ++menuSize_ << ". Save/Load from file\n";
    std::cout << ++menuSize_ << ". Generate data persons\n";
    std::cout << ++menuSize_ << ". Delete record\n";
    std::cout << ++menuSize_ << ". Exit\n\n";
}

void Menu::switchMenu() {
    MenuOptions menuOption { };
    person_.push_back(std::make_shared<Student>(Student("TEST NAME", "TEST SURNAME", "TEST ADDRESS 22", "92041966814", "male", "1111111111")));// only for tests
    person_.push_back(std::make_shared<Student>(Student("name", "surname", "address", "61012648927", "gend", "2323234543"))); // only for tests
    person_.push_back(std::make_shared<Student>(Student("nameee", "surrname", "addrettss_", "96072048497", "female", "2323237543"))); // only for tests
    while (true) {
        printMenu();
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
            command_ = std::make_unique<ShowPersons>(valid_);
        } break;
        case MenuOptions::SearchPerson: {
            command_ = std::make_unique<SearchPerson>(valid_);
        } break;
        case MenuOptions::SortPerson: {
            command_ = std::make_unique<SortPerson>(valid_);
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