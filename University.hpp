#pragma once

#include "Person.hpp"
#include "Command.hpp"

#include <memory>
#include <vector>
#include <fstream>

using PersonIt = std::vector<std::shared_ptr<Person>>::iterator;
constexpr char DEFAULT_FILE_NAME[] { "records.txt" };

class University : public Command {
public:
    //University();
    ~University() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;
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
        KeepOriginal,
        Edit,
        Back
    }; 

    void applicationStart();

private:
    size_t printMenu();
    void addNewPerson();
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
    void deleteRecordByIndexNumber();

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

    void addStudentRecordToVector();
    void addProfesorRecordToVector();

    MenuOption menuEngine(size_t menuSize);
    bool validatingMenuChoose(const size_t choosenValueToValid, const size_t sizeMenu);
    void showStudents();
    void addOneRecordToEndFile(size_t personIndex, std::fstream & fileName);
    void loadFromFile(std::string fileName = DEFAULT_FILE_NAME);
    int countRecord(std::string fileMane = DEFAULT_FILE_NAME);

    void printSearchMenu();
    void printDeletePersonByIndexNumber();
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
    IfPersonExist ifPersonExist(size_t menuSize);
    void ifPersonExistMenu();
    void updateRecordIfPersonExist();
    void saveAllFile(std::string fileName = DEFAULT_FILE_NAME);
    void saveInNewFile();
    void printSaveInNewFile();
    void validationSaveInNewFile();
    void userInsertFileName();
    void saveNew();
    void printIfFileExist();
    void validationIfFileExist(size_t userChoice);

    void sortStudents();
    void printSortMenu();
    void sortMenuEngine();
    MenuOption validationUserChoiceSortMenu();
    void sortByPeselNumber();
    void sortBySurname();
    void sortBySalary();
    void ifExistCompare();
    size_t userChoiceIfFileExist();
    size_t saveNewIfFileExist();
    void clearLoad();
    void printClearLoadMenu();
    void clearVector();
    void loadToExist();
    void printLoadToExist();
    std::vector<std::shared_ptr<Person>> copyDataToTempContanair(std::vector<std::shared_ptr<Person>>& personCopy);
    void deleteDuplicate();

    void printInterfaceDataGenerator();
    void interfaceDataGeneratorStudent();
    void interfaceDataGeneratorProfessor();
    size_t interfaceDataGeneratorAll();
    void dataGenerator();
    void studentDataGenerator(size_t dataAmout);
    void professorDataGenerator(size_t dataAmout);
    void nameGenerator();
    void surnameGenerator();
    void addressGenerator();
    void indexNumberGenerator();
    void peselNumberGenerator();
    void professorSalaryGenerator();
    void genderGenerator();
    void loadFromFileToGenerateData(std::string fileName);
    std::string randomDataLoader(std::string fileName, size_t recordNumber);
    size_t randomDataGenerator(size_t maxElement, size_t minElement = 1);
    size_t countRecordGenerateData(std::string fileMane);
    std::string generateWeightPeselNumber(std::string pesel);

    void deleteByIndexNumber(std::string);
    std::string convertPersonGender(const size_t);
    YesNoOption yesNoOption();

    MenuOption menuOption_ { MenuOption::BaseMenu };
    std::string name_ { "test_name" };
    std::string surname_ { "test_surname" };
    std::string address_ { "test_address" };
    std::string indexNumber_ { "1111111111" };
    std::string peselNumber_ { "82040207834" };
    std::string professorSalary_ { "4000" };
    size_t gender_ { 1 };

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
    PersonIt checkedIfPersonExist_ { };

    std::string fileName_ { DEFAULT_FILE_NAME };
    std::fstream file_;
};
