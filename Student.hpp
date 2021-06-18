#pragma once

#include <string>

class Student {
public:
    enum class Gender{
        female,
        male
    };

    Student(std::string, std::string, size_t, uint64_t, Gender);

private:
    std::string name_;
    std::string surname_;
    size_t indexNumber_;
    uint64_t peselNumber_;
    Gender gender_;
};
