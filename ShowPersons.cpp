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

std::string ShowPersons::generateSingleRecordLine(const std::vector<std::unique_ptr<Person>>::iterator& singlePerson) {
    std::string output { };
    output = "| " + generateSingleRecord(singlePerson->get()->getName()) + " | ";
    output = generateSingleRecord(singlePerson->get()->getSurname()) + " | ";
    output = generateSingleRecord(singlePerson->get()->getAddress()) + " | ";
    output = generateSingleRecord(singlePerson->get()->getPeselNumber()) + " | ";
    output = generateSingleRecord(singlePerson->get()->getGender()) + " | ";
    output = generateSingleRecord(singlePerson->get()->getIndexNumber()) + " | ";
    output = generateSingleRecord(singlePerson->get()->getSalary()) + " |\n";
    return output;
}

void ShowPersons::printSeparateLine() {
    int lineSize = validation_->getNameSize() + validation_->getSurnameSize() +
                       validation_->getAddressSize() + validation_->getPeselNumberSize() + 
                       validation_->getIndexNumberSize() + validation_->getSalarySize() + 10;
    std::string line { };
    line.insert(lineSize, "-");
}