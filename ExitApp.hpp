#pragma once
#include "Command.hpp"
#include <memory>

class ExitApp : public Command {
public:
    ~ExitApp() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) const override;

private:
};