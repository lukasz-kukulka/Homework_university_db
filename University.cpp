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
    menuOption_ = static_cast<MenuOption>(choice);
    switch (menuOption_)
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
    return menuOption_;
}

void University::addNewStudent() {


    std::cout << "Please insert student index number: ";
    std::cin >> indexNumber_;
    std::cout << '\n';
    std::cout << "Please insert student PESEL number: ";
    std::cin >> peselNumber_;
    std::cout << '\n';
    std::cout << "Please insert student surname: ";
    std::cin >> gender_;
    std::cout << '\n';
}

void University::insertStudentName() {
    std::cout << "Please insert student name: ";
    std::cin >> name_;
    std::cout << '\n';
}

void University::insertStudentSurname() {
    std::cout << "Please insert student surname: ";
    std::cin >> surname_;
    std::cout << '\n';
}

void University::insertStudentIndexNumber() {
    std::cout << "Please insert student index number: ";
    std::cin >> indexNumber_;
    std::cout << '\n';
}