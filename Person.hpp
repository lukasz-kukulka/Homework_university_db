#pragma once

#include <string>

class Person {
public:
    Person() = default;
    Person(std::string name, std::string surname, std::string address, std::string peselNumber, char gender);
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

    void printBorderTop();
    size_t getBorderSize();
    void printBorderLine();
    virtual void printPerson() = 0;

    std::string generateCell(std::string cellBody, size_t cellSize);

protected:
    std::string convertPersonGender(const char gender);

    std::string name_ {"NO_NAME"};
    std::string surname_ { "NO_SURNAME" };
    std::string address_{ "NO_ADDRESS" };
    std::string peselNumber_{ "00000000000" };
    char gender_ { 'f' };
    std::string salary_{ "NO_SALARY" };
    std::string indexNumber_ { "NO_INDEX" };

    size_t sizeNameLimit_ { 16 };
    size_t sizeSurnameLimit_ { 30 };
    size_t sizeAddressLimit_ { 40 };
    size_t sizePeselNumberLimit_ { 14 };
    size_t sizeGenderLimit_ { 8 };
    size_t sizeSalaryLimit_ { 10 };
    size_t sizeIndexNumberLimit_ { 12 };
};