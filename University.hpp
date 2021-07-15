#pragma once
#include "Student.hpp"
#include "Person.hpp"

#include <vector>

class University {
public:
    University();
    enum class MenuOption {
        BaseMenu = 0,
        AddStudents,
        ShowStudent,
        SearchStudents,
        SortStudents,
        SaveLoadFile,
        Delete = 200,
        Exit,
        SearchBySurname = 11,
        SearchByPESEL = 12,
        SortBySurname = 21,
        SortByPESEL = 22,
        Back = 100
    };

    enum class YesNoOption {
        Yes,
        No,
        Error
    };

    void applicationStart();

private:
    void printMenu();
    void addNewStudent();

    void insertStudentName();
    void insertStudentSurname();
    void insertAddress();
    void insertStudentIndexNumber();
    void insertStudentGender();
    void insertStudentPeselNumber();

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
    bool validatingMenuChoose(const int);
    void showStudents();
    void saveToFile(size_t);
    void loadFromFile();
    int countRecord();

    void printSearchMenu();
    MenuOption searchMenuStudent();
    void searchMenuEngine();
    bool validatingSearchAndSortMenuChoose(const int);
    std::string insertSearchPeselNumber();
    void checkIfExistPeselNumber(std::string);
    void searchByPeselNumber();
    std::string insertSearchSurname();
    void checkIfExistSurname(std::string);
    void searchBySurname();

    void sortStudents();
    void printSortMenu();
    void sortMenuEngine();
    MenuOption sortMenuStudent();
    void sortByPeselNumber();
    void sortBySurname();

    void deleteByIndexNumber(std::string);
    std::string convertStudentGender(const size_t);
    YesNoOption yesNoOption();

    MenuOption menuOption_ { MenuOption::BaseMenu };
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string indexNumber_;
    std::string peselNumber_;
    size_t gender_;
    std::vector<Person>person_;
    Student tempStudent_;
};