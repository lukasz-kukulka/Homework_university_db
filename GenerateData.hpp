#pragma once
#include "Command.hpp"
#include <memory>

class GenerateData : public Command {
public:
    ~GenerateData() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) const override;

private:
};