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
    

    std::string name_ {"test"};
    std::string surname_ { "cos tam jest" };
    std::string address_{ "adress 3" };
    std::string indexNumber_ { "8212343823" };
    std::string peselNumber_{ "82828282821" };
    Gender gender_ { Gender::female };

    uint8_t sizeNameLimit { 20 };
    uint8_t sizeSurnameLimit { 40 };
    uint8_t sizeAddressLimit { 60 };
    uint8_t sizeIndexNumberLimit { 10 };
    uint8_t sizePeselNumberLimit { 11 };
    uint8_t sizeGenderLimit { 6 };
};
