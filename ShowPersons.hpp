#pragma once
#include "Command.hpp"
#include "ValidationData.hpp"

#include <memory>

class ShowPersons : public Command {
public:
    ShowPersons(std::shared_ptr<ValidationData> validation);
    ~ShowPersons() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    void printSingleRecord(const std::shared_ptr<Person>& singlePerson);

    std::shared_ptr<ValidationData>validation_;
};