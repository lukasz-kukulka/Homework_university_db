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
    virtual ~Person();

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    std::string getPeselNumber() const { return peselNumber_; }
    std::string getGender() { return convertPersonGender(gender_); };
    virtual std::string getSalary() const { return salary_; }
    virtual std::string getIndexNumber() const { return indexNumber_; }
    
    size_t getSizeNameLimit() const { return sizeNameLimit_; }
    size_t getSizeSurnameLimit() const { return sizeSurnameLimit_; }
    size_t getSizeAddressLimit() const { return sizeAddressLimit_; }
    size_t getSizePeselNumberLimit() const { return sizePeselNumberLimit_; }
    size_t getSizeGenderLimit() const { return sizePeselNumberLimit_; }

    void setSalary(std::string salary) { salary_ = salary; }

    virtual void printBorderTop() = 0;
    virtual void printPerson() = 0;
    virtual void printBorderBotton() = 0;
    virtual size_t getBorderSize() = 0;

protected:
    std::string convertPersonGender(const Gender);

    std::string name_ {"testtt"};
    std::string surname_ { "cos aaaa aaaaaaaaaaaaaaa" };
    std::string address_{ "adress 3 3" };
    std::string peselNumber_{ "82828280021" };
    Gender gender_ { Gender::female };
    std::string salary_{ "NO_SALARY" };
    std::string indexNumber_ { "NO_INDEX" };

    size_t sizeNameLimit_ { 16 };
    size_t sizeSurnameLimit_ { 30 };
    size_t sizeAddressLimit_ { 40 };
    size_t sizePeselNumberLimit_ { 14 };
    size_t sizeGenderLimit_ { 8 };
    size_t sizeSalaryLimit_ { 10 };
};