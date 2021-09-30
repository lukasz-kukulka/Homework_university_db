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
    std::cout << "| NAME: " << name_ << " | ";
    std::cout << "SURNAME: " << surname_ << " | ";
    std::cout << "ADDRESS: " << address_ << " | ";
    std::cout << "PESEL NUMBER: " << peselNumber_ << " | ";
    std::cout << "GENDER: " << name_ << " | ";
    std::cout << "INDEX NUMBER: " << indexNumber_ << " | ";
    std::cout << "SALARY: " << salary_ << " | \n";
}

void AddPerson::printExistingPerson(std::shared_ptr<Person>& person) {
    
}

void AddPerson::existingPerson(std::vector<std::shared_ptr<Person>>& person) {
    if (end(person) != isPersonExist(person)) {
        
    }
}

