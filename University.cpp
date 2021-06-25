#include "University.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>

constexpr char currentlyDate[] = "13082021";  // FORMAT DATE DDMMYYYY

University::University()
    : tempStudent() {
    // loadFromFile();
    // for (int i = 0; i < 10; i++) {
    //     students.push_back(Student());
    //     saveToFile(i);
    // }
    // students[0].printBorderTop();
    // for (auto stu : students) {

    //     stu.printStudent();
    // }
    // students[0].printBorderBotton();
}

void University::applicationStart() {
    do {
        printMenu();
    } while (menuEngine() != MenuOption::Exit);
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
    switch (menuOption_) {
    case MenuOption::AddStudents: {
    } break;
    case MenuOption::ShowStudent: {
    } break;
    case MenuOption::SearchStudents: {
    } break;
    case MenuOption::Exit: {
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
    auto result = std::all_of(name_.begin(), name_.end(), [](auto character) {
        return std::isalpha(character);
    });
    if (!result) {
        std::cout << "In name can be only alphabet\n";
        return false;
    }
    if (name_.size() > tempStudent.getSizeNameLimit()) {
        std::cout << "Length is to long\n";
        return false;
    }
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
    auto result = std::all_of(surname_.begin(), surname_.end(), [](auto character) {
        return std::isalpha(character);
    });
    if (!result) {
        std::cout << "In surname can be only alphabet\n";
        return false;
    }
    if (surname_.size() > tempStudent.getSizeSurnameLimit()) {
        std::cout << "Length is to long\n";
        return false;
    }
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
    if (address_.size() > tempStudent.getSizeAddressLimit()) {
        std::cout << "Length is to long\n";
        return false;
    }
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
    auto result = std::all_of(indexNumber_.begin(), indexNumber_.end(), [](auto character) {
        return std::isdigit(character);
    });
    if (!result) {
        std::cout << "In surname can be only alphabet\n";
        return false;
    }
    if (indexNumber_.size() != tempStudent.getSizeIndexNumberLimit()) {
        std::cout << "Length is to long\n";
        return false;
    }
    return true;
}

void University::insertStudentPeselNumber() {
    do {
        std::cout << "Please insert student PESEL number: ";
        std::cin >> peselNumber_;
        std::cout << '\n';
        std::cout << peselNumber_ << '\n';  //TEST
    } while (validatingPeselNumber() == false);
}

bool University::peselValidDOBCheck() {
    if ((peselNumber_[2] == '1' || peselNumber_[2] == '3' || peselNumber_[2] == '5' || peselNumber_[2] == '7' || peselNumber_[2] == '9') && peselNumber_[2] != '0' && peselNumber_[2] != '1' && peselNumber_[2] != '2') {
        return false;
    }
    if (peselNumber_[4] != '0' && peselNumber_[4] != '1' && peselNumber_[4] != '2' && peselNumber_[4] != '3') {
        return false;
    }
    if (peselNumber_[4] == '3' && peselNumber_[5] != '0' && peselNumber_[5] != '1' && peselNumber_[5] != '2') {
        return false;
    }
    return true;
}

bool University::peselValidGenderCheck() {
    gender_ = 1;  //TEST
    if (static_cast<size_t>(peselNumber_[9]) % 2 != static_cast<size_t>(gender_)) {
        return false;
    }
    return true;
}

bool University::peselValidWithCurrentlyDate() {
    if (currentlyDate[5] == '0' && (peselNumber_[2] == '4' || peselNumber_[2] == '5' || peselNumber_[2] == '6' || peselNumber_[2] == '7')) {
        return false;
    }
    if (currentlyDate[5] == '1' && (peselNumber_[2] == '6' || peselNumber_[2] == '7')) {
        return false;
    }
    return true;
}

bool University::peselValidWithWeight() {
    std::string weightCheck = "13791379131";
    size_t weightResult = 0;
    for (int i = 0; i < 11; i++) {
        weightResult = weightResult + (static_cast<size_t>(peselNumber_[i] - '0') * (static_cast<size_t>(weightCheck[i] - '0')));
    }
    weightResult = weightResult % 10;
    if (weightResult == 0) {
        weightResult = 0;
    } else {
        weightResult = 10 - weightResult;
    }
    if (static_cast<size_t>(peselNumber_[10] - '0') != weightResult) {
        return false;
    }
    return true;
}

bool University::validatingPeselNumber() {
    bool corectPeselNumber = true;
    corectPeselNumber = peselValidDOBCheck();
    //std::cout << "After peselValidDOBCheck() = " << corectPeselNumber << '\n'; //TEST
    corectPeselNumber = peselValidGenderCheck();
    // std::cout << "After peselValidGenderCheck() = " << corectPeselNumber << '\n'; //TEST
    corectPeselNumber = peselValidWithCurrentlyDate();
    //std::cout << "After peselValidWithCurrentlyDate() = " << corectPeselNumber << '\n'; //TEST
    corectPeselNumber = peselValidWithWeight();
    // std::cout << "After peselValidWithWeight() = " << corectPeselNumber << '\n'; //TEST
    if (peselNumber_.size() != tempStudent.getSizePeselNumberLimit()) {
        corectPeselNumber = false;
    }
    if (!corectPeselNumber) {
        std::cout << "Pesel number in incorrect\n";
    }
    return corectPeselNumber;
}

void University::insertStudentGender() {
    do {
        std::cout << "Please choose gender 1 - Male , 0 - Female: ";
        std::cin >> gender_;
        std::cout << '\n';
    } while (validatingGender() == false);
}

bool University::validatingGender() {
    if (gender_ !=0 && gender_ != 1) {
        std::cout << "Wrong value, please choose 0 or 1\n";
        return false;
    }
    return true;
}

void University::showStudents() {
    //std::cout <<
}

void University::saveToFile(size_t indexStudent) {
    std::fstream file;
    file.open("records.txt", std::ios::out | std::ios::app);
    file << "[Student nr. : " << indexStudent + 1 << "]\n";
    file << students[indexStudent].getName() << "\n";
    file << students[indexStudent].getSurname() << "\n";
    file << students[indexStudent].getAddress() << "\n";
    file << students[indexStudent].getIndexNumber() << "\n";
    file << students[indexStudent].getPeselNumber() << "\n";
    file << students[indexStudent].getGender() << "\n\n";
    file.close();
}

void University::loadFromFile() {
    students.reserve(countRecord());
    int lineNo = 1;
    std::string line;
    std::fstream file;
    file.open("records.txt", std::ios::in);
    if (file.good() == false) {
        std::cout << "Created new file\n";
        file.open("records.txt", std::ios::out | std::ios::app);
    }
    while (getline(file, line)) {
        switch (lineNo) {
        case 2: {
            name_ = line;
            break;
        }
        case 3: {
            surname_ = line;
            break;
        }
        case 4: {
            address_ = line;
            break;
        }
        case 5: {
            indexNumber_ = line;
            break;
        }
        case 6: {
            peselNumber_ = line;
            break;
        }
        case 7: {
            line.size() == 4 ? gender_ = 1 : gender_ = 0;
            break;
        }
        }
        lineNo++;
        if (lineNo > 8) {
            lineNo = 1;
            students.push_back(Student(name_, surname_, address_, indexNumber_, peselNumber_, static_cast<Student::Gender>(gender_)));
        }
    }
    file.close();
}

int University::countRecord() {
    int lineNo = 0;
    std::string line;
    std::fstream file;
    file.open("records.txt", std::ios::in);
    if (file.good() == false) {
        std::cout << "Created new file\n";
        file.open("records.txt", std::ios::out | std::ios::app);
    }
    while (getline(file, line)) {
        lineNo++;
    }
    file.close();
    return lineNo / 8;
}

University::MenuOption University::searchStudent() {
    uint8_t choice = 0;
    do {
        std::cout << "SEARCH BY\n";
        std::cout << "1. Surname\n";
        std::cout << "2. PESEL number\n";
        std::cout << "3. Back to main menu\n";
        std::cout << "Insert your choice: ";
        std::cin >> choice;
        if (choice == 1 || choice == 2) {
            return static_cast<MenuOption>(choice + 10);
        }
        if (choice == 3) {
            return MenuOption::BaseMenu;
        }
    } while (choice != 1 || choice != 2 || choice != 0);
    return MenuOption::BaseMenu;
}

void University::searchByPeselNumber(std::string pesel) {
    for (auto& student : students) {
        if (student.getPeselNumber() == pesel) {
            student.printStudent();
            student.printBorderBotton();
        }
    }
}

void University::searchBySurname(std::string surname) {
    for (auto& student : students) {
        if (student.getSurname() == surname) {
            student.printStudent();
            student.printBorderBotton();
        }
    }
}

void University::sortByPeselNumber() {
    std::sort(students.begin(), students.end(), [&](auto const& lhs, auto const& rhs) {
        return lhs.getPeselNumber() < rhs.getPeselNumber();
    });
}

void University::sortBySurname() {
    std::sort(students.begin(), students.end(), [&](auto const& lhs, auto const& rhs) {
        return lhs.getSurname() < rhs.getSurname();
    });
}

void University::deleteByIndexNumber(std::string indexNumber) {
    auto iterator = 0;
    std::string answer;
    for (auto& student : students) {
        iterator++;
        if (student.getIndexNumber() == indexNumber) {
            student.printStudent();
            student.printBorderBotton();
            break;
        }
    }
    while (1) {
        std::cout << "Do you wanna delete this record? Y/N: ";
        std::string confirm;
        std::cin >> confirm;
        if (confirm == "Y" || confirm == "y") {
            students[iterator] = students[students.size() - 1];
            students.erase(students.end() - 1);
            break;
        }
        if (confirm == "N" || confirm == "n") {
            break;
        }
    }
}
