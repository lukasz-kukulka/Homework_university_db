#pragma once
#include "Command.hpp"
#include <memory>

class SortPerson : public Command {
public:
    enum class SortMenu{
        NoChoice,
        SearchByName,
        SearchBySurname,
        SearchByAddress,
        SearchByPeselNumber,
        SearchByGender,
        SearchByIndex,
        SearchBySalary,
        Back
    };
    ~SortPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    int printSortMenu();

};