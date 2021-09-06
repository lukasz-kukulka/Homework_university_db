#pragma once
#include "Command.hpp"
#include "ValidationData.hpp"
#include <memory>
#include <limits> //for numeric_limits
#include <ios> // for std::streamsize

class AddPerson : public Command {
public:
    AddPerson(std::shared_ptr<ValidationData> validation);
    ~AddPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>> person) const override;

private:
    void selectPerson() const ;
    std::shared_ptr<ValidationData>validation_;
};