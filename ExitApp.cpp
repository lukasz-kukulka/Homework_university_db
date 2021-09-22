#include "ExitApp.hpp"

#include <iostream>

void ExitApp::operator()(std::vector<std::shared_ptr<Person>>& person)  {
    person.size();
    std::cout << "EXIT APPLICATION HERE\n";
}