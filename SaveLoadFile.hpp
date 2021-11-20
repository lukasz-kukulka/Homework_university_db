#pragma once

#include "Command.hpp"
#include "ValidationData.hpp"

#include <memory>

class SaveLoadFile : public Command {
public:
    SaveLoadFile(std::shared_ptr<ValidationData> validation);
    ~SaveLoadFile() = default;
    enum class SaveLoadOptions {
        NoChoice,
        SaveToExist,
        SaveNew,
        LoadNew,
        LoadToExist,
        Back
    };

    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    int printSaveLoadMenu();

    std::shared_ptr<ValidationData>validation_;
};