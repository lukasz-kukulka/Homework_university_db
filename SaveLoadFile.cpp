#include "SaveLoadFile.hpp"

#include <iostream>

SaveLoadFile::SaveLoadFile(std::shared_ptr<ValidationData> validation)
    : validation_(validation) 
{
    
}

void SaveLoadFile::operator()(std::vector<std::shared_ptr<Person>>& person) {
    person.size();
    std::cout << "SAVE LOAD HERE\n";
}

int SaveLoadFile::printSaveLoadMenu() {
    int optionNumber = 0;
    std::cout << ++optionNumber << ". Save(add to currently file new records (delete duplicate)\n";
    std::cout << ++optionNumber << ". Save to new file \n";
    std::cout << ++optionNumber << ". Clear existing data and load new data from file \n";
    std::cout << ++optionNumber << ". Load from file and add records to existing file (delete duplicate)\n";
    std::cout << ++optionNumber << ". Back\n";
    return optionNumber;
}

SaveLoadFile::SaveLoadOptions SaveLoadFile::userChoice() {
    auto menuSize = printSaveLoadMenu();
    int userAnswer { };
    std::cout << "Please insert your how you wanna do\n";
    do {
        std::cin >> userAnswer;
    } while (validation_->isCorrectMenuChoice(userAnswer, menuSize) == false);
    return static_cast<SaveLoadOptions>(userAnswer);
}

SaveLoadFile::SaveLoadOptions SaveLoadFile::saveLoadMenu(SaveLoadOptions userChoice, std::vector<std::shared_ptr<Person>>& person) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (userChoice) {
        case SaveLoadOptions::SaveToExist : {
            saveToCurrentlyFile(person);
        } break;
        case SaveLoadOptions::SaveNew : {
            saveToNewFile(person);
        } break;
        case SaveLoadOptions::LoadNew : {
            loadToNewVector(person);
        } break; 
        case SaveLoadOptions::LoadToExist : {
            loadToExistVector(person);
        } break; 
        case SaveLoadOptions::Back : {
            std::cout << "BACK TO MAIN MENU\n";
        } break; 
        default : {
            std::cout << "ERROR ... WRONG ANSWER(SWITCH)\n";
        } break;
    }
    return static_cast<SaveLoadOptions>(userChoice);
}

void SaveLoadFile::saveToCurrentlyFile(std::vector<std::shared_ptr<Person>>& person) {
    saveMultiRecordsToFile(person);
}

void SaveLoadFile::saveToNewFile(std::vector<std::shared_ptr<Person>>& person) {
    person.size(); // delete
}

void SaveLoadFile::loadToNewVector(std::vector<std::shared_ptr<Person>>& person) {
    person.size(); // delete
}

void SaveLoadFile::loadToExistVector(std::vector<std::shared_ptr<Person>>& person) {
    person.size(); // delete
}

void SaveLoadFile::saveSingleRecordToFile(std::vector<std::shared_ptr<Person>>& person, int indexNumber, std::fstream& file) {
    file << "[Person nr. : " << indexNumber + 1 << "]\n";
    file << person[indexNumber]->getName() << "\n";
    file << person[indexNumber]->getSurname() << "\n";
    file << person[indexNumber]->getAddress() << "\n";
    file << person[indexNumber]->getPeselNumber() << "\n";
    file << person[indexNumber]->getIndexNumber() << "\n";
    file << person[indexNumber]->getSalary() << "\n\n";
}

void SaveLoadFile::saveMultiRecordsToFile(std::vector<std::shared_ptr<Person>>& person, std::string fileName) {
    std::fstream file;
    if (fileName == DEFAULT_FILE_NAME) {
        file.open(fileName + ".txt", file.in | file.app);
    } else {
        file.open(fileName, file.in | file.trunc);
    }
    if (!file.is_open()) {
        std::cout << "ERROR IN saveSingleRecordToFile() function\n";
    }
    for (int i = 0; i < static_cast<int>(person.size()); i++) {
        saveSingleRecordToFile(person, i, file);
    }
    std::cout << "Data saved in " << fileName << '\n';
}

void SaveLoadFile::deleteDuplicate(std::vector<std::shared_ptr<Person>>& person) {
    std::vector<Person>tempPersons();
    person.size();
}
