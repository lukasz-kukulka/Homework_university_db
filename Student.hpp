#pragma once

#include <string>

#include "Person.hpp"

class Student : public Person {
public:
    Student() = default;
    Student(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, std::string indexNumber);
    ~Student(){};

    // void printBorderTop() override;
    void printPerson() override;
    void printBorderBotton() override;
    size_t getBorderSize() override;

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    std::string getPeselNumber() const { return peselNumber_; }
    std::string getGender();

    std::string getIndexNumber() const { return indexNumber_; }

    size_t getSizeIndexNumberLimit() const { return sizeIndexNumberLimit_; }

private:
    std::string indexNumber_ {};
};
