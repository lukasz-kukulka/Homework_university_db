#include "ExitApp.hpp"

#include <iostream>

void ExitApp::operator()(std::vector<std::shared_ptr<Person>> person) const {
    person.size();
    std::cout << "EXIT APPLICATION HERE\n";
}