#include "ShowPersons.hpp"

#include <iostream>

ShowPersons::ShowPersons(std::shared_ptr<ValidationData> validation) 
    : validation_(validation)
{
}

ShowPersons::ShowPersons(std::vector<std::shared_ptr<Person>>& person)
    : persons_(person)
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

std::string ShowPersons::generateSingleRecord(const std::string& singleRecord, int cellSize) {
    std::string output { };
    output.append(cellSize / 2 - singleRecord.size() / 2, ' ');
    output += singleRecord;
    output.append(cellSize / 2 - (singleRecord.size() / 2) + (cellSize % 2) - (singleRecord.size() % 2), ' ');
    return output;
}

std::string ShowPersons::generateSingleRecordLine(Person* singlePerson) {
    std::string output { };
    output = "| " + generateSingleRecord(singlePerson->getName(), validation_->getNameSize()) + " | ";
    output += generateSingleRecord(singlePerson->getSurname(), validation_->getSurnameSize()) + " | ";
    output += generateSingleRecord(singlePerson->getAddress(), validation_->getAddressSize()) + " | ";
    output += generateSingleRecord(singlePerson->getPeselNumber(), validation_->getPeselNumberSize()) + " | ";
    output += generateSingleRecord(singlePerson->getGender(), validation_->getGenderSize()) + " | ";
    output += generateSingleRecord(singlePerson->getIndexNumber(), validation_->getIndexNumberSize()) + " | ";
    output += generateSingleRecord(singlePerson->getSalary(), validation_->getSalarySize()) + " |\n";
    return output;
}

void ShowPersons::printSeparateLine() {
    int borderAndSeparatorSize { 22 };
    int lineSize = validation_->getNameSize() + validation_->getSurnameSize() +
                       validation_->getAddressSize() + validation_->getPeselNumberSize() + 
                       validation_->getGenderSize() + validation_->getIndexNumberSize() + validation_->getSalarySize() + borderAndSeparatorSize;
    std::string line { };
    line.append(lineSize, '-');
    std::cout << line << '\n';
}

void ShowPersons::generateAllRecord(std::vector<std::shared_ptr<Person>>& person) {
    printSeparateLine();
    std::string singleStringLine { };
    for (const auto & ele : person) {
        singleStringLine = generateSingleRecordLine(ele.get());
        std::cout << singleStringLine;
        printSeparateLine();
    }
    std::cout << '\n';
}