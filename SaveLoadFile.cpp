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
    return SaveLoadOptions::NoChoice;
}
