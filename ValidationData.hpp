#pragma once
#include <stdlib.h> // for size_t
#include <string>
class ValidationData {
public:
    bool isCorrectMenuChoice(const size_t choosenValueToValid, const size_t sizeMenu);
    bool validationIsAlpabet(std::string stringToCheck);
    bool validationIsDigit(std::string stringToCheck);
    bool validationStringSize(std::string userStringData, size_t maxSize, bool isEqual = false);
    bool peselValidDOBCheck(std::string dayOfBirth);
private:

};