#pragma once
#include "Student.hpp"

class University {
public:
    University();

    enum class MenuOption {
        BaseMenu = 0,
        AddStudents = 1,
        ShowStudent = 2,
        SearchStudents = 3,
        Exit = 4,
        SearchBySurname = 11,
        SearchByPESEL = 12,
        SortBySurname = 21,
        SortByPESEL = 22,
        Back = 100,
        Delete = 200
    };

private:
    void printMenu();
    void addNewStudent();

    void insertStudentName();
    void insertStudentSurname();
    void insertStudentIndexNumber();
    void insertStudentPeselNumber();
    void insertStudentGender();

    bool validatingName();

    MenuOption menuEngine();

    MenuOption menuOption_ { MenuOption::BaseMenu };
    std::string name_;
    std::string surname_;
    size_t indexNumber_;
    uint64_t peselNumber_;
    size_t gender_;
};