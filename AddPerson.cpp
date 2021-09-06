#include "AddPerson.hpp"

#include <iostream>

AddPerson::AddPerson(std::shared_ptr<ValidationData> validation) {
    validation.get();
}

void AddPerson::operator()(std::vector<std::shared_ptr<Person>> person) const {
    person.size();
    std::cout << "ADD PERSON HERE\n";
    selectPerson();
}

void AddPerson::selectPerson() const {
    size_t userChoicePerson{};
    do {
        std::cout << "Which person you wanna add to database?\n";
        std::cout << "1.STUDENT | 2.PROFESSOR :";
        std::cin >> userChoicePerson;
    } while (true);
}
