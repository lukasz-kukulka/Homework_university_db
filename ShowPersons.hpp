#pragma once
#include "Command.hpp"
#include "ValidationData.hpp"

#include <memory>
#include <string>

class ShowPersons : public Command {
public:
    ShowPersons();
    ShowPersons(std::shared_ptr<ValidationData> validation);
    ShowPersons(std::vector<std::shared_ptr<Person>>& person);
    ~ShowPersons() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    std::string generateSingleRecord(const std::string& singleRecord, int cellSize);
    std::string generateSingleRecordLine(Person* singlePerson, size_t personIndex);
    void printSeparateLine();
    void generateAllRecord(std::vector<std::shared_ptr<Person>>& person);

    std::shared_ptr<ValidationData>validation_;
    std::vector<std::shared_ptr<Person>> persons_;
};