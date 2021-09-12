#include "ValidationData.hpp"

#include <limits> //for numeric_limits
#include <ios> // for std::streamsize
#include <iostream>

bool ValidationData::isCorrectMenuChoice(const size_t choosenValueToValid, const size_t sizeMenu) {
    if (std::cin.fail() || choosenValueToValid < 1 || choosenValueToValid > sizeMenu) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect value, please put number betwen 1 and " << sizeMenu << '\n';
        return false;
    }
    return true;
}

