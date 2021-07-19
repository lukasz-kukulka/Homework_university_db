#pragma once

#include "Person.hpp"

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
        SearchBySalary = 13,
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

    enum class WhichPerson {
        Anyone,
        Student,
        Professor
    };

    void applicationStart();

private:
    void printMenu();
    void addNewStudent();
    void printInsertPersonData();
    void confirmAddRecord();
    void selectPerson();

    void insertStudentName();
    void insertStudentSurname();
    void insertAddress();
    void insertStudentGender();
    void insertStudentPeselNumber();
    void insertStudentIndexNumber();
    void insertProfessorSalary();

    bool validationSelectPerson(size_t userChoice);
    void assignmentPersonValue(size_t userChoice);
    bool validationStringSize(std::string userStringData, size_t maxSize, bool isEqual = false);
    bool validationIsAlpabet(std::string stringToCheck);
    bool validationIsDigit(std::string stringToCheck);
    bool peselValidDOBCheck();
    bool peselValidGenderCheck();
    bool peselValidWithCurrentlyDate();
    bool peselValidWithWeight();
    bool validatingPeselNumber();
    bool validatingGender();

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
    void searchBySalary();
    std::string insertSearchSalary();
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
    std::string convertPersonGender(const size_t);
    YesNoOption yesNoOption();

    MenuOption menuOption_ { MenuOption::BaseMenu };
    std::string name_ {};
    std::string surname_ {};
    std::string address_ {};
    std::string indexNumber_ {};
    std::string peselNumber_ {};
    std::string professorSalary_ {};
    size_t gender_ {};

    size_t sizeNameLimit_ { 16 };
    size_t sizeSurnameLimit_ { 30 };
    size_t sizeAddressLimit_ { 40 };
    size_t sizePeselNumberLimit_ { 11 };
    size_t sizeGenderLimit_ { 6 };
    size_t sizeIndexNumberLimit_ { 10 };
    size_t sizeSalaryLimit_ { 5 };

    std::vector<std::shared_ptr<Person>>person_;
    WhichPerson userChoicePerson_ { WhichPerson::Anyone };
};
