#include "University.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>

constexpr char currentlyDate[] = "13082021";  // FORMAT DATE DDMMYYYY

University::University() {
    // loadFromFile();
    // for (int i = 0; i < 10; i++) {
    //     person_.push_back(Student());
    //     saveToFile(i);
    // }
    // person_[0].printBorderTop();
    // for (auto stu : person_) {

    //     stu.printStudent();
    // }
    // person_[0].printBorderBotton();
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
    std::cout << "4. Sort students \n";
    std::cout << "5. Save/Load from file\n";
    std::cout << "6. Delete record\n";
    std::cout << "7. Exit\n\n";
}

University::MenuOption University::menuEngine() {
    int choice = 0;
    do {
        std::cout << "Please insert you choice: ";
        std::cin >> choice;
    } while (validatingMenuChoose(choice) == false);
    menuOption_ = static_cast<MenuOption>(choice);
    switch (menuOption_) {
        case MenuOption::AddStudents : {
            //addNewStudent();
        } break;
        case MenuOption::ShowStudent : {
            //showStudents();
        } break;
        case MenuOption::SearchStudents : {
            //searchMenuEngine();
        } break;
        case MenuOption::SortStudents : {
            //sortMenuEngine();
        } break;
        case MenuOption::SaveLoadFile : {

        } break;
        case MenuOption::Delete : {

        } break;
        case MenuOption::Exit: {
            
        } break;
        default :
        break;
    }
    return menuOption_;
}

bool University::validatingMenuChoose(const int choosenValueToValid) {
    if (std::cin.fail() || choosenValueToValid < 1 || choosenValueToValid > 5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect value, please put number betwen 1 and 5\n";
        return false;
    }
    return true;
}

void University::addNewStudent() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    insertStudentName();
    insertStudentSurname();
    insertStudentGender();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    insertAddress();
    insertStudentPeselNumber();
    
    insertProfessorSalary();
    
    insertStudentIndexNumber();
    confirmAddRecord();
}

void University::confirmAddRecord() {
    std::cout << "Name: " << name_ << " | Surname: " << surname_ << " | Gender: " <<  convertStudentGender(gender_) 
              << " | Address: " << address_ << " | Index nr.: " << indexNumber_ << " | PESEL: " << peselNumber_ << '\n'; 
    while ( 1 ) {
        std::cout << "Are you sure you wanna add this record to database? Y/N ";
        if (yesNoOption() == YesNoOption::Yes) {
            person_.push_back(std::make_shared<Student>(Student(name_, surname_,address_, peselNumber_, static_cast<Student::Gender>(gender_), indexNumber_)));
            break; 
        }
        if (yesNoOption() == YesNoOption::No) {
            break;
        }
    }
}

void University::insertStudentName() {
    do {
        std::cout << "Please insert student name: ";
        std::getline (std::cin, name_);
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
    if (name_.size() > sizeNameLimit_) {
        std::cout << "Length is to long\n";
        return false;
    }
    return true;
}

void University::insertStudentSurname() {
    do {
        std::cout << "Please insert student surname: ";
        std::getline (std::cin, surname_);
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
    if (surname_.size() > sizeSurnameLimit_) {
        std::cout << "Length is to long\n";
        return false;
    }
    return true;
}

void University::insertAddress() {
    do {
        std::cout << "Please insert student address: ";
        std::getline (std::cin, address_);
    } while (validatingAddress() == false);
}

bool University::validatingAddress() {
    if (address_.size() > sizeAddressLimit_) {
        std::cout << "Length is to long\n";
        return false;
    }
    return true;
}

void University::insertStudentIndexNumber() {
    do {
        std::cout << "Please insert student index number(10 digits): ";
        std::getline (std::cin, indexNumber_);
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
    if (indexNumber_.size() != sizeIndexNumberLimit_ - 2) {
        std::cout << "Wrong length, insert 10 digit\n";
        return false;
    }
    return true;
}

void University::insertProfessorSalary() {
    do {
        std::cout << "Please insert professor salary(max 5 digits): ";
        std::getline (std::cin, professorSalary);
    } while (validatingSalary() == false);
}

bool University::validatingSalary() {
    return false;
}

void University::insertStudentPeselNumber() {
    do {
        std::cout << "Please insert student PESEL number: ";
        std::getline (std::cin, peselNumber_);
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
    if (peselNumber_.size() != sizePeselNumberLimit_ - 3) {
        corectPeselNumber = false;
    }
    if (!corectPeselNumber) {
        std::cout << "Pesel number is incorrect\n";
    }
    return corectPeselNumber;
}

void University::insertStudentGender() {
    do {
        std::cout << "Please choose gender: 1 - Male , 0 - Female: ";
        std::cin >> gender_;  
    } while (validatingGender() == false);
}

bool University::validatingGender() {
    if (gender_ !=0 && gender_ != 1) {
        std::cout << "Wrong value, please choose 0 or 1\n";
        return false;
    }
    return true;
}

// void University::showStudents() {
//     // if (!person_.empty()) {
//     //     person_[0].printBorderTop();
//     //     for (auto ele : person_) {
//     //         ele.printStudent();
//     //     }
//     //     person_[0].printBorderBotton();
//     // }
//     // std::cout << "Database of students is empty please load form file or add new students\n";
// }

// void University::saveToFile(size_t indexStudent) {
//     std::fstream file;
//     file.open("records.txt", std::ios::out | std::ios::app);
//     file << "[Student nr. : " << indexStudent + 1 << "]\n";
//     file << person_[indexStudent].getName() << "\n";
//     file << person_[indexStudent].getSurname() << "\n";
//     file << person_[indexStudent].getAddress() << "\n";
//     //file << person_[indexStudent].getIndexNumber() << "\n";
//     file << person_[indexStudent].getPeselNumber() << "\n";
//     file << person_[indexStudent].getGender() << "\n\n";
//     file.close();
// }

// void University::loadFromFile() {
//     person_.reserve(countRecord());
//     int lineNo = 1;
//     std::string line;
//     std::fstream file;
//     file.open("records.txt", std::ios::in);
//     if (file.good() == false) {
//         std::cout << "Created new file\n";
//         file.open("records.txt", std::ios::out | std::ios::app);
//     }
//     while (getline(file, line)) {
//         switch (lineNo) {
//             case 2: {
//                 name_ = line;
//             } break;
//             case 3: {
//                 surname_ = line;
//             } break;
//             case 4: {
//                 address_ = line;
//             } break;
//             case 5: {
//                 indexNumber_ = line;
//             } break;
//             case 6: {
//                 peselNumber_ = line;
//             } break;
//             case 7: {
//                 line.size() == 4 ? gender_ = 1 : gender_ = 0;
//             } break;
//             default : {  
//             } break;
//         }
//         lineNo++;
//         if (lineNo > 8) {
//             lineNo = 1;
//             person_.push_back(Student(Student(name_, surname_,address_, peselNumber_, static_cast<Student::Gender>(gender_), indexNumber_)));
//         }
//     }
//     file.close();
// }

// int University::countRecord() {
//     int lineNo = 0;
//     std::string line;
//     std::fstream file;
//     file.open("records.txt", std::ios::in);
//     if (file.good() == false) {
//         std::cout << "Created new file\n";
//         file.open("records.txt", std::ios::out | std::ios::app);
//     }
//     while (getline(file, line)) {
//         lineNo++;
//     }
//     file.close();
//     return lineNo / 8;
// }

// void University::printSearchMenu() {
//     std::cout << "SEARCH BY\n";
//     std::cout << "1. Surname\n";
//     std::cout << "2. PESEL number\n";
//     std::cout << "3. Back to main menu\n";
//     std::cout << "Insert your choice: ";
// }

// University::MenuOption University::searchMenuStudent() {
//     int choice = 0;
//     do {
//         std::cin >> choice;
//     } while (validatingSearchAndSortMenuChoose(choice) == false);
//     if (choice == 3) {
//         return MenuOption::Back;
//     }
//     return static_cast<MenuOption>(choice + 10);
// }

// void University::searchMenuEngine() {
//     MenuOption searchChoose = MenuOption::BaseMenu;
//     while (searchChoose != MenuOption::Back) {
//         printSearchMenu();
//         searchChoose = searchMenuStudent();
//         switch (searchChoose) {
//             case MenuOption::SearchBySurname : {
//                 searchBySurname();
//             } break;
//             case MenuOption::SearchByPESEL : {
//                 searchByPeselNumber();
//             } break;
//             default :
//             break;
//         }
//     }
// }

// bool University::validatingSearchAndSortMenuChoose(const int choosenValueToValid) {
//     if (std::cin.fail() || choosenValueToValid < 1 || choosenValueToValid > 3) {
//         std::cin.clear();
//         std::cout << "Incorrect value, please put number betwen 1 and 3\n";
//         return false;
//     }
//     return true;
// }

// std::string University::insertSearchPeselNumber() {
//     std::string insertPesel;
//     do {
//         std::cout << "Please insert searching PESEL number: ";
//         std::getline (std::cin, insertPesel);
//     } while (validatingPeselNumber() == false);
//     return insertPesel;
// }

// void University::checkIfExistPeselNumber(std::string pesel) {
//     bool ifExistPeselNumber = false;
//     for (auto& student : person_) {
//         if (student.getPeselNumber() == pesel) {
//             student.printStudent();
//             student.printBorderBotton();
//             ifExistPeselNumber = true;
//             break;
//         }
//     }
//     if (ifExistPeselNumber == false) {
//         std::cout << "PESEL number don't exist in database\n";
//     }
// }

// void University::searchByPeselNumber() {
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     checkIfExistPeselNumber(insertSearchPeselNumber());
// }

// std::string University::insertSearchSurname() {
//     std::string insertSurname;
//     do {
//         std::cout << "Please insert searching Surname: ";
//         std::getline (std::cin, insertSurname);
//     } while (validatingSurname() == false);
//     return insertSurname;
// }

// void University::checkIfExistSurname(std::string surname) {
//     bool ifExistSurname = false;
//     for (auto& student : person_) {
//         if (student.getSurname() == surname) {
//             student.printStudent();
//             student.printBorderBotton();
//             ifExistSurname = true;
//             break;
//         }
//     }
//     if (ifExistSurname == false) {
//         std::cout << "Surname don't exist in database\n";
//     }
// }

// void University::searchBySurname() {
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     checkIfExistSurname(insertSearchSurname());
// }

// void University::printSortMenu() {
//     std::cout << "SORT BY\n";
//     std::cout << "1. PESEL number\n";
//     std::cout << "2. Surname number\n";
//     std::cout << "3. Back to main menu\n";
//     std::cout << "Insert your choice: ";
// }

// void University::sortMenuEngine() {
//     MenuOption sortChoose = MenuOption::BaseMenu;
//     while (sortChoose != MenuOption::Back) {
//         printSortMenu();
//         sortChoose = sortMenuStudent();
//         switch (sortChoose) {
//             case MenuOption::SortByPESEL : {
//                 sortByPeselNumber();
//             } break;
//             case MenuOption::SortBySurname : {
//                 sortBySurname();
//             } break;
//             default :
//             break;
//         }

//     }
// }

// University::MenuOption University::sortMenuStudent() {
//     int choice = 0;
//     do {
//         std::cin >> choice;
//     } while (validatingSearchAndSortMenuChoose(choice) == false);
//     if (choice == 3) {
//         return MenuOption::Back;
//     }
//     return static_cast<MenuOption>(choice + 20);
// }

// void University::sortByPeselNumber() {
//     if (!person_.empty()) {
//         std::sort(person_.begin(), person_.end(), [&](auto const& lhs, auto const& rhs) {
//             return lhs.getPeselNumber() < rhs.getPeselNumber();
//         });
//         std::cout << "Database is sorted by PESEL number\n";
//     } else {
//         std::cout << "Database is empty\n";
//     }
// }

// void University::sortBySurname() {
//     if (!person_.empty()) {
//         std::sort(person_.begin(), person_.end(), [&](auto const& lhs, auto const& rhs) {
//             return lhs.getSurname() < rhs.getSurname();
//         });
//         std::cout << "Database is sorted by surname\n";
//     } else {
//         std::cout << "Database is empty\n";
//     }
// }

// void University::deleteByIndexNumber(std::string indexNumber) {
//     auto iterator = 0;
//     std::string answer;
//     for (auto& student : person_) {
//         iterator++;
//         if (student.getIndexNumber() == indexNumber) {
//             student.printStudent();
//             student.printBorderBotton();
//             break;
//         }
//     }
//     while (1) {
//         std::cout << "Do you wanna delete this record? Y/N: ";
//         if (yesNoOption() == YesNoOption::Yes) {
//             person_[iterator] = person_[person_.size() - 1];
//             person_.erase(person_.end() - 1);
//             break;
//         }
//         if (yesNoOption() == YesNoOption::No) {
//             break;
//         }
//     }
// }

std::string University::convertStudentGender(const size_t gender) {
    return gender == 0 ? "female" : "male";
}

University::YesNoOption University::yesNoOption() {
    char answer;
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y') {
        return YesNoOption::Yes;
    }
    if (answer == 'N' || answer == 'n') {
        return YesNoOption::No;
    }
    std::cout << "Wrong answer, you must choose Y or N\n";
    return YesNoOption::Error;
}
