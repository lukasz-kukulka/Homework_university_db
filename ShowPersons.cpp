#include "ShowPersons.hpp"

#include <iostream>

ShowPersons::ShowPersons(std::shared_ptr<ValidationData> validation) 
    : validation_(validation)
{
}

void ShowPersons::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SHOW PERSON HERE\n";
    if (person.size() > 0) {
        generateAllRecord(person);
    } else {
        std::cout << "DATABASE IS EMPTY\n\n";
    }
    
}

std::string ShowPersons::generateSingleRecord(const std::string& singleRecord) {
    std::string output { };
    output.insert(singleRecord.size() / 2, " ");
    output += singleRecord;
    output.insert((singleRecord.size() / 2) + (singleRecord.size() % 2), " ");
    return output;
}

std::string ShowPersons::generateSingleRecordLine(Person* singlePerson) {
    std::string output { };
    output = "| " + generateSingleRecord(singlePerson->getName()) + " | ";
    output += generateSingleRecord(singlePerson->getSurname()) + " | ";
    output += generateSingleRecord(singlePerson->getAddress()) + " | ";
    output += generateSingleRecord(singlePerson->getPeselNumber()) + " | ";
    output += generateSingleRecord(singlePerson->getGender()) + " | ";
    output += generateSingleRecord(singlePerson->getGender()) + " | ";
    output += generateSingleRecord(singlePerson->getIndexNumber()) + " | ";
    output += generateSingleRecord(singlePerson->getSalary()) + " |\n";
    //std::cout << "----------------------\n";
    return output;
}

void ShowPersons::printSeparateLine() {
    int lineSize = validation_->getNameSize() + validation_->getSurnameSize() +
                       validation_->getAddressSize() + validation_->getPeselNumberSize() + 
                       validation_->getGenderSize() + validation_->getIndexNumberSize() + validation_->getSalarySize() + 10;
    std::string line { };
    line.insert(lineSize, "-");
}

void ShowPersons::generateAllRecord(std::vector<std::shared_ptr<Person>>& person) {
    printSeparateLine();
    for (const auto & ele : person) {
        generateSingleRecordLine(ele.get());
        printSeparateLine();
    }
    std::cout << '\n';
}