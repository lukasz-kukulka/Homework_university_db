#include "AddPerson.hpp"
#include "Student.hpp"

#include <iostream>

AddPerson::AddPerson(std::shared_ptr<ValidationData> validation) 
    : validation_(validation)
{
}

void AddPerson::operator()(std::vector<std::shared_ptr<Person>> person) const {
    person.size();
    std::cout << "ADD PERSON HERE\n";
    selectPerson();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void AddPerson::selectPerson() const {
    size_t userChoicePerson{};
    do {
        std::cout << "Which person you wanna add to database?\n";
        std::cout << "1.STUDENT | 2.PROFESSOR :";
        std::cin >> userChoicePerson;
    } while (validation_->isCorrectMenuChoice(userChoicePerson, 2));
}

std::string AddPerson::insertStudentName() {
    std::string name { };
    do {
        std::cout << "Please insert person name: ";
        std::getline(std::cin, name);
    } while (true);
    return name;
}
