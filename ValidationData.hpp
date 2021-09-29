#pragma once
#include <stdlib.h> // for size_t
#include <string>

namespace {
    constexpr char CURRENTLY_DATE[] = "13082021";  // FORMAT DATE DDMMYYYY
}

class ValidationData {
public:
    enum class YesNoConfirm{
        NoConfirm,
        Yes,
        No,
        Error,
        Back
    };

    bool isCorrectMenuChoice(const size_t choosenValueToValid, const size_t sizeMenu);

    bool validationIsAlpabet(std::string stringToCheck);
    bool validationIsDigit(std::string stringToCheck);
    bool validationStringSize(std::string userStringData, size_t maxSize, bool isEqual = false);

    bool peselValidDOBCheck(std::string dayOfBirth);
    bool peselValidGenderCheck(char charGender, std::string peselNumber);
    bool peselValidWithCurrentlyDate(std::string peselNumber);
    bool peselValidWithWeight(std::string peseNumber);
    bool validatingPeselNumber(std::string peselNumber);

    bool validatingGender(char userChoice);

    YesNoConfirm confirmDataYesNo(std::string question);
private:

};