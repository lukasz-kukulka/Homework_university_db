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
    std::string generateSingleRecordLine(Person* singlePerson);
    void printSeparateLine();
    void generateAllRecord(std::vector<std::shared_ptr<Person>>& person);

    std::shared_ptr<ValidationData>validation_;
};