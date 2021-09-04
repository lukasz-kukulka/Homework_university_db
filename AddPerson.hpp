#pragma once
#include "Command.hpp"

class AddPerson : public Command {
public:
    ~AddPerson() = default;
    void operator()(std::vector<Person>& person) const override;

private:
};