#pragma once

#include "Command.hpp"

#include <memory>

class SearchPerson : public Command {
public:
    enum class SearchMenu{
        NoChoice,
        SearchByName,
        SearchBySurname,
        SearchByAddress,
        SearchByPeselNumber,
        SearchByGender,
        SearchByIndex,
        SearchBySalary
    };
    ~SearchPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    int printSearchMenu();
    int validationUserInsertDataMenu(int userAnswer);
    SearchMenu searchMenu(int userChoice);

    void searchByName(std::string nameToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchBySurname(std::string surnameToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchByAddress();
    void searchByPeselNumber();
    void searchByGender();
    void searchByIndexNumber();
    void searchBySalary();

    std::vector<std::shared_ptr<Person>> foundPersons_;
    SearchMenu currentlyChoice_ { SearchMenu::NoChoice };
};