#pragma once
#include "Student.hpp"

#include <vector>
class University {
public:
    University();
    void insertStudentPeselNumber();
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
    void applicationStart();
    void printMenu();
    void addNewStudent();

    void insertStudentName();
    void insertStudentSurname();
    void insertAddress();
    void insertStudentIndexNumber();
    
    void insertStudentGender();

    bool validatingName();
    bool validatingSurname();
    bool validatingIndexNumber();
    bool peselValidDOBCheck();
    bool peselValidGenderCheck();
    bool peselValidWithCurrentlyDate();
    bool peselValidWithWeight();
    bool validatingPeselNumber();
    bool validatingGender();
    bool validatingAddress();

    MenuOption menuEngine();
    void showStudents();
    void saveToFile(size_t);
    void loadFromFile();
    int countRecord();

    MenuOption searchStudent();
    void searchByPeselNumber(std::string);
    void searchBySurname(std::string);
    void sortByPeselNumber();
    void sortBySurname();
    void deleteByIndexNumber(std::string);

    MenuOption menuOption_ { MenuOption::BaseMenu };
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string indexNumber_;
    std::string peselNumber_;
    size_t gender_;
    std::vector<Student>students;
    Student tempStudent;
};