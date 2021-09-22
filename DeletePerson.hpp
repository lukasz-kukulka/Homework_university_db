#pragma once
#include "Command.hpp"
#include <memory>

class DeletePerson : public Command {
public:
    ~DeletePerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person)  override;

private:
};