#include "University.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <typeinfo>

#include "Professor.hpp"
#include "Student.hpp"

//to do
// sprawdzic czy osoba z takim peselem juz istnieje przy dodawaniu
// czy taki numer indexu istnieje
//
// generator danych
//

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
    while (menuEngine(printMenu()) != MenuOption::Exit) {

    }
}

size_t University::printMenu() {
    size_t optionNumber = 0;
    std::cout << " --------------------- \n";
    std::cout << "|  STUDENTS DATABASE  |\n";
    std::cout << " --------------------- \n";
    std::cout << ++optionNumber << ". Add student\n";
    std::cout << ++optionNumber << ". Show all students\n";
    std::cout << ++optionNumber << ". Search students \n";
    std::cout << ++optionNumber << ". Sort students \n";
    std::cout << ++optionNumber << ". Save/Load from file\n";
    std::cout << ++optionNumber << ". Generate data persons\n";
    std::cout << ++optionNumber << ". Delete record\n";
    std::cout << ++optionNumber << ". Exit\n\n";
    return optionNumber;
}

University::MenuOption University::menuEngine(size_t menuSize) {
    int choice = 0;
    do {
        std::cout << "Please insert you choice: ";
        std::cin >> choice;
    } while (validatingMenuChoose(choice, menuSize) == false);
    menuOption_ = static_cast<MenuOption>(choice);
    switch (menuOption_) {
    case MenuOption::AddStudents: {
        addNewStudent();
    } break;
    case MenuOption::ShowStudent: {
        showStudents();
    } break;
    case MenuOption::SearchStudents: {
        searchMenuEngine();
    } break;
    case MenuOption::SortStudents: {
        sortMenuEngine();
    } break;
    case MenuOption::SaveLoadFile: {
    } break;
    case MenuOption::GenerateData: {
    } break;
    case MenuOption::Delete: {
    } break;
    case MenuOption::Exit: {
    } break;
    default:
        break;
    }
    return menuOption_;
}

bool University::validatingMenuChoose(const size_t choosenValueToValid, const size_t sizeMenu) {
    if (std::cin.fail() || choosenValueToValid < 1 || choosenValueToValid > sizeMenu) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect value, please put number betwen 1 and " << sizeMenu << '\n';
        return false;
    }
    return true;
}

void University::addNewStudent() {
    selectPerson();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    insertStudentName();
    insertStudentSurname();
    insertStudentGender();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    insertAddress();
    insertStudentPeselNumber();
    if (userChoicePerson_ == WhichPerson::Student) {
        insertStudentIndexNumber();
    } else {
        insertProfessorSalary();
    }
    confirmAddRecord();
}

void University::selectPerson() {
    size_t userChoicePerson{};
    do {
        std::cout << "Which person you wanna add to database?\n";
        std::cout << "1.STUDENT | 2.PROFESSOR :";
        std::cin >> userChoicePerson;
    } while (validationSelectPerson(userChoicePerson) == false);
}

bool University::validationSelectPerson(size_t userChoicePerson) {
    if (userChoicePerson == 1 || userChoicePerson == 2) {
        assignmentPersonValue(userChoicePerson);
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Wrong answer, insert 1 or 2\n";
    return false;
}

void University::assignmentPersonValue(size_t userChoicePerson) {
    userChoicePerson_ = static_cast<University::WhichPerson>(userChoicePerson);
}

void University::printInsertPersonData() {
    std::cout << "Name: " << name_ << " | Surname: " << surname_ << " | Gender: " << convertPersonGender(gender_)
              << " | Address: " << address_ << " | PESEL: " << peselNumber_;
    if (userChoicePerson_ == WhichPerson::Student) {
        std::cout << " Student index Number: " << indexNumber_ << '\n';
    } else if (userChoicePerson_ == WhichPerson::Professor) {
        std::cout << " Professor salary: " << professorSalary_ << '\n';
    }
}

void University::confirmAddRecord() {
    while (true) {
        std::cout << "Are you sure you wanna add this record to database? Y/N ";
        if (yesNoOption() == YesNoOption::Yes && userChoicePerson_ == WhichPerson::Student) {
            person_.push_back(std::make_shared<Student>(Student(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), indexNumber_)));
            break;
        }
        if (yesNoOption() == YesNoOption::Yes && userChoicePerson_ == WhichPerson::Professor) {
            person_.push_back(std::make_shared<Professor>(Professor(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), professorSalary_)));
            break;
        }
        if (yesNoOption() == YesNoOption::No) {
            break;
        }
    }
}

void University::insertStudentName() {
    do {
        std::cout << "Please insert person name: ";
        std::getline(std::cin, name_);
    } while (validationStringSize(name_, sizeNameLimit_) == false || validationIsAlpabet(name_) == false);
}

void University::insertStudentSurname() {
    do {
        std::cout << "Please insert person surname: ";
        std::getline(std::cin, surname_);
    } while (validationStringSize(surname_, sizeSurnameLimit_) == false || validationIsAlpabet(surname_) == false);
}

void University::insertAddress() {
    do {
        std::cout << "Please insert person address: ";
        std::getline(std::cin, address_);
    } while (validationStringSize(address_, sizeAddressLimit_) == false);
}

void University::insertStudentIndexNumber() {
    do {
        std::cout << "Please insert student index number(10 digits): ";
        std::getline(std::cin, indexNumber_);
    } while (validationStringSize(indexNumber_, sizeIndexNumberLimit_, true) == false || validationIsDigit(indexNumber_) == false);
}

void University::insertProfessorSalary() {
    do {
        std::cout << "Please insert professor salary(max 5 digits): ";
        std::getline(std::cin, professorSalary_);
    } while (validationStringSize(professorSalary_, sizeSalaryLimit_) == false || validationIsDigit(professorSalary_) == false);
}

void University::insertStudentPeselNumber() {
    do {
        std::cout << "Please insert person PESEL number: ";
        std::getline(std::cin, peselNumber_);
    } while (validatingPeselNumber() == false || validationIsDigit(peselNumber_) == false || validationStringSize(peselNumber_, sizePeselNumberLimit_, true) == false);
}

void University::insertStudentGender() {
    do {
        std::cout << "Please choose gender: 1 - Male , 0 - Female: ";
        std::cin >> gender_;
    } while (validatingGender() == false);
}

bool University::validationIsAlpabet(std::string stringToCheck) {
    auto result = std::all_of(stringToCheck.begin(), stringToCheck.end(), [](auto character) {
        return std::isalpha(character);
    });
    if (result) {
        return true;
    }
    std::cout << "Insert data can be only alphabet\n";
    return false;
}

bool University::validationIsDigit(std::string stringToCheck) {
    auto result = std::all_of(stringToCheck.begin(), stringToCheck.end(), [](auto character) {
        return std::isdigit(character);
    });
    if (result) {
        return true;
    }
    std::cout << "Insert data can be only digit\n";
    return false;
}

bool University::validationStringSize(std::string userStringData, size_t maxSize, bool isEqual) {
    if (isEqual == false && userStringData.size() <= maxSize) {
        return true;
    }
    if (isEqual == true && userStringData.size() == maxSize) {
        return true;
    }
    if (isEqual == true) {
        std::cout << "Wrong length, value must have " << maxSize << " characters\n";
    }
    std::cout << "Length is to long, maximum length is " << maxSize << '\n';
    return false;
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
    corectPeselNumber = peselValidGenderCheck();
    corectPeselNumber = peselValidWithCurrentlyDate();
    corectPeselNumber = peselValidWithWeight();
    if (!corectPeselNumber) {
        std::cout << "Pesel number is incorrect\n";
    }
    return corectPeselNumber;
}

bool University::validatingGender() {
    if (gender_ != 0 && gender_ != 1) {
        std::cout << "Wrong value, please choose 0 or 1\n";
        return false;
    }
    return true;
}

void University::showStudents() {
    if (!person_.empty()) {
        person_[0]->getAddress();
        for (auto ele : person_) {
            ele->printPerson();
        }
        person_[0]->printBorderBotton();
    }
    std::cout << "Database of students is empty please load form file or add new students\n";
}

void University::saveToFile(size_t personIndex) {
    std::fstream file;
    file.open("records.txt", std::ios::out | std::ios::app);
    file << "[Person nr. : " << personIndex + 1 << "]\n";
    file << person_[personIndex]->getName() << "\n";
    file << person_[personIndex]->getSurname() << "\n";
    file << person_[personIndex]->getAddress() << "\n";
    file << person_[personIndex]->getPeselNumber() << "\n";
    file << person_[personIndex]->getIndexNumber() << "\n";
    file << person_[personIndex]->getSalary() << "\n\n";
    file.close();
}

void University::loadFromFile() {
    person_.reserve(countRecord());
    int lineNo = 1;
    std::string line;
    std::fstream file;
    file.open("records.txt", std::ios::in);
    if (file.good() == false) {
        std::cout << "File not exist\n";
    }
    while (getline(file, line)) {
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
                person_.push_back(std::make_shared<Professor>(Professor(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), professorSalary_)));
            } else {
                person_.push_back(std::make_shared<Student>(Student(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), indexNumber_)));
            }
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

void University::printSearchMenu() {
    std::cout << "SEARCH BY\n";
    std::cout << "1. Surname\n";
    std::cout << "2. PESEL number\n";
    std::cout << "3. Back to main menu\n";
    std::cout << "Insert your choice: ";
}

University::MenuOption University::searchMenuStudent() {
    int choice = 0;
    do {
        std::cin >> choice;
    } while (validatingSearchAndSortMenuChoose(choice) == false);
    if (choice == 3) {
        return MenuOption::Back;
    }
    return static_cast<MenuOption>(choice + 10);
}

void University::searchMenuEngine() {
    MenuOption searchChoose = MenuOption::BaseMenu;
    while (searchChoose != MenuOption::Back) {
        printSearchMenu();
        searchChoose = searchMenuStudent();
        switch (searchChoose) {
        case MenuOption::SearchBySurname: {
            searchBySurname();
        } break;
        case MenuOption::SearchByPESEL: {
            searchByPeselNumber();
        } break;
        default:
            break;
        }
    }
}

void University::whichPersonIs(Person* person) {
    std::shared_ptr<Person> currentlyPerson_(person);
    currentlyReadingRecord_ = University::WhichPerson::Anyone;  //TO DO
    if (person->getSalary().empty()) {
        currentlyReadingRecord_ = University::WhichPerson::Student;
        currentlyPerson_ = (std::make_shared<Student>(Student(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), indexNumber_)));

    } else {
        currentlyReadingRecord_ = University::WhichPerson::Professor;
        currentlyPerson_ = (std::make_shared<Professor>(Professor(name_, surname_, address_, peselNumber_, static_cast<Student::Gender>(gender_), professorSalary_)));
    }
}

bool University::validatingSearchAndSortMenuChoose(const int choosenValueToValid) {
    if (std::cin.fail() || choosenValueToValid < 1 || choosenValueToValid > 3) {
        std::cin.clear();
        std::cout << "Incorrect value, please put number betwen 1 and 3\n";
        return false;
    }
    return true;
}

void University::searchBySurname() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    checkIfExistSurname(insertSearchSurname());
}

void University::printSetSalaryMenu() {
    std::cout << "What you wanna do?\n";
    std::cout << "1. Change salary\n";
    std::cout << "2. Back\n";
}

size_t University::choiceSetSalary() {
    size_t userChoice{};
    while (userChoice != 1 && userChoice != 2) {
        std::cout << "Wrong answer, please insert 1 or 2.\n";
    }
    return userChoice;
}

void University::searchByPeselNumber() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (checkIfExistPeselNumber(insertSearchPeselNumber()) == true && currentlyReadingRecord_ == University::WhichPerson::Professor) {
        printSetSalaryMenu();
        choiceSetSalary();
    }
}

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

std::string University::insertSearchPeselNumber() {
    std::string insertPesel;
    do {
        std::cout << "Please insert searching PESEL number: ";
        std::getline(std::cin, insertPesel);
    } while (validatingPeselNumber() == false || validationIsDigit(peselNumber_) == false || validationStringSize(peselNumber_, sizePeselNumberLimit_, true) == false);
    return insertPesel;
}

bool University::checkIfExistPeselNumber(std::string pesel) {
    for (auto& person : person_) {
        if (person->getPeselNumber() == pesel) {
            person->printPerson();
            person->printBorderBotton();
            whichPersonIs(person.get());
            professorSalary_ = person->getSalary();
            return true;
        }
    }
    std::cout << "PESEL number don't exist in database\n\n";
    return false;
}

std::string University::insertSearchSurname() {
    std::string insertSurname;
    do {
        std::cout << "Please insert searching Surname: ";
        std::getline(std::cin, insertSurname);
    } while (validationStringSize(surname_, sizeSurnameLimit_) == false || validationIsAlpabet(surname_) == false);
    return insertSurname;
}

void University::checkIfExistSurname(std::string surname) {
    bool ifExistSurname = false;
    for (auto& person : person_) {
        if (person->getSurname() == surname) {
            person->printPerson();
            person->printBorderBotton();
            ifExistSurname = true;
            break;
        }
    }
    if (ifExistSurname == false) {
        std::cout << "Surname don't exist in database\n\n";
    }
}

void University::printSortMenu() {
    std::cout << "SORT BY\n";
    std::cout << "1. PESEL number\n";
    std::cout << "2. Surname number\n";
    std::cout << "3. Surname salary\n";
    std::cout << "4. Back to main menu\n";
    std::cout << "Insert your choice: ";
}

void University::sortMenuEngine() {
    MenuOption sortChoose = MenuOption::BaseMenu;
    while (sortChoose != MenuOption::Back) {
        printSortMenu();
        sortChoose = validationUserChoiceSortMenu();
        switch (sortChoose) {
        case MenuOption::SortByPESEL: {
            sortByPeselNumber();
        } break;
        case MenuOption::SortBySurname: {
            sortBySurname();
        } break;
        case MenuOption::SearchBySalary: {
            sortBySalary();
        } break;
        default:
            break;
        }
    }
}

University::MenuOption University::validationUserChoiceSortMenu() {
    int choice = 0;
    do {
        std::cin >> choice;
    } while (validatingSearchAndSortMenuChoose(choice) == false);
    if (choice == 4) {
        return MenuOption::Back;
    }
    return static_cast<MenuOption>(choice + 20);
}

void University::sortByPeselNumber() {
    if (!person_.empty()) {
        std::sort(person_.begin(), person_.end(), [&](auto const& lhs, auto const& rhs) {
            return lhs->getPeselNumber() < rhs->getPeselNumber();
        });
        std::cout << "Database is sorted by PESEL number\n";
    } else {
        std::cout << "Database is empty\n";
    }
}

void University::sortBySurname() {
    if (!person_.empty()) {
        std::sort(person_.begin(), person_.end(), [&](auto const& lhs, auto const& rhs) {
            return lhs->getSurname() < rhs->getSurname();
        });
        std::cout << "Database is sorted by surname\n";
    } else {
        std::cout << "Database is empty\n";
    }
}

void University::sortBySalary() {
    if (!person_.empty()) {
        std::sort(person_.begin(), person_.end(), [&](auto const& lhs, auto const& rhs) {
            return lhs->getSalary() > rhs->getSalary();
        });
        std::cout << "Database is sorted by salary\n";
    } else {
        std::cout << "Database is empty\n";
    }
}

void University::deleteByIndexNumber(std::string indexNumber) {
    auto iterator = 0;
    std::string answer;
    for (auto& person : person_) {
        iterator++;
        if (person->getIndexNumber() == indexNumber) {
            person->printPerson();
            person->printBorderBotton();
            break;
        }
    }
    while (true) {
        std::cout << "Do you wanna delete this record? Y/N: ";
        if (yesNoOption() == YesNoOption::Yes) {
            person_[iterator] = person_[person_.size() - 1];
            person_.erase(person_.end() - 1);
            break;
        }
        if (yesNoOption() == YesNoOption::No) {
            break;
        }
    }
}

std::string University::convertPersonGender(const size_t gender) {
    return gender == 0 ? "female" : "male";
}

University::YesNoOption University::yesNoOption() {
    std::string answer;
    std::getline(std::cin, answer);
    if (answer == "Y" || answer == "y") {
        return YesNoOption::Yes;
    }
    if (answer == "N" || answer == "n") {
        return YesNoOption::No;
    }
    std::cout << "Wrong answer, you must choose Y or N\n";
    return YesNoOption::Error;
}

void University::printSaveLoadMenu() {
    size_t optionNumber = 0;
    std::cout << ++optionNumber << ". Save(add to currently file new records (delete duplicate)\n";
    std::cout << ++optionNumber << ". Save to new file \n";
    std::cout << ++optionNumber << ". Clear data and load new data from file \n";
    std::cout << ++optionNumber << ". Load from file and add records to existing file (delete duplicate)\n";
    std::cout << ++optionNumber << ". Back\n";
}

