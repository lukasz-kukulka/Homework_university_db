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
        GenerateData,
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

    enum class LoadSaveOption {
        NoChoice,
        Save,
        SaveNew,
        ClearLoad,
        LoadToExist,
        Back
    };   

    enum class IfPersonExist {
        NoChoice,
        Compare,
        Update,
        Edit,
        Back
    }; 

    void applicationStart();

private:
    size_t printMenu();
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

    MenuOption menuEngine(size_t menuSize);
    bool validatingMenuChoose(const size_t choosenValueToValid, const size_t sizeMenu);
    void showStudents();
    void saveToFile(size_t);
    void loadFromFile();
    int countRecord();

    void printSearchMenu();
    MenuOption searchMenuStudent();
    void searchMenuEngine();
    bool validatingSearchAndSortMenuChoose(const int);
    std::string insertSearchPeselNumber();
    bool checkIfExistPeselNumber(std::string);
    void printSetSalaryMenu();
    void searchByPeselNumber();
    void searchBySalary();
    std::string insertSearchSalary();
    std::string insertSearchSurname();
    void checkIfExistSurname(std::string);
    void searchBySurname();
    void whichPersonIs(Person* person);
    size_t choiceSetSalary();
    void salaryOptions(size_t userChoice);
    void changingSalary(std::string newSalary);
    size_t printSaveLoadMenu();
    LoadSaveOption menuLoadSaveEngine(size_t menuSize);
    void loadSaveMenu();
    std::vector<std::shared_ptr<Person>>::iterator isPersonExist();
    size_t printMenuIfPersonExist();


    void sortStudents();
    void printSortMenu();
    void sortMenuEngine();
    MenuOption validationUserChoiceSortMenu();
    void sortByPeselNumber();
    void sortBySurname();
    void sortBySalary();

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
    std::shared_ptr<Person>currentlyPerson_;
    WhichPerson userChoicePerson_ { WhichPerson::Anyone };
    WhichPerson currentlyReadingRecord_ { WhichPerson::Anyone };
    LoadSaveOption userChoiceLoadSave_ { LoadSaveOption::NoChoice };
    IfPersonExist userChoiceIfExist_ { IfPersonExist::NoChoice };
};
