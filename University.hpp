#pragma once

#include "Person.hpp"
#include "Student.hpp"

#include <memory>
#include <vector>

class University {
public:
    University();
    //~University();
    enum class MenuOption {
        BaseMenu = 0,
        AddStudents,
        ShowStudent,
        SearchStudents,
        SortStudents,
        SaveLoadFile,
        Exit,
        SearchBySurname = 11,
        SearchByPESEL = 12,
        SortBySurname = 21,
        SortByPESEL = 22,
        Back = 100,
        Delete = 200
    };

    enum class YesNoOption {
        Yes,
        No,
        Error
    };

    enum class WithPerson {
        Anyone,
        Student,
        Professor
    };

    void applicationStart();

private:
    void printMenu();
    void addNewStudent();
    void confirmAddRecord();
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

    size_t sizeNameLimit_ { 16 };
    size_t sizeSurnameLimit_ { 30 };
    size_t sizeAddressLimit_ { 40 };
    size_t sizePeselNumberLimit_ { 11 };
    size_t sizeGenderLimit_ { 6 };
    size_t sizeIndexNumberLimit_ { 10 };
    size_t sizeSalaryLimit_ { 6 };

    std::vector<std::shared_ptr<Person>>person_;
};