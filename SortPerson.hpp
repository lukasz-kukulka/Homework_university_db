#pragma once
#include "Command.hpp"
#include <memory>

class SortPerson : public Command {
public:
    enum class SortMenu{
        NoChoice,
        SortByName,
        SortBySurname,
        SortByAddress,
        SortByPeselNumber,
        SortByGender,
        SortByIndex,
        SortBySalary,
        Back
    };
    ~SortPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    int printSortMenu();
    SortMenu userChoice();
    SortMenu sortMenu(int userChoice, std::vector<std::shared_ptr<Person>>& person);

    SortMenu userChoiceMenuOption { SortMenu::NoChoice };
};