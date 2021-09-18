#pragma once
#include <stdlib.h> // for size_t
#include <string>

namespace {
    constexpr char CURRENTLY_DATE[] = "13082021";  // FORMAT DATE DDMMYYYY
}

class ValidationData {
public:
    bool isCorrectMenuChoice(const size_t choosenValueToValid, const size_t sizeMenu);

    bool validationIsAlpabet(std::string stringToCheck);
    bool validationIsDigit(std::string stringToCheck);
    bool validationStringSize(std::string userStringData, size_t maxSize, bool isEqual = false);

    bool peselValidDOBCheck(std::string dayOfBirth);
    bool peselValidGenderCheck(char charGender, std::string gender);
    bool peselValidWithCurrentlyDate(std::string peselNumber);
private:

};