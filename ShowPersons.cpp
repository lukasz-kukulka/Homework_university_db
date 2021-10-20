#include "ShowPersons.hpp"

#include <iostream>

ShowPersons::ShowPersons(std::shared_ptr<ValidationData> validation) 
    : validation_(validation)
{
}

void ShowPersons::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SHOW PERSON HERE\n";
}

std::string ShowPersons::generateSingleRecord(const std::string& singleRecord) {
    std::string output { };
    output.insert(singleRecord.size() / 2, " ");
    output += singleRecord;
    output.insert((singleRecord.size() / 2) + (singleRecord.size() % 2), " ");
    return output;
}

void ShowPersons::printSeparateLine(uint8_t size) {
    size += 1;  // only for compilation
}