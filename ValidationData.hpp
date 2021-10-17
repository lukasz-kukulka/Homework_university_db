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
    bool validationStringSize(std::string userStringData, uint8_t maxSize, bool isEqual = false);

    bool peselValidDOBCheck(std::string dayOfBirth);
    bool peselValidGenderCheck(char charGender, std::string peselNumber);
    bool peselValidWithCurrentlyDate(std::string peselNumber);
    bool peselValidWithWeight(std::string peseNumber);
    bool validatingPeselNumber(std::string peselNumber);

    bool validatingGender(char userChoice);

    YesNoConfirm confirmDataYesNo(std::string question);

    uint8_t getNameSize() const { return nameSize_; }
private:
    uint8_t nameSize_ { };
    uint8_t surnameSize_ { };
    uint8_t addressSize_ { };
    uint8_t peselNumberSize_ { };
    uint8_t genderSize_ { };
    uint8_t indexNumberSize_ { };
    uint8_t salarySize_ { };
};