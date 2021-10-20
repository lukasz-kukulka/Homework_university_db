#pragma once
#include "Command.hpp"
#include "ValidationData.hpp"

#include <memory>
#include <string>

class ShowPersons : public Command {
public:
    ShowPersons(std::shared_ptr<ValidationData> validation);
    ~ShowPersons() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    std::string generateSingleRecord(const std::string& singleRecord);
    void printSeparateLine(uint8_t size);

    std::shared_ptr<ValidationData>validation_;
};