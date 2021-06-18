#include "University.hpp"

#include <iostream>

University::University() {

}

void University::printMenu() {
    std::cout << " --------------------- \n";
    std::cout << "|  STUDENTS DATABASE  |\n";
    std::cout << " --------------------- \n";
    std::cout << "1. Add student\n";
    std::cout << "2. Show all students\n";
    std::cout << "3. Search students \n";
    std::cout << "4. Exit\n\n";
}

University::MenuOption University::menuEngine() {
    std::cout << "Please insert you choice: ";
    uint8_t choice = 0;
    std::cin >> choice;
    switch (static_cast<MenuOption>(choice))
    {
        case MenuOption::AddStudents : {

        } break;
        case MenuOption::ShowStudent : {

        } break;
        case MenuOption::SearchStudents : {

        } break;
        case MenuOption::Exit : {

        } break;    
        default:
        break;
    }
    return static_cast<MenuOption>(choice);
}