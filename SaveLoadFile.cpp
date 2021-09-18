#include "SaveLoadFile.hpp"

#include <iostream>

void SaveLoadFile::operator()(std::vector<std::shared_ptr<Person>>& person) const {
    person.size();
    std::cout << "SAVE LOAD HERE\n";
}