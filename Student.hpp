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
    
    void printBorderTop();
    void printStudent();
    void printBorderBotton();
    int getBorderSize() const;

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    std::string getIndexNumber() const { return indexNumber_; }
    std::string getPeselNumber() const { return peselNumber_; }
    std::string getGender();
private:
    std::string convertStudentGender(const Gender);

    std::string name_ {"testtt"};
    std::string surname_ { "cos aaaa aaaaaaaaaaaaaaa" };
    std::string address_{ "adress 3 3" };
    std::string indexNumber_ { "8212343823" };
    std::string peselNumber_{ "8282828002" };
    Gender gender_ { Gender::female };

    uint8_t sizeNameLimit { 16 };
    uint8_t sizeSurnameLimit { 30 };
    uint8_t sizeAddressLimit { 40 };
    uint8_t sizeIndexNumberLimit { 12 };
    uint8_t sizePeselNumberLimit { 14 };
    uint8_t sizeGenderLimit { 8 };
};
