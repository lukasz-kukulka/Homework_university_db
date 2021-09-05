#include "GenerateData.hpp"

#include <iostream>

void GenerateData::operator()(std::vector<std::shared_ptr<Person>> person) const {
    person.size();
    std::cout << "GENERATE DATA HERE\n";
}