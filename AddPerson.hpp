#pragma once
#include "Command.hpp"
#include <memory>

class AddPerson : public Command {
public:
    ~AddPerson() = default;
    //void operator()(std::vector<Person>& person) const override;
    void operator()(std::vector<std::shared_ptr<Person>> person) const override;

private:
};