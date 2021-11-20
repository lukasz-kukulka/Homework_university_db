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
    return 0;
}