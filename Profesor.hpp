#pragma once

#include <string>

class Profesor {
public:
    enum class Gender : uint8_t {
        female,
        male
    };
    Profesor() = default;
    Profesor(std::string name, std::string surname, std::string address, std::string peselNumber, Gender gender, size_t salary);

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    std::string getPeselNumber() const { return peselNumber_; }
    std::string getGender();

    size_t getSalary() const { return salary_; }

    uint8_t getSizeNameLimit() const { return sizeNameLimit_; }
    uint8_t getSizeSurnameLimit() const { return sizeSurnameLimit_; }
    uint8_t getSizeAddressLimit() const { return sizeAddressLimit_; }
    uint8_t getSizePeselNumberLimit() const { return sizePeselNumberLimit_; }

    uint8_t getSizeSalaryLimit() const { return sizeSalaryLimit_; }

private:
    std::string convertStudentGender(const Gender);

    std::string name_ {"testtt"};
    std::string surname_ { "cos aaaa aaaaaaaaaaaaaaa" };
    std::string address_{ "adress 3 3" };
    std::string peselNumber_{ "8282828002" };
    Gender gender_ { Gender::female };

    size_t salary_ { 1000 };

    size_t sizeNameLimit_ { 16 };
    size_t sizeSurnameLimit_ { 30 };
    size_t sizeAddressLimit_ { 40 };
    size_t sizePeselNumberLimit_ { 14 };
    size_t sizeGenderLimit_ { 8 };

    size_t sizeSalaryLimit_ { 6 };
};