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

    SearchMenu currentlyChoice_ { SearchMenu::NoChoice };
};