#pragma once
#include "Command.hpp"
#include <memory>

class SaveLoadFile : public Command {
public:
    ~SaveLoadFile() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
};