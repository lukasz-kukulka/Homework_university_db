#pragma once
#include "Command.hpp"
#include <memory>

class SortPerson : public Command {
public:
    ~SortPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    
};