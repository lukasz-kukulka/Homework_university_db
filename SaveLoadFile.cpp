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
            // TO DO
        } break;       
        case SaveLoadOptions::LoadNew : {
            // TO DO
        } break; 
        case SaveLoadOptions::LoadToExist : {
            // TO DO
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
    person.size(); // delete
}

void SaveLoadFile::saveToNewFile(std::vector<std::shared_ptr<Person>>& person) {
    person.size(); // delete
}