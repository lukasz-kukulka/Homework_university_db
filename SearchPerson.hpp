#pragma once
#include "Command.hpp"
#include <memory>

class SearchPerson : public Command {
public:
    ~SearchPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) const override;

private:
};