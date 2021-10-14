#include "AddPerson.hpp"
#include "Student.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include <exception>

#include <iostream>

AddPerson::AddPerson(std::shared_ptr<ValidationData> validation) 
    : validation_(validation)
{
}

void AddPerson::operator()(std::vector<std::shared_ptr<Person>>& person)  {
    std::cout << "ADD PERSON HERE\n"; //TO DELETE 
    //zmienić share ptr na const
    while (yesNoAnsver_ != ansvers::Back) {
        confirmAddRecord(person);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // add condition if answer if yesNoAnsver_ == ansvers::No
        // add conditions in all insert data
    }
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
    } while (validation_->isCorrectMenuChoice(userChoicePerson, optionNumber));
    return static_cast<WhichPerson>(userChoicePerson);
}

std::string AddPerson::insertPersonName() {
    std::string name { };
    do {
        std::cout << "Please insert person name: ";
        std::getline(std::cin, name);
    } while (true);
    return name;
}

std::string AddPerson::insertPersonSurname() {
    std::string surname { };
    do {
        std::cout << "Please insert person surname: ";
        std::getline(std::cin, surname);
    } while (true);
    return surname;
}

std::string AddPerson::insertPersonAddress() {
    std::string address { };
    do {
        std::cout << "Please insert person address: ";
        std::getline(std::cin, address);
    } while (true);
    return address;
}

std::string AddPerson::insertPersonPesel() {
    std::string pesel { };
    do {
        std::cout << "Please insert person PESEL number: ";
        std::getline(std::cin, pesel);
    } while (true);
    return pesel;
}

char AddPerson::insertPersonGender() {
    char gender;
    do {
        std::cout << "Please choose gender: m = Male , f = Female: ";
        std::cin >> gender;
    } while (true);
}

std::string AddPerson::insertStudentIndexNumber() {
    char indexNumber;
    do {
        std::cout << "Please insert student index number: ";
        std::cin >> indexNumber;
    } while (true);
}

std::string AddPerson::insertProfessorSalary() {
    char salary;
    do {
        std::cout << "Please insert professor salary: ";
        std::cin >> salary;
    } while (true);
}

void AddPerson::addingPerson(std::vector<std::shared_ptr<Person>>& person)  {
    WhichPerson userChoice = selectPerson();
    if (userChoice == WhichPerson::Student) {
        addStudentToDatabase(person);
    } else if (userChoice == WhichPerson::Professor) {
        addProfessorToDatabase(person);
    } else {
        std::cout << "Back to main menu ...\n";
    }
}

void AddPerson::generateData(WhichPerson userChoice) {
    name_ = insertPersonName();
    surname_ = insertPersonSurname();
    address_ = insertPersonAddress();
    peselNumber_ = insertPersonPesel();
    gender_ = insertPersonGender();
    if (userChoice == WhichPerson::Student) {
        indexNumber_ = insertStudentIndexNumber();
    } else if (userChoice == WhichPerson::Professor) {
        salary_ = insertProfessorSalary();
    }
}

void AddPerson::addStudentToDatabase(std::vector<std::shared_ptr<Person>>& person)  {
    generateData(WhichPerson::Student);
    person.push_back(std::make_shared<Student>(Student(name_, surname_, address_, peselNumber_, gender_, indexNumber_)));
}

void AddPerson::addProfessorToDatabase(std::vector<std::shared_ptr<Person>>& person)  {
    generateData(WhichPerson::Professor);
    person.push_back(std::make_shared<Professor>(Professor(name_, surname_, address_, peselNumber_, gender_, salary_)));
}

void AddPerson::confirmAddRecord(std::vector<std::shared_ptr<Person>>& person) {
    while (true) {
        printAddingPerson();
        yesNoAnsver_ = validation_->confirmDataYesNo("Are you sure,do you wanna add this record to database?\n");
        if (yesNoAnsver_ == ansvers::Yes) {
            addingPerson(person);
            existingPerson(person);
        }
        break;
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
        if (end(person) != existPerson_) {
            confirmAddRecord(person);
            break;
        } else {
            printMenuIfPersonExist(person);
        }
    }
}

void AddPerson::printMenuIfPersonExist(std::vector<std::shared_ptr<Person>>& person) {
    int menuOptionNumber { };
    do {
        std::cout << ++menuOptionNumber << "Person exist. What you wanna do?\n";
        std::cout << ++menuOptionNumber << "Save new\n";
        std::cout << ++menuOptionNumber << "Leave existing person\n";
        std::cout << ++menuOptionNumber << "Edit record\n";
        std::cout << ++menuOptionNumber << "Cancel\n\n";
        isPersonExistMenu(isPersonExistMenuUserChoice(menuOptionNumber), person);
    } while (true); // to do

}

void AddPerson::isPersonExistMenu(size_t userChoice, std::vector<std::shared_ptr<Person>>& person) {
    existingPersonMenu_ = static_cast<ExistingPersonMenu>(userChoice);
    switch (existingPersonMenu_) {
        case ExistingPersonMenu::SaveNew : {
            saveNewIsPersonExist(person);
        } break;
        case ExistingPersonMenu::LeaveExist : {
            leaveExistIsPersonExist();
        } break;
        case ExistingPersonMenu::Edit : {
            editIsPersonExist();
        } break;
        case ExistingPersonMenu::Cancel : {
            cancelIsPersonExist();
        } break;        
        default : break;
    }

}

size_t AddPerson::isPersonExistMenuUserChoice(int optionNumber) {
    std::cout << "What is your choice? ";
    size_t userChoice { };
    std::cin >> userChoice;
    while (validation_->isCorrectMenuChoice(userChoice, optionNumber) == false) {
    }
    return userChoice;
}

bool AddPerson::saveNewIsPersonExist(std::vector<std::shared_ptr<Person>>& person) {
    while (true) {
        printAddingPerson();
        yesNoAnsver_ = validation_->confirmDataYesNo("Are you sure,do you wanna add this record to database?\n");
        if (yesNoAnsver_ == ansvers::Yes) {
            addingPerson(person);
            std::cout << "Save new person complete\n";
            return true;
        }
        if (yesNoAnsver_ == ansvers::Back) {
            std::cout << "Cancel process\n";
            return true;
        }
        return false;
    }
}

void AddPerson::leaveExistIsPersonExist() {
    while (true) {
        printExistingPerson(*existPerson_);
        yesNoAnsver_ = validation_->confirmDataYesNo("Are you sure,do you wanna leave old record?\n");
        if (yesNoAnsver_ == ansvers::Yes) {
            
        }
        // add another option answer
        break;
    }
}

void AddPerson::editIsPersonExist() {

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
        confirmEditPerson(existPerson_->get()->getGender() , std::to_string(gender_), userAnswer, std::to_string(insertPersonGender()));
    }
    confirmEditPerson(existPerson_->get()->getGender() , std::to_string(gender_) , userAnswer);
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
    //TO DO
}

void AddPerson::cancelIsPersonExist() {
    //TO DO
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

