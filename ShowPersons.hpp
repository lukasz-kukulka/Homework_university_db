#pragma once
#include "Command.hpp"
#include <memory>

class ShowPersons : public Command {
public:
    ~ShowPersons() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    void printSingleRecord();
};