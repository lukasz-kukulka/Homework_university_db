#include "ValidationData.hpp"

#include <limits> //for numeric_limits
#include <ios> // for std::streamsize
#include <cctype> // tolover
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

bool ValidationData::peselValidGenderCheck(char charGender, std::string peselNumber) {
    int genderNumber = (peselNumber[9] - '0') % 2;
    if (std::tolower(charGender) == 'f' && genderNumber == 0) {
        return true;
    }
    if (std::tolower(charGender) == 'm' && genderNumber == 1) {
        return true;
    }
    return false;
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

bool ValidationData::validatingPeselNumber(std::string peselNumber) {
    bool corectPeselNumber = true;
    corectPeselNumber = peselValidDOBCheck(peselNumber);
    corectPeselNumber = peselValidWithCurrentlyDate(peselNumber);
    corectPeselNumber = peselValidWithWeight(peselNumber);
    if (!corectPeselNumber) {
        std::cout << "Pesel number is incorrect\n";
    }
    return corectPeselNumber;
}

bool ValidationData::validatingGender(char userChoice) {
    if (std::tolower(userChoice) != 'f' && std::tolower(userChoice) != 'm') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong value, please choose f or m\n";
        return false;
    }
    return true;
}

ValidationData::YesNoConfirm ValidationData::confirmDataYesNo(std::string question) {
    std::string answer { };
    YesNoConfirm confirmation { YesNoConfirm::NoConfirm };
    std::cout << question << '\n';
    std::cout << "Yes(y)\n";
    std::cout << "No(n)\n";
    std::cout << "Back(b)\n";
    while (confirmation == YesNoConfirm::NoConfirm || confirmation == YesNoConfirm::Error) {    
        std::cin.clear();
        std::getline(std::cin, answer);
        if (answer == "Y" || answer == "y") {
            confirmation = YesNoConfirm::Yes;
        } else if (answer == "N" || answer == "n") {
            confirmation = YesNoConfirm::No;
        } else if (answer == "B" || answer == "b") {
            confirmation = YesNoConfirm::Back;
        } else {
            std::cout << "Wrong answer, you must choose Y, N or B\n";
            confirmation = YesNoConfirm::Error;
        }
    }
    return confirmation;
}