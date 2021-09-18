#pragma once
#include <stdlib.h> // for size_t
class ValidationData {
public:
    bool isCorrectMenuChoice(const size_t choosenValueToValid, const size_t sizeMenu);
    bool validationIsAlpabet(std::string stringToCheck);
private:

};