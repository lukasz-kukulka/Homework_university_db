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

bool ValidationData::peselValidDOBCheck(std::string dayOfBirth) {
    if ((dayOfBirth[2] == '1' || dayOfBirth[2] == '3' || dayOfBirth[2] == '5' || dayOfBirth[2] == '7' || dayOfBirth[2] == '9') && dayOfBirth[2] != '0' && dayOfBirth[2] != '1' && dayOfBirth[2] != '2') {
        return false;
    }
    if (dayOfBirth[4] != '0' && dayOfBirth[4] != '1' && dayOfBirth[4] != '2' && dayOfBirth[4] != '3') {
        return false;
    }
    if (dayOfBirth[4] == '3' && dayOfBirth[5] != '0' && dayOfBirth[5] != '1' && dayOfBirth[5] != '2') {
        return false;
    }
    return true;
}

bool ValidationData::peselValidGenderCheck(char charGender, std::string gender) {
    if (static_cast<size_t>(gender[9]) % 2 != std::stol(gender)) {
        return false;
    }
    return true;
}

bool ValidationData::peselValidWithCurrentlyDate(std::string peselNumber) {
    if (CURRENTLY_DATE[5] == '0' && (peselNumber[2] == '4' || peselNumber[2] == '5' || peselNumber[2] == '6' || peselNumber[2] == '7')) {
        return false;
    }
    if (CURRENTLY_DATE[5] == '1' && (peselNumber[2] == '6' || peselNumber[2] == '7')) {
        return false;
    }
    return true;
}

bool ValidationData::peselValidWithWeight(std::string peselNumber) {
    std::string weightCheck = "13791379131";
    size_t weightResult = 0;
    for (int i = 0; i < 10; i++) {
        weightResult = weightResult + (static_cast<size_t>(peselNumber[i] - '0') * (static_cast<size_t>(weightCheck[i] - '0')));
    }
    weightResult = weightResult % 10;
    if (weightResult == 0) {
        weightResult = 0;
    } else {
        weightResult = 10 - weightResult;
    }
    if (static_cast<size_t>(peselNumber[10] - '0') != weightResult) {
        return false;
    }
    return true;
}