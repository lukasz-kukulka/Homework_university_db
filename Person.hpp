#pragma once

#include <string>

class Person {
public:
    enum class Gender : uint8_t {
        female,
        male
    };

    Person() = default;
    Person(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender);
    //virtual ~Person() = 0;

    virtual std::string getName() const { return name_; }
    virtual std::string getSurname() const { return surname_; }
    virtual std::string getAddress() const { return address_; }
    virtual std::string getPeselNumber() const { return peselNumber_; }
    virtual std::string getGender();

    virtual size_t getSizeNameLimit() const { return sizeNameLimit_; }
    virtual size_t getSizeSurnameLimit() const { return sizeSurnameLimit_; }
    virtual size_t getSizeAddressLimit() const { return sizeAddressLimit_; }
    virtual size_t getSizePeselNumberLimit() const { return sizePeselNumberLimit_; }
    virtual size_t getSizeGenderLimit() const { return sizePeselNumberLimit_; }

    virtual void printBorderTop();
    virtual void printStudent();
    virtual void printBorderBotton();
    virtual size_t getBorderSize();

protected:
    virtual std::string convertStudentGender(const Gender);

    std::string name_ {"testtt"};
    std::string surname_ { "cos aaaa aaaaaaaaaaaaaaa" };
    std::string address_{ "adress 3 3" };
    std::string peselNumber_{ "8282828002" };
    Gender gender_ { Gender::female };

    size_t sizeNameLimit_ { 16 };
    size_t sizeSurnameLimit_ { 30 };
    size_t sizeAddressLimit_ { 40 };
    size_t sizePeselNumberLimit_ { 14 };
    size_t sizeGenderLimit_ { 8 };
};