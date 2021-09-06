#pragma once
#include "Command.hpp"
#include "ValidationData.hpp"
#include <memory>

class AddPerson : public Command {
public:
    AddPerson(std::shared_ptr<ValidationData> validation);
    ~AddPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>> person) const override;

private:
    void selectPerson() const ;
};