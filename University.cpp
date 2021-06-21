#include "University.hpp"

#include <iostream>

University::University() {

    for (int i = 0; i < 10; i++) {
        students.push_back(Student());
        students[i].printStudent();
    }
    students[0].printBorderBotton();
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
    insertStudentName();
    insertStudentSurname();
    insertStudentIndexNumber();
    insertStudentPeselNumber();
    insertStudentGender();
    students.push_back(Student(name_, surname_, address_, indexNumber_, peselNumber_, static_cast<Student::Gender>(gender_)));
}

void University::insertStudentName() {
    do {
        std::cout << "Please insert student name: ";
        std::cin >> name_;
        std::cout << '\n';
    } while (validatingName() == false);
}

bool University::validatingName() {
    //TODO
    return true;
}

void University::insertStudentSurname() {
    do {
        std::cout << "Please insert student surname: ";
        std::cin >> surname_;
        std::cout << '\n';
    } while (validatingSurname() == false);
}

bool University::validatingSurname() {
    //TODO
    return true;
}

void University::insertAddress() {
    do {
        std::cout << "Please insert student address: ";
        std::cin >> surname_;
        std::cout << '\n';
    } while (validatingAddress() == false);
}

bool University::validatingAddress() {
    //TODO
    return true;
}

void University::insertStudentIndexNumber() {
    do {
        std::cout << "Please insert student index number: ";
        std::cin >> indexNumber_;
        std::cout << '\n';
    } while (validatingIndexNumber() == false);
}

bool University::validatingIndexNumber() {
    //TODO
    return true;
}

void University::insertStudentPeselNumber() {
    do {
        std::cout << "Please insert student PESEL number: ";
        std::cin >> peselNumber_;
        std::cout << '\n';       
    } while (validatingPeselNumber() == false);
}

bool University::validatingPeselNumber() {
    //TODO
    return true;
}

void University::insertStudentGender() {
    do {
        std::cout << "Please insert student surname: ";
        std::cin >> gender_;
        std::cout << '\n';
    } while (validatingGender() == false);
}

bool University::validatingGender() {
    //TODO
    return true;
}

void University::showStudents() {

    //std::cout << 
}