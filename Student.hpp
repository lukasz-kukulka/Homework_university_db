#pragma once

#include <string>

class Student {
public:
    enum class Gender : uint8_t {
        female,
        male
    };
    Student() = default;
    Student(std::string, std::string, std::string, std::string, std::string, Gender);
    
    void prindBorderTop();
    void printStudent();
    void printBorderBotton();
    std::string convertStudentGender(const Gender);
private:
    

    std::string name_ {"testt"};
    std::string surname_ { "cos aaaaaaaaaaaaaaaaaaa" };
    std::string address_{ "adress 33" };
    std::string indexNumber_ { "8212343823s" };
    std::string peselNumber_{ "82828282821" };
    Gender gender_ { Gender::female };

    uint8_t sizeNameLimit { 15 };
    uint8_t sizeSurnameLimit { 30 };
    uint8_t sizeAddressLimit { 40 };
    uint8_t sizeIndexNumberLimit { 12 };
    uint8_t sizePeselNumberLimit { 13 };
    uint8_t sizeGenderLimit { 8 };
};
