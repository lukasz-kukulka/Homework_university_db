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

bool ValidationData::validationIsAlpabet(std::string stringToCheck) {
    auto result = std::all_of(stringToCheck.begin(), stringToCheck.end(), [](auto character) {
        return std::isalpha(character);
    });
    if (result) {
        return true;
    }
    std::cout << "Insert data can be only alphabet\n";
    return false;
}

bool ValidationData::validationIsDigit(std::string stringToCheck) {
    auto result = std::all_of(stringToCheck.begin(), stringToCheck.end(), [](auto character) {
        return std::isdigit(character);
    });
    if (result) {
        return true;
    }
    std::cout << "Insert data can be only digit\n"; 
    return false;
}

bool ValidationData::validationStringSize(std::string userStringData, size_t maxSize, bool isEqual) {
    if (isEqual == false && userStringData.size() <= maxSize) {
        return true;
    }
    if (isEqual == true && userStringData.size() == maxSize) {
        return true;
    }
    if (isEqual == true) {
        std::cout << "Wrong length, value must have " << maxSize << " characters\n";
    }
    std::cout << "Length is to long, maximum length is " << maxSize << '\n';
    return false;
}