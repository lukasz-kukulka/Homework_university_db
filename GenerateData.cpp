#include "GenerateData.hpp"

#include <iostream>

void GenerateData::operator()(std::vector<std::shared_ptr<Person>>& person)  {
    person.size();
    std::cout << "GENERATE DATA HERE\n";
}