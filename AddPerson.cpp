#include "AddPerson.hpp"
#include "Student.hpp"
#include "Professor.hpp"
#include "Student.hpp"

#include <exception>
#include <ios> // streamsize
#include <iostream>
#include <limits> // numeric limits

AddPerson::AddPerson(std::shared_ptr<ValidationData> validation) 
    : validation_(validation)
{
}

void AddPerson::operator()(std::vector<std::shared_ptr<Person>>& person)  {
    std::cout << "ADD PERSON HERE\n"; //TO DELETE 
    do {
        whichPerson_ = selectPerson();
        if (whichPerson_ == WhichPerson::Back) {
            break;
        }
        generateData();
        confirmAddRecord(person);
    } while (true);
}

AddPerson::WhichPerson AddPerson::selectPerson()  {
    size_t userChoicePerson{};
    int optionNumber { };
    do {
        optionNumber = 0;
        std::cout << "Which person you wanna add to database?\n";
        std::cout << ++optionNumber << ". STUDENT\n";
        std::cout << ++optionNumber << ". PROFESSOR\n";
        std::cout << ++optionNumber << ". BACK\n";
        std::cin >> userChoicePerson;
    } while (validation_->isCorrectMenuChoice(userChoicePerson, optionNumber) == false);
    //std::cout << "tests\n";
    return static_cast<WhichPerson>(userChoicePerson);
}

std::string AddPerson::insertPersonName() {
    std::string name { };
    do {
        std::cout << "Please insert person name: ";
        std::getline(std::cin, name);
    } while (validation_->validationIsAlpabet(name) == false || validation_->validationStringSize(name, validation_->getNameSize()) == false);
    return name;
}

std::string AddPerson::insertPersonSurname() {
    std::string surname { };
    do {
        std::cout << "Please insert person surname: ";
        std::getline(std::cin, surname);
    } while (validation_->validationIsAlpabet(surname) == false || validation_->validationStringSize(surname, validation_->getSurnameSize()) == false);
    return surname;
}

std::string AddPerson::insertPersonAddress() {
    std::string address { };
    do {
        std::cout << "Please insert person address: ";
        std::getline(std::cin, address);
    } while (validation_->validationStringSize(address, validation_->getAddressSize()) == false);
    return address;
}

std::string AddPerson::insertPersonPesel() {
    std::string pesel { };
    do {
        std::cout << "Please insert person PESEL number: ";
        std::getline(std::cin, pesel);
    } while (validation_->validatingPeselNumber(pesel) == false || validation_->validationStringSize(pesel, validation_->getPeselNumberSize(), true) == false);
    return pesel;
}

std::string AddPerson::insertPersonGender() {
    char gender;
    do {
        std::cout << "Please choose gender: m = Male , f = Female: ";
        std::cin >> gender;
    } while (validation_->validatingGender(gender) == false);
    if (gender == 'f') {
        return "Female";
    }
    if (gender == 'm') {
        return "Male";
    }
    return "ERROR";
}

std::string AddPerson::insertStudentIndexNumber() {
    std::string indexNumber;
    do {
        std::cout << "Please insert student index number: ";
        std::cin >> indexNumber;
    } while (validation_->validationIsDigit(indexNumber) == false || validation_->validationStringSize(indexNumber, validation_->getIndexNumberSize(), true) == false);
    return indexNumber;
}

std::string AddPerson::insertProfessorSalary() {
    std::string salary;
    do {
        std::cout << "Please insert professor salary: ";
        std::cin >> salary;
    } while (validation_->validationIsDigit(salary) == false || validation_->validationStringSize(salary, validation_->getSalarySize() == false));
    return salary;
}

void AddPerson::addingPerson(std::vector<std::shared_ptr<Person>>& person)  {
    if (whichPerson_ == WhichPerson::Student) {
        addStudentToDatabase(person);
    } else if (whichPerson_ == WhichPerson::Professor) {
        addProfessorToDatabase(person);
    } else {
        std::cout << "Back to main menu ...\n";
        return;
    }
}

void AddPerson::generateData() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    name_ = insertPersonName();
    surname_ = insertPersonSurname();
    address_ = insertPersonAddress();
    peselNumber_ = insertPersonPesel();
    gender_ = insertPersonGender();
    if (whichPerson_ == WhichPerson::Student) {
        indexNumber_ = insertStudentIndexNumber();
    } else if (whichPerson_ == WhichPerson::Professor) {
        salary_ = insertProfessorSalary();
    }
}

void AddPerson::addStudentToDatabase(std::vector<std::shared_ptr<Person>>& person)  {
    person.push_back(std::make_shared<Student>(Student(name_, surname_, address_, peselNumber_, gender_, indexNumber_)));
}

void AddPerson::addProfessorToDatabase(std::vector<std::shared_ptr<Person>>& person)  {
    person.push_back(std::make_shared<Professor>(Professor(name_, surname_, address_, peselNumber_, gender_, salary_)));
}

void AddPerson::confirmAddRecord(std::vector<std::shared_ptr<Person>>& person) {
    printAddingPerson();
    yesNoAnsver_ = validation_->confirmDataYesNo("Are you sure,do you wanna add this record to database?\n");
    if (yesNoAnsver_ == ansvers::Yes) {
        existingPerson(person);
    }
}

std::vector<std::shared_ptr<Person>>::iterator AddPerson::isPersonExist(std::vector<std::shared_ptr<Person>>& person) {
    return std::find_if(begin(person), 
                        end(person), 
                        [&](auto finding){ return (finding->getPeselNumber() == peselNumber_ ||
                                                  (finding->getIndexNumber() == indexNumber_ && indexNumber_ != "NO_INDEX") ||
                                                  (finding->getName() == name_ && finding->getSurname() == surname_)); });
}

void AddPerson::printAddingPerson() {
    std::cout << "--------------  ADDING PERSON  -------------\n";
    std::cout << "| NAME: " << name_ << " | ";
    std::cout << "SURNAME: " << surname_ << " | ";
    std::cout << "ADDRESS: " << address_ << " | ";
    std::cout << "PESEL NUMBER: " << peselNumber_ << " | ";
    std::cout << "GENDER: " << name_ << " | ";
    std::cout << "INDEX NUMBER: " << indexNumber_ << " | ";
    std::cout << "SALARY: " << salary_ << " | \n";
}

void AddPerson::printExistingPerson(std::shared_ptr<Person>& person) {
    std::cout << "--------------  EXISTING PERSON  -------------\n";
    std::cout << "| NAME: " << person->getName() << " | ";
    std::cout << "SURNAME: " << person->getSurname() << " | ";
    std::cout << "ADDRESS: " << person->getAddress() << " | ";
    std::cout << "PESEL NUMBER: " << person->getPeselNumber() << " | ";
    std::cout << "GENDER: " << person->getGender() << " | ";
    std::cout << "INDEX NUMBER: " << person->getIndexNumber() << " | ";
    std::cout << "SALARY: " << person->getSalary() << " | \n";
}

void AddPerson::existingPerson(std::vector<std::shared_ptr<Person>>& person) {
    existPerson_ = isPersonExist(person);
    while (true) {
        if (end(person) == existPerson_) {
            addingPerson(person);
            break;
        } else {
            printMenuIfPersonExist(person);
        }
    }
}

void AddPerson::printMenuIfPersonExist(std::vector<std::shared_ptr<Person>>& person) {
    int menuOptionNumber { };
    AddPerson::ExistingPersonMenu userAnswer { };
    do {
        std::cout << ++menuOptionNumber << "Person exist. What you wanna do?\n";
        std::cout << ++menuOptionNumber << "Save new\n";
        std::cout << ++menuOptionNumber << "Leave existing person\n";
        std::cout << ++menuOptionNumber << "Edit record\n";
        std::cout << ++menuOptionNumber << "Cancel\n\n";
        userAnswer = isPersonExistMenuUserChoice(menuOptionNumber);
        isPersonExistMenu(userAnswer, person);
    } while (userAnswer == AddPerson::ExistingPersonMenu::Back || userAnswer == AddPerson::ExistingPersonMenu::Cancel);

}

AddPerson::ExistingPersonMenu AddPerson::isPersonExistMenu(AddPerson::ExistingPersonMenu userChoice, std::vector<std::shared_ptr<Person>>& person) {
    switch (userChoice) {
        case ExistingPersonMenu::SaveNew : {
            return saveNewIsPersonExist(person);
        }
        case ExistingPersonMenu::LeaveExist : {
            return leaveExistIsPersonExist();
        }
        case ExistingPersonMenu::Edit : {
            return editIsPersonExist();
        }
        case ExistingPersonMenu::Cancel : {
            return cancelIsPersonExist();
        }       
        default : {
            throw std::range_error { "Wrong answer in PersonExistMenu()" };
        } break;
    }
}

AddPerson::ExistingPersonMenu AddPerson::isPersonExistMenuUserChoice(int optionNumber) {
    std::cout << "What is your choice? ";
    size_t userChoice { };
    std::cin >> userChoice;
    while (validation_->isCorrectMenuChoice(userChoice, optionNumber) == false) {
    }
    return static_cast<ExistingPersonMenu>(userChoice);
}

AddPerson::ExistingPersonMenu AddPerson::saveNewIsPersonExist(std::vector<std::shared_ptr<Person>>& person) {
    while (true) {
        printAddingPerson();
        yesNoAnsver_ = validation_->confirmDataYesNo("Are you sure,do you wanna add this record to database?\n");
        if (yesNoAnsver_ == ansvers::Yes) {
            addingPerson(person);
            std::cout << "Save new person complete\n";
            return AddPerson::ExistingPersonMenu::Back;
        }
        if (yesNoAnsver_ == ansvers::No) {
            std::cout << "Back to menu\n";
            return AddPerson::ExistingPersonMenu::NoChoice;
        }
        if (yesNoAnsver_ == ansvers::Back) {
            std::cout << "Cancel process\n";
            return AddPerson::ExistingPersonMenu::Back;
        }
    }
}

AddPerson::ExistingPersonMenu AddPerson::leaveExistIsPersonExist() {
    while (true) {
        printExistingPerson(*existPerson_);
        yesNoAnsver_ = validation_->confirmDataYesNo("Are you sure,do you wanna leave old record?\n");
        if (yesNoAnsver_ == ansvers::Yes) {
            std::cout << "Old record saved\n";
            return AddPerson::ExistingPersonMenu::Back;
        }
        if (yesNoAnsver_ == ansvers::No) {
            std::cout << "Back to menu\n";
            return AddPerson::ExistingPersonMenu::NoChoice;
        }
        if (yesNoAnsver_ == ansvers::Back) {
            std::cout << "Cancel process\n";
            return AddPerson::ExistingPersonMenu::Back;
        }
    }
}

AddPerson::ExistingPersonMenu AddPerson::editIsPersonExist() {
    editName();
    editSurname();
    editAddress();
    editPeselNumber();
    editGender();
    if (whichPerson_ == WhichPerson::Student) {
        editIndexNumber();
    } else if (whichPerson_ == WhichPerson::Professor) {
        editSalary();
    } else {
        throw std::range_error { "Wrong person in editIsPersonExist" };
    }
    return AddPerson::ExistingPersonMenu::Back;
}

void AddPerson::editName() {
    printMenuConfirmEditPerson();
    auto userAnswer = userChoiceConfirmEditPerson();
    if (userAnswer == AddPerson::EditPerson::Edit) {
        confirmEditPerson(existPerson_->get()->getName() , name_, userAnswer, insertPersonName());
    }
    confirmEditPerson(existPerson_->get()->getName() , name_, userAnswer);
}

void AddPerson::editSurname() {
    printMenuConfirmEditPerson();
    auto userAnswer = userChoiceConfirmEditPerson();
    if (userAnswer == AddPerson::EditPerson::Edit) {
        confirmEditPerson(existPerson_->get()->getName() , surname_, userAnswer, insertPersonSurname());
    }
    confirmEditPerson(existPerson_->get()->getSurname() , surname_, userAnswer);
}

void AddPerson::editAddress() {
    printMenuConfirmEditPerson();
    auto userAnswer = userChoiceConfirmEditPerson();
    if (userAnswer == AddPerson::EditPerson::Edit) {
        confirmEditPerson(existPerson_->get()->getAddress() , address_, userAnswer, insertPersonAddress());
    }
    confirmEditPerson(existPerson_->get()->getAddress() , address_ , userAnswer);
}

void AddPerson::editPeselNumber() {
    printMenuConfirmEditPerson();
    auto userAnswer = userChoiceConfirmEditPerson();
    if (userAnswer == AddPerson::EditPerson::Edit) {
        confirmEditPerson(existPerson_->get()->getPeselNumber() , peselNumber_, userAnswer, insertPersonPesel());
    }
    confirmEditPerson(existPerson_->get()->getPeselNumber() , peselNumber_ , userAnswer);
}

void AddPerson::editGender() {
    printMenuConfirmEditPerson();
    auto userAnswer = userChoiceConfirmEditPerson();
    if (userAnswer == AddPerson::EditPerson::Edit) {
        confirmEditPerson(existPerson_->get()->getGender() , gender_, userAnswer, insertPersonGender());
    }
    confirmEditPerson(existPerson_->get()->getGender() , gender_ , userAnswer);
}

void AddPerson::editIndexNumber() {
    printMenuConfirmEditPerson();
    auto userAnswer = userChoiceConfirmEditPerson();
    if (userAnswer == AddPerson::EditPerson::Edit) {
        confirmEditPerson(existPerson_->get()->getIndexNumber() , indexNumber_, userAnswer, insertStudentIndexNumber());
    }
    confirmEditPerson(existPerson_->get()->getIndexNumber(), indexNumber_ , userAnswer);
}

void AddPerson::editSalary() {
    printMenuConfirmEditPerson();
    auto userAnswer = userChoiceConfirmEditPerson();
    if (userAnswer == AddPerson::EditPerson::Edit) {
        confirmEditPerson(existPerson_->get()->getSalary() , salary_, userAnswer, insertProfessorSalary());
    }
    confirmEditPerson(existPerson_->get()->getSalary(), salary_ , userAnswer);
}


AddPerson::ExistingPersonMenu AddPerson::cancelIsPersonExist() {
    std::cout << "All records is cleaned\n";
    clearTemporaryData();
    return AddPerson::ExistingPersonMenu::Cancel;
}

void AddPerson::clearTemporaryData() {
    name_ = "";
    surname_ = "";
    address_ = "";
    peselNumber_ = "";
    gender_ = ' ';
    indexNumber_ = "";
    salary_ = "";
}

std::string AddPerson::confirmEditPerson(std::string oldRecord, std::string newRecord, EditPerson userAnswer, std::string editAnswer) {
    std::cout << "OLD RECORD: " << oldRecord << " | NEW RECORD: " << newRecord << '\n';
    switch (userAnswer)
    {
        case AddPerson::EditPerson::LeaveOld : {
            return oldRecord;
        } break;
        case AddPerson::EditPerson::AddNew : {
            return newRecord;
        } break;
        case AddPerson::EditPerson::Edit : {
            return editAnswer;
        } break;
        case AddPerson::EditPerson::Cancel : {
            return "";
        } break;
        default : {
            throw std::range_error { "Wrong option menu in confirm Edit Person class" };
        } break;
    }
}

int AddPerson::printMenuConfirmEditPerson() {
    int menuOptionNumber { };
    std::cout << ++menuOptionNumber << ". You editing record, what you wanna do?\n";
    std::cout << ++menuOptionNumber << ". Leave old\n";
    std::cout << ++menuOptionNumber << ". Add new\n";
    std::cout << ++menuOptionNumber << ". Edit\n";
    std::cout << ++menuOptionNumber << ". Cancel\n\n";
    return menuOptionNumber;
}

AddPerson::EditPerson AddPerson::userChoiceConfirmEditPerson() {
    int userChoice { };
    do {
        std::cin >> userChoice;
    } while (validation_->isCorrectMenuChoice(userChoice, printMenuConfirmEditPerson()) == false);
    return static_cast<EditPerson>(userChoice);
}

