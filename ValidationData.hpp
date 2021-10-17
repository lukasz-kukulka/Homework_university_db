#pragma once
#include <stdlib.h> // for size_t
#include <string>

namespace {
    constexpr char CURRENTLY_DATE[] = "13082021";  // FORMAT DATE DDMMYYYY
    constexpr uint8_t NAMESIZE { 20 };
    constexpr uint8_t SURNAMESIZE { 30 };
    constexpr uint8_t ADDRESSSIZE { 50 };
    constexpr uint8_t PESELNUMBERSIZE { 11 };
    constexpr uint8_t INDEXNUMBERSIZE { 10 };
    constexpr uint8_t SALARYSIZE { 5 };
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

    uint8_t getNameSize() const { return NAMESIZE; }
    uint8_t getSurnameSize() const { return SURNAMESIZE; }
    uint8_t getAddressSize() const { return ADDRESSSIZE; }
    uint8_t getPeselNumberSize() const { return PESELNUMBERSIZE; }
    uint8_t getIndexNumberSize() const { return INDEXNUMBERSIZE; }
    uint8_t getSalarySize() const { return SALARYSIZE; }
private:
};