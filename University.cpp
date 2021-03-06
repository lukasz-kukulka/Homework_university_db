#include "University.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <typeinfo>
#include <iterator>
#include <limits>
#include <random>

#include "Professor.hpp"
#include "Student.hpp"

constexpr char currentlyDate[] = "13082021";  // FORMAT DATE DDMMYYYY

// University::University() {

// }
void University::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
}

void University::applicationStart() {
    
    while (menuEngine(printMenu()) != MenuOption::Exit) {

    }
}

///////////////////////////////////////
// size_t University::printMenu() {
//     size_t optionNumber = 0;
//     std::cout << " --------------------- \n";
//     std::cout << "|  STUDENTS DATABASE  |\n";
//     std::cout << " --------------------- \n";
//     std::cout << ++optionNumber << ". Add studentTEST\n";
//     std::cout << ++optionNumber << ". Show all students\n";
//     std::cout << ++optionNumber << ". Search students \n";
//     std::cout << ++optionNumber << ". Sort students \n";
//     std::cout << ++optionNumber << ". Save/Load from file\n";
//     std::cout << ++optionNumber << ". Generate data persons\n";
//     std::cout << ++optionNumber << ". Delete record\n";
//     std::cout << ++optionNumber << ". Exit\n\n";
//     return optionNumber;
// }
/////////////////////////////////////////

/////////////////////////////////////////////////////
// University::MenuOption University::menuEngine(size_t menuSize) {
//     int choice = 0;
//     do {
//         std::cout << "Please insert you choice: ";
//         std::cin >> choice;
//     } while (validatingMenuChoose(choice, menuSize) == false);
//     menuOption_ = static_cast<MenuOption>(choice);
//     switch (menuOption_) {
//     case MenuOption::AddStudents: {
//         addNewPerson();
//     } break;
//     case MenuOption::ShowStudent: {
//         showStudents();
//     } break;
//     case MenuOption::SearchStudents: {
//         searchMenuEngine();
//     } break;
//     case MenuOption::SortStudents: {
//         sortMenuEngine();
//     } break;
//     case MenuOption::SaveLoadFile: {
//         loadSaveMenu();
//     } break;
//     case MenuOption::GenerateData: {
//         printInterfaceDataGenerator();
//     } break;
//     case MenuOption::Delete: {
//         deleteRecordByIndexNumber();
//     } break;
//     case MenuOption::Exit: {
//     } break;
//     default:
//         break;
//     }
//     return menuOption_;
// }
////////////////////////////////////////////////////////////////

// bool University::validatingMenuChoose(const size_t choosenValueToValid, const size_t sizeMenu) {
//     if (std::cin.fail() || choosenValueToValid < 1 || choosenValueToValid > sizeMenu) {
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         std::cout << "Incorrect value, please put number betwen 1 and " << sizeMenu << '\n';
//         return false;
//     }
//     return true;
// }

// void University::deleteRecordByIndexNumber() {
//     printDeletePersonByIndexNumber();
//     insertStudentIndexNumber();
//     deleteByIndexNumber(indexNumber_);
// }

// void University::printDeletePersonByIndexNumber() {
//     std::cout << "Please insert index number what you wanna delete\n";
// }

// void University::addNewPerson() {
//     selectPerson();
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     insertStudentName();
//     insertStudentSurname();
//     insertStudentGender();
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     insertAddress();
//     insertStudentPeselNumber();
//     if (userChoicePerson_ == WhichPerson::Student) {
//         insertStudentIndexNumber();
//     } else {
//         insertProfessorSalary();
//     }
//     confirmAddRecord();
// }

// void University::selectPerson() {
//     size_t userChoicePerson{};
//     do {
//         std::cout << "Which person you wanna add to database?\n";
//         std::cout << "1.STUDENT | 2.PROFESSOR :";
//         std::cin >> userChoicePerson;
//     } while (validationSelectPerson(userChoicePerson) == false);
// }

// void University::ifPersonExistMenu() {
//     do {

//     } while (ifPersonExist(printMenuIfPersonExist()) != IfPersonExist::Back);
// }

// size_t University::printMenuIfPersonExist() {
//     size_t optionNumber = 0;
//     std::cout << "Person already exist, what you wanna do?\n";
//     std::cout << ++optionNumber << ". Compare records\n";
//     std::cout << ++optionNumber << ". Update data\n";
//     std::cout << ++optionNumber << ". Keep original\n";
//     std::cout << ++optionNumber << ". Edit data\n";
//     std::cout << ++optionNumber << ". Back\n\n";
//     return optionNumber; 
// }

// University::IfPersonExist University::ifPersonExist(size_t menuSize) {
//     int choice = 0;
//     do {
//         std::cout << "Please insert you choice: ";
//         std::cin >> choice;
//     } while (validatingMenuChoose(choice, menuSize) == false);
//     userChoiceIfExist_ = static_cast<IfPersonExist>(choice);
//     switch (userChoiceIfExist_) {
//     case IfPersonExist::Compare : {
//         ifExistCompare();
//     } break;
//     case IfPersonExist::Update : {
//         updateRecordIfPersonExist();
//         userChoiceIfExist_ = IfPersonExist::Back;
//     } break;
//     case IfPersonExist::KeepOriginal: {
//         userChoiceIfExist_ = IfPersonExist::Back;
//     } break;
//     case IfPersonExist::Edit : {
//         addNewPerson();
//     } break;
//     case IfPersonExist::Back : {
//         userChoiceIfExist_ = IfPersonExist::Back;
//     } break;
//     default:
//         break;
//     }
//     return userChoiceIfExist_;
// }

// void University::ifExistCompare() {
//     std::cout << "INPUT DATA:                    Name: " << name_ 
//               << " | Surname: " << surname_ 
//               << " | Address: " << address_ 
//               << " | Index number: " << indexNumber_ 
//               << " | PESEL number: " << peselNumber_ 
//               << " | Salary: " << professorSalary_
//               << " | Gender: " << convertPersonGender(gender_) << '\n';
//     std::cout << "EXISTING DATA(ORIGINAL):       Name: " << checkedIfPersonExist_->get()->getName()
//               << " | Surname: " << checkedIfPersonExist_->get()->getSurname()
//               << " | Address: " << checkedIfPersonExist_->get()->getAddress()
//               << " | Index number: " << checkedIfPersonExist_->get()->getIndexNumber() 
//               << " | PESEL number: " << checkedIfPersonExist_->get()->getPeselNumber()
//               << " | Salary: " << checkedIfPersonExist_->get()->getSalary()
//               << " | Gender: " << checkedIfPersonExist_->get()->getGender() << '\n';
// }

// void University::updateRecordIfPersonExist() {
//     if (userChoicePerson_ == WhichPerson::Student) {
//         addStudentRecordToVector();
//     }
//     if (userChoicePerson_ == WhichPerson::Professor) {
//         addProfesorRecordToVector();
//     }
//     (end(person_) - 1)->swap(*checkedIfPersonExist_);
//     person_.erase(end(person_) - 1);
// }

// void University::addStudentRecordToVector() {
//     //person_.push_back(std::make_shared<Student>(Student(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), indexNumber_)));
// }

// void University::addProfesorRecordToVector() {
//     //person_.push_back(std::make_shared<Professor>(Professor(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), professorSalary_)));
// }

// std::vector<std::shared_ptr<Person>>::iterator University::isPersonExist() {
//     return std::find_if(begin(person_), 
//                         end(person_), 
//                         [&](auto finding){ 
//                                         return (finding->getPeselNumber() == peselNumber_ || 
//                                                 (finding->getIndexNumber() == indexNumber_ && 
//                                                 (!indexNumber_.empty()))); });
// }

// bool University::validationSelectPerson(size_t userChoicePerson) {
//     if (userChoicePerson == 1 || userChoicePerson == 2) {
//         assignmentPersonValue(userChoicePerson);
//         return true;
//     }
//     std::cout << "Wrong answer, insert 1 or 2\n";
//     std::cin.clear();
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     return false;
// }

void University::assignmentPersonValue(size_t userChoicePerson) {
    userChoicePerson_ = static_cast<University::WhichPerson>(userChoicePerson);
}

// void University::printInsertPersonData() {
//     std::cout << "Name: " << name_ << " | Surname: " << surname_ << " | Gender: " << convertPersonGender(gender_)
//               << " | Address: " << address_ << " | PESEL: " << peselNumber_;
//     if (userChoicePerson_ == WhichPerson::Student) {
//         std::cout << " Student index Number: " << indexNumber_ << '\n';
//     } else if (userChoicePerson_ == WhichPerson::Professor) {
//         std::cout << " Professor salary: " << professorSalary_ << '\n';
//     }
// }

// void University::confirmAddRecord() {
//     while (true) {
//         checkedIfPersonExist_ = isPersonExist();
//         std::cout << "Are you sure you wanna add this record to database? Y/N:";
//         if (yesNoOption() == YesNoOption::Yes && userChoicePerson_ == WhichPerson::Student) {
//             if (checkedIfPersonExist_ != end(person_)) {
//                 ifPersonExistMenu();
//                 break;
//             }
//             addStudentRecordToVector();
//             break;
//         }
//         if (yesNoOption() == YesNoOption::Yes && userChoicePerson_ == WhichPerson::Professor) {
//             addProfesorRecordToVector();
//             break;
//         }
//         if (yesNoOption() == YesNoOption::No) {
//             break;
//         }
//     }
// }

// void University::insertStudentName() {
//     do {
//         std::cout << "Please insert person name: ";
//         std::getline(std::cin, name_);
//     } while (validationStringSize(name_, sizeNameLimit_) == false || validationIsAlpabet(name_) == false);
// }

// void University::insertStudentSurname() {
//     do {
//         std::cout << "Please insert person surname: ";
//         std::getline(std::cin, surname_);
//     } while (validationStringSize(surname_, sizeSurnameLimit_) == false || validationIsAlpabet(surname_) == false);
// }

// void University::insertAddress() {
//     do {
//         std::cout << "Please insert person address: ";
//         std::getline(std::cin, address_);
//     } while (validationStringSize(address_, sizeAddressLimit_) == false);
// }

// void University::insertStudentIndexNumber() {
//     do {
//         std::cout << "Please insert student index number(10 digits): ";
//         std::getline(std::cin, indexNumber_);
//     } while (validationStringSize(indexNumber_, sizeIndexNumberLimit_, true) == false || validationIsDigit(indexNumber_) == false);
// }

// void University::insertProfessorSalary() {
//     do {
//         std::cout << "Please insert professor salary(max 5 digits): ";
//         std::getline(std::cin, professorSalary_);
//     } while (validationStringSize(professorSalary_, sizeSalaryLimit_) == false || validationIsDigit(professorSalary_) == false);
// }

// void University::insertStudentPeselNumber() {
//     do {
//         std::cout << "Please insert person PESEL number: ";
//         std::getline(std::cin, peselNumber_);
//     } while (validatingPeselNumber() == false || validationIsDigit(peselNumber_) == false || validationStringSize(peselNumber_, sizePeselNumberLimit_, true) == false);
// }

// void University::insertStudentGender() {
//     do {
//         std::cout << "Please choose gender: 1 - Male , 0 - Female: ";
//         std::cin >> gender_;
//     } while (validatingGender() == false);
// }

// bool University::validationIsAlpabet(std::string stringToCheck) {
//     auto result = std::all_of(stringToCheck.begin(), stringToCheck.end(), [](auto character) {
//         return std::isalpha(character);
//     });
//     if (result) {
//         return true;
//     }
//     std::cout << "Insert data can be only alphabet\n";
//     return false;
// }

// bool University::validationIsDigit(std::string stringToCheck) {
//     auto result = std::all_of(stringToCheck.begin(), stringToCheck.end(), [](auto character) {
//         return std::isdigit(character);
//     });
//     if (result) {
//         return true;
//     }
//     std::cout << "Insert data can be only digit\n";
//     return false;
// }

// bool University::validationStringSize(std::string userStringData, size_t maxSize, bool isEqual) {
//     if (isEqual == false && userStringData.size() <= maxSize) {
//         return true;
//     }
//     if (isEqual == true && userStringData.size() == maxSize) {
//         return true;
//     }
//     if (isEqual == true) {
//         std::cout << "Wrong length, value must have " << maxSize << " characters\n";
//     }
//     std::cout << "Length is to long, maximum length is " << maxSize << '\n';
//     return false;
// }

// bool University::peselValidDOBCheck() {
//     if ((peselNumber_[2] == '1' || peselNumber_[2] == '3' || peselNumber_[2] == '5' || peselNumber_[2] == '7' || peselNumber_[2] == '9') && peselNumber_[2] != '0' && peselNumber_[2] != '1' && peselNumber_[2] != '2') {
//         return false;
//     }
//     if (peselNumber_[4] != '0' && peselNumber_[4] != '1' && peselNumber_[4] != '2' && peselNumber_[4] != '3') {
//         return false;
//     }
//     if (peselNumber_[4] == '3' && peselNumber_[5] != '0' && peselNumber_[5] != '1' && peselNumber_[5] != '2') {
//         return false;
//     }
//     return true;
// }

// bool University::peselValidGenderCheck() {
//     if (static_cast<size_t>(peselNumber_[9]) % 2 != static_cast<size_t>(gender_)) {
//         return false;
//     }
//     return true;
// }

// bool University::peselValidWithCurrentlyDate() {
//     if (currentlyDate[5] == '0' && (peselNumber_[2] == '4' || peselNumber_[2] == '5' || peselNumber_[2] == '6' || peselNumber_[2] == '7')) {
//         return false;
//     }
//     if (currentlyDate[5] == '1' && (peselNumber_[2] == '6' || peselNumber_[2] == '7')) {
//         return false;
//     }
//     return true;
// }

// bool University::peselValidWithWeight() {
//     std::string weightCheck = "13791379131";
//     size_t weightResult = 0;
//     for (int i = 0; i < 10; i++) {
//         weightResult = weightResult + (static_cast<size_t>(peselNumber_[i] - '0') * (static_cast<size_t>(weightCheck[i] - '0')));
//     }
//     weightResult = weightResult % 10;
//     if (weightResult == 0) {
//         weightResult = 0;
//     } else {
//         weightResult = 10 - weightResult;
//     }
//     if (static_cast<size_t>(peselNumber_[10] - '0') != weightResult) {
//         return false;
//     }
//     return true;
// }

// bool University::validatingPeselNumber() {
//     bool corectPeselNumber = true;
//     corectPeselNumber = peselValidDOBCheck();
//     corectPeselNumber = peselValidWithCurrentlyDate();
//     corectPeselNumber = peselValidWithWeight();
//     if (!corectPeselNumber) {
//         std::cout << "Pesel number is incorrect\n";
//     }
//     return corectPeselNumber;
// }

// bool University::validatingGender() {
//     if (gender_ != 0 && gender_ != 1) {
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         std::cout << "Wrong value, please choose 0 or 1\n";
//         return false;
//     }
//     return true;
// }

// void University::showStudents() {
//     if (!person_.empty()) {
//         person_[0]->printBorderLine();
//         person_[0]->printBorderTop();
//         for (auto ele : person_) {
//             person_[0]->printBorderLine();
//             ele->printPerson();
//         }
//         person_[0]->printBorderLine();
//     }
//     std::cout << "Database of students is empty please load form file or add new students\n";
// }

// int University::countRecord(std::string fileMane) { 
//     int lineNo = 0;
//     std::string line;
//     file_.open(fileMane, std::ios::in);
//     if (file_.good() == false) {
//         std::cout << "File not exist\n";
//     }
//     while (getline(file_, line)) {
//         lineNo++;
//     }
//     file_.close();
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
//         case MenuOption::SearchBySurname: {
//             searchBySurname();
//         } break;
//         case MenuOption::SearchByPESEL: {
//             searchByPeselNumber();
//         } break;
//         default:
//             break;
//         }
//     }
// }

// void University::whichPersonIs(Person* person) {
//     std::shared_ptr<Person> currentlyPerson_(person);
//     currentlyReadingRecord_ = University::WhichPerson::Anyone;  //TO DO
//     if (person->getSalary().empty()) {
//         currentlyReadingRecord_ = University::WhichPerson::Student;
//         currentlyPerson_ = (std::make_shared<Student>(Student(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), indexNumber_)));

//     } else {
//         currentlyReadingRecord_ = University::WhichPerson::Professor;
//         currentlyPerson_ = (std::make_shared<Professor>(Professor(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), professorSalary_)));
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

// void University::searchBySurname() {
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     checkIfExistSurname(insertSearchSurname());
// }

// void University::printSetSalaryMenu() {
//     std::cout << "What you wanna do?\n";
//     std::cout << "1. Change salary\n";
//     std::cout << "2. Back\n";
// }

// size_t University::choiceSetSalary() {
//     size_t userChoice{};
//     while (userChoice != 1 && userChoice != 2) {
//         std::cout << "Wrong answer, please insert 1 or 2.\n";
//     }
//     return userChoice;
// }

// void University::searchByPeselNumber() {
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
//     if (checkIfExistPeselNumber(insertSearchPeselNumber()) == true && currentlyReadingRecord_ == University::WhichPerson::Professor) {
//         printSetSalaryMenu();
//         choiceSetSalary();
//     }
// }

void University::salaryOptions(size_t userChoice) {
    std::string newSalary{};
    if (userChoice == 1) {
        do {
            std::cout << "Insert new salary: ";
            std::cin >> newSalary;
        } while (validationStringSize(professorSalary_, sizeSalaryLimit_) == false || validationIsDigit(professorSalary_) == false);
        changingSalary(newSalary);
    }
}

void University::changingSalary(std::string newSalary) {
    currentlyPerson_->setSalary(newSalary);
}

// std::string University::insertSearchPeselNumber() {
//     std::string insertPesel;
//     do {
//         std::cout << "Please insert searching PESEL number: ";
//         std::getline(std::cin, insertPesel);
//     } while (validatingPeselNumber() == false || validationIsDigit(peselNumber_) == false || validationStringSize(peselNumber_, sizePeselNumberLimit_, true) == false);
//     return insertPesel;
// }

// bool University::checkIfExistPeselNumber(std::string pesel) {
//     for (auto& person : person_) {
//         if (person->getPeselNumber() == pesel) {
//             person->printPerson();
//             person->printBorderLine();
//             whichPersonIs(person.get());
//             professorSalary_ = person->getSalary();
//             return true;
//         }
//     }
//     std::cout << "PESEL number don't exist in database\n\n";
//     return false;
// }

// std::string University::insertSearchSurname() {
//     std::string insertSurname;
//     do {
//         std::cout << "Please insert searching Surname: ";
//         std::getline(std::cin, insertSurname);
//     } while (validationStringSize(surname_, sizeSurnameLimit_) == false || validationIsAlpabet(surname_) == false);
//     return insertSurname;
// }

// void University::checkIfExistSurname(std::string surname) {
//     bool ifExistSurname = false;
//     for (auto& person : person_) {
//         if (person->getSurname() == surname) {
//             person->printPerson();
//             person->printBorderLine();
//             ifExistSurname = true;
//             break;
//         }
//     }
//     if (ifExistSurname == false) {
//         std::cout << "Surname don't exist in database\n\n";
//     }
// }

// void University::printSortMenu() {
//     std::cout << "SORT BY\n";
//     std::cout << "1. PESEL number\n";
//     std::cout << "2. Surname number\n";
//     std::cout << "3. Surname salary\n";
//     std::cout << "4. Back to main menu\n";
//     std::cout << "Insert your choice: ";
// }

// void University::sortMenuEngine() {
//     MenuOption sortChoose = MenuOption::BaseMenu;
//     while (sortChoose != MenuOption::Back) {
//         printSortMenu();
//         sortChoose = validationUserChoiceSortMenu();
//         switch (sortChoose) {
//         case MenuOption::SortByPESEL: {
//             sortByPeselNumber();
//         } break;
//         case MenuOption::SortBySurname: {
//             sortBySurname();
//         } break;
//         case MenuOption::SearchBySalary: {
//             sortBySalary();
//         } break;
//         default:
//             break;
//         }
//     }
// }

// University::MenuOption University::validationUserChoiceSortMenu() {
//     int choice = 0;
//     do {
//         std::cin >> choice;
//     } while (validatingSearchAndSortMenuChoose(choice) == false);
//     if (choice == 4) {
//         return MenuOption::Back;
//     }
//     return static_cast<MenuOption>(choice + 20);
// }

// void University::sortByPeselNumber() {
//     if (!person_.empty()) {
//         std::sort(person_.begin(), person_.end(), [&](auto const& lhs, auto const& rhs) {
//             return lhs->getPeselNumber() < rhs->getPeselNumber();
//         });
//         std::cout << "Database is sorted by PESEL number\n";
//     } else {
//         std::cout << "Database is empty\n";
//     }
// }

// void University::sortBySurname() {
//     if (!person_.empty()) {
//         std::sort(person_.begin(), person_.end(), [&](auto const& lhs, auto const& rhs) {
//             return lhs->getSurname() < rhs->getSurname();
//         });
//         std::cout << "Database is sorted by surname\n";
//     } else {
//         std::cout << "Database is empty\n";
//     }
// }

// void University::sortBySalary() {
//     if (!person_.empty()) {
//         std::sort(person_.begin(), person_.end(), [&](auto const& lhs, auto const& rhs) {
//             return lhs->getSalary() > rhs->getSalary();
//         });
//         std::cout << "Database is sorted by salary\n";
//     } else {
//         std::cout << "Database is empty\n";
//     }
// }

// void University::deleteByIndexNumber(std::string indexNumber) {
//     auto iterator = 0;
//     std::string answer;
//     for (auto& person : person_) {
//         iterator++;
//         if (person->getIndexNumber() == indexNumber) {
//             person->printPerson();
//             person->printBorderLine();
//             break;
//         }
//     }
//     while (true) {
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

// std::string University::convertPersonGender(const size_t gender) {
//     return gender == 0 ? "female" : "male";
// }

// University::YesNoOption University::yesNoOption() {
//     std::string answer { };
//     std::cin.clear();
//     std::getline(std::cin, answer);
//     if (answer == "Y" || answer == "y") {
//         return YesNoOption::Yes;
//     }
//     if (answer == "N" || answer == "n") {
//         return YesNoOption::No;
//     }
//     std::cout << "Wrong answer, you must choose Y or N\n";
//     return YesNoOption::Error;
// }

void University::loadSaveMenu() {
    while (menuLoadSaveEngine(printSaveLoadMenu()) != LoadSaveOption::Back) {

    }
}

size_t University::printSaveLoadMenu() {
    size_t optionNumber = 0;
    std::cout << ++optionNumber << ". Save(add to currently file new records (delete duplicate)\n";
    std::cout << ++optionNumber << ". Save to new file \n";
    std::cout << ++optionNumber << ". Clear existing data and load new data from file \n";
    std::cout << ++optionNumber << ". Load from file and add records to existing file (delete duplicate)\n";
    std::cout << ++optionNumber << ". Back\n";
    return optionNumber;
}

University::LoadSaveOption University::menuLoadSaveEngine(size_t menuSize) {
    int choice = 0;
    do {
        std::cout << "Please insert you choice: ";
        std::cin >> choice;
    } while (validatingMenuChoose(choice, menuSize) == false);
    userChoiceLoadSave_ = static_cast<LoadSaveOption>(choice);
    switch (userChoiceLoadSave_) {
    case LoadSaveOption::Save : {
        saveAllFile();
    } break;
    case LoadSaveOption::SaveNew : {
        saveNew();
    } break;
    case LoadSaveOption::ClearLoad : {
        clearLoad();
    } break;
    case LoadSaveOption::LoadToExist : {
        loadToExist();
    } break;
    case LoadSaveOption::Back : {
    } break;
    default:
        break;
    }
    return userChoiceLoadSave_;
}

void University::loadToExist() {
    printLoadToExist();
    userInsertFileName();
    std::vector<std::shared_ptr<Person>>personCopy_;
    copyDataToTempContanair(personCopy_);
    loadFromFile(fileName_);
    deleteDuplicate();
}

void University::deleteDuplicate() {
    std::sort(begin(person_), end(person_), [](auto a, auto b){ return a->getPeselNumber() < b->getPeselNumber(); });
    person_.erase(std::unique(begin(person_), end(person_), [](auto a, auto b){ return a->getPeselNumber() == b->getPeselNumber(); }), end(person_));
}

std::vector<std::shared_ptr<Person>> University::copyDataToTempContanair(std::vector<std::shared_ptr<Person>>& personCopy) {
    std::copy(begin(person_), end(person_), std::back_inserter(personCopy));
    return personCopy;
}

void University::printLoadToExist() {
    std::cout << "Please insert file name\n";
    std::cout << "You will don't currently data\n";
    std::cout << "All duplicate will delete\n";
}

void University::saveNew() {
    printSaveInNewFile();
    userInsertFileName();
    saveInNewFile();
}

void University::saveAllFile(std::string fileName) {
    std::string file = fileName;
    if (fileName != DEFAULT_FILE_NAME) {
        file += ".txt";
        file_.open(file, std::ios::out | std::ios::trunc);
    } else {
        file_.open(file, std::ios::out | std::ios::app);
    }
    //std::ofstream file("records.txt");
    //std::copy(begin(person_), end(person_), std::ostream_iterator<std::string>(file_, " ")));
    if (!file_.good()) {
        std::cout << "ERROR IN addOneRecordToEndFile() function\n";
    }
    for (size_t i = 0; i < person_.size(); i++) {
        addOneRecordToEndFile(i, file_);
    }
    std::cout << "Data saved in file\n";
    file_.close();
}

void University::printSaveInNewFile() {
    std::cout << "Please insert file name\n";
    std::cout << "All files will saving in .txt format\n";
    std::cout << "You need put ONLY name, without format\n";

}

void University::userInsertFileName() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, fileName_);
}

void University::saveInNewFile() {
    saveAllFile(fileName_); 
}

size_t University::saveNewIfFileExist() {
    printIfFileExist();
    size_t userChoice = userChoiceIfFileExist();
    return userChoice;
}

void University::printIfFileExist() {
    std::cout << "File exist\n";
    std::cout << "What you wanna do:\n";
    std::cout << "1. Add records to end file\n";
    std::cout << "2. Replace file\n";
}

size_t University::userChoiceIfFileExist() {
    size_t userChoice = 0;
    std::cout << "Your choice: ";
    std::cin >> userChoice;
    validationIfFileExist(userChoice);
    return userChoice;
}

void University::validationIfFileExist(size_t userChoice) {
    while (true) {
        if (!std::cin.fail() && (userChoice == 1 || userChoice == 2)) {
            break;
        }
        std::cout << "Wrong value please insert again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void University::addOneRecordToEndFile(size_t personIndex, std::fstream & file) {
    file << "[Person nr. : " << personIndex + 1 << "]\n";
    file << person_[personIndex]->getName() << "\n";
    file << person_[personIndex]->getSurname() << "\n";
    file << person_[personIndex]->getAddress() << "\n";
    file << person_[personIndex]->getPeselNumber() << "\n";
    file << person_[personIndex]->getIndexNumber() << "\n";
    file << person_[personIndex]->getSalary() << "\n\n";
}

void University::clearVector() {
    person_.clear();
}

void University::clearLoad() {
    printClearLoadMenu();
    userInsertFileName();
    loadFromFile(fileName_);
    clearVector();
}

void University::printClearLoadMenu() {
    std::cout << "Please insert file name to load: ";
}

void University::loadFromFile(std::string fileName) {
    // std::ifstream file("records.txt");
    // std::vector<uint16_t> vec;
    // std::copy(std::istream_iterator<uint16_t>(file_), std::istream_iterator<uint16_t>{}, std::back_inserter(vec));
    person_.reserve(countRecord());
    int lineNo = 1;
    std::string line;
    file_.open(fileName, std::ios::in);
    if (file_.good() == false) {
        std::cout << "File not exist\n";
    }
    while (getline(file_, line)) {
        switch (lineNo) {
        case 2: {
            name_ = line;
        } break;
        case 3: {
            surname_ = line;
        } break;
        case 4: {
            address_ = line;
        } break;
        case 5: {
            peselNumber_ = line;
        } break;
        case 6: {
            line.size() == 4 ? gender_ = 1 : gender_ = 0;
        } break;
        case 7: {
            indexNumber_ = line;
        } break;
        case 8: {
            professorSalary_ = line;
        } break;
        default: {
        } break;
        }
        lineNo++;
        if (lineNo > 9) {
            lineNo = 1;
            
            if (indexNumber_.size() < 1) {
                addProfesorRecordToVector();
            } else {
                addStudentRecordToVector();
            }
        }
    }
    file_.close();
}

void University::printInterfaceDataGenerator() {
   std::cout << "Please insert how many records you wanna generate\n";
   std::cout << "Students ";
   interfaceDataGeneratorStudent();
   std::cout << "Professors ";
   interfaceDataGeneratorProfessor();
}

void University::interfaceDataGeneratorStudent() {
    studentDataGenerator(interfaceDataGeneratorAll()) ;
}

void University::interfaceDataGeneratorProfessor() {
    professorDataGenerator(interfaceDataGeneratorAll());
}

size_t University::interfaceDataGeneratorAll() {
    size_t amount = 0;
    do { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> amount;
    } while (std::cin.fail());
    return amount;
}

void University::dataGenerator() {
    nameGenerator(); 
    surnameGenerator();
    addressGenerator();
    indexNumberGenerator();
    peselNumberGenerator();
    professorSalaryGenerator();
    genderGenerator();
}

void University::studentDataGenerator(size_t dataAmout) {
    for (size_t i = 0; i < dataAmout; i++){
        dataGenerator();
        addStudentRecordToVector(); 
    }
}

void University::professorDataGenerator(size_t dataAmout) {
    for (size_t i = 0; i < dataAmout; i++){
        dataGenerator();
        addProfesorRecordToVector();
    } 
}

std::string University::randomDataLoader(std::string fileName, size_t recordNumber) {
    std::string line;
    size_t lineNumber = 0;
    file_.open(fileName, std::ios::in);
    if (file_.good() == false) {
        std::cout << "File not exist\n";
    }
    while (getline(file_, line)) {
        if (lineNumber == recordNumber) {
            file_.close();
            return line;
        }
        lineNumber++;
    }
    file_.close();
    return "ERROR_NO_RECORD";
}

void University::nameGenerator() {
    std::string fileName = "DataGenerate/names.txt";
    name_ = randomDataLoader(fileName, randomDataGenerator(1, countRecordGenerateData(fileName) - 1));
}

void University::surnameGenerator() {
    std::string fileName = "DataGenerate/surnames.txt";
    surname_ = randomDataLoader(fileName, randomDataGenerator(1, countRecordGenerateData(fileName) - 1));
}

void University::addressGenerator() {
    std::string fileName = "DataGenerate/streets.txt";
    address_ = randomDataLoader(fileName, randomDataGenerator(1, countRecordGenerateData(fileName) - 1));
    address_ = address_ + " " + std::to_string(randomDataGenerator(1, 150));
}

void University::indexNumberGenerator() {
    indexNumber_ = std::to_string(randomDataGenerator(1000000000, 3333999999));
}

void University::peselNumberGenerator() {
    peselNumber_ = "";
    peselNumber_ = peselNumber_ + std::to_string(randomDataGenerator(1, 9));
    peselNumber_ += std::to_string(randomDataGenerator(1, 9));
    peselNumber_ += std::to_string(randomDataGenerator(10, 12));
    peselNumber_ += std::to_string(randomDataGenerator(10, 30));
    peselNumber_ += std::to_string(randomDataGenerator(1111, 9999));
    peselNumber_ += generateWeightPeselNumber(peselNumber_);
}

std::string University::generateWeightPeselNumber(std::string pesel) {
    std::string weightCheck = "13791379131";
    size_t weightResult = 0;
    for (size_t i = 0; i < pesel.size(); i++) {
        weightResult = weightResult + (static_cast<size_t>(pesel[i] - '0') * (static_cast<size_t>(weightCheck[i] - '0')));
    }
    weightResult = weightResult % 10;
    if (weightResult == 0) {
        weightResult = 0;
    } else {
        weightResult = 10 - weightResult;
    }
    return std::to_string(weightResult);
}

void University::professorSalaryGenerator() {
    professorSalary_ = std::to_string(randomDataGenerator(3000, 10000));
}

void University::genderGenerator() {
    gender_ = static_cast<size_t>(peselNumber_[9] - '0') % 2;
}

size_t University::randomDataGenerator(size_t minElement, size_t maxElement) {
    std::random_device seed;
    std::mt19937 randomNumber{seed()}; 
    std::uniform_int_distribution<size_t> range(minElement, maxElement);
    return range(randomNumber);
}

size_t University::countRecordGenerateData(std::string fileMane) { 
    int lineNo = 0;
    std::string line;
    file_.open(fileMane, std::ios::in);
    if (file_.good() == false) {
        std::cout << "File not exist\n";
    }
    while (getline(file_, line)) {
        lineNo++;
        if (line.size() == 0) {
            lineNo--;
        }
    }
    file_.close();
    return lineNo;
}
