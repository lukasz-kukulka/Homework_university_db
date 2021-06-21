#pragma once
#include "Student.hpp"

#include <vector>
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
    void insertAddress();
    void insertStudentIndexNumber();
    void insertStudentPeselNumber();
    void insertStudentGender();

    bool validatingName();
    bool validatingSurname();
    bool validatingIndexNumber();
    bool validatingPeselNumber();
    bool validatingGender();
    bool validatingAddress();

    MenuOption menuEngine();
    void showStudents();

    MenuOption menuOption_ { MenuOption::BaseMenu };
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string indexNumber_;
    std::string peselNumber_;
    size_t gender_;
    std::vector<Student>students;
};