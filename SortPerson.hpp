#pragma once
#include "Command.hpp"
#include "ValidationData.hpp"

#include <memory>

class SortPerson : public Command {
public:
    SortPerson(std::shared_ptr<ValidationData> validation);
    ~SortPerson() = default;
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
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    int printSortMenu();
    SortMenu userChoice();
    SortMenu sortMenu(SortMenu userChoice, std::vector<std::shared_ptr<Person>>& person);

    void sortByName(std::vector<std::shared_ptr<Person>>& person);
    void sortBySurname(std::vector<std::shared_ptr<Person>>& person);
    void sortByAddress(std::vector<std::shared_ptr<Person>>& person);

    std::shared_ptr<ValidationData> validation_;
    SortMenu userChoiceMenuOption_ { SortMenu::NoChoice };
};