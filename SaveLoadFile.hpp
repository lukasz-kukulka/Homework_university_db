#pragma once

#include "Command.hpp"
#include "ValidationData.hpp"

#include <fstream> 
#include <memory>

namespace {
    constexpr char DEFAULT_FILE_NAME[] { "default.txt" };
}

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
    SaveLoadOptions userChoice();
    SaveLoadOptions saveLoadMenu(SaveLoadOptions userChoice, std::vector<std::shared_ptr<Person>>& person);

    void saveToCurrentlyFile(std::vector<std::shared_ptr<Person>>& person);

    void saveToNewFile(std::vector<std::shared_ptr<Person>>& person);

    void loadToNewVector(std::vector<std::shared_ptr<Person>>& person);

    void loadToExistVector(std::vector<std::shared_ptr<Person>>& person);

    std::shared_ptr<ValidationData>validation_;
    SaveLoadOptions SaveLoadOptions_ { SaveLoadOptions::NoChoice };
};