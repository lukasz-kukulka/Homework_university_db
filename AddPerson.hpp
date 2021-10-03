#pragma once
#include "Command.hpp"
#include "ValidationData.hpp"
#include "Person.hpp"
#include <memory>
#include <string>
#include <limits> //for numeric_limits
#include <ios> // for std::streamsize

using ansvers = ValidationData::YesNoConfirm;

class AddPerson : public Command {
public:
    AddPerson(std::shared_ptr<ValidationData> validation);
    ~AddPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

    enum class WhichPerson {
        NoPerson = 0,
        Student,
        Professor,
        Back
    };

    enum class ExistingPersonMenu {
        NoChoice,
        SaveNew,
        LeaveExist,
        Edit,
        Cancel
    }; 

private:
    WhichPerson selectPerson()  ;
    std::string insertPersonName();
    std::string insertPersonSurname();
    std::string insertPersonAddress();
    std::string insertPersonPesel();
    char insertPersonGender();
    std::string insertStudentIndexNumber();
    std::string insertProfessorSalary();
    
    void generateData(WhichPerson userChoice);
    void addingPerson(std::vector<std::shared_ptr<Person>>& person);
    void addStudentToDatabase(std::vector<std::shared_ptr<Person>>& person);
    void addProfessorToDatabase(std::vector<std::shared_ptr<Person>>& person);
    void confirmAddRecord(std::vector<std::shared_ptr<Person>>& person);
    std::vector<std::shared_ptr<Person>>::iterator isPersonExist(std::vector<std::shared_ptr<Person>>& person);
    void printAddingPerson();
    void printExistingPerson(std::shared_ptr<Person>& person);
    void existingPerson(std::vector<std::shared_ptr<Person>>& person);
    void printMenuIfPersonExist();
    void isPersonExistMenu(size_t userChoice);
    size_t isPersonExistMenuUserChoice(int optionNumber);

    void saveNewIsPersonExist();
    void leaveExistIsPersonExist();
    void editIsPersonExist();
    void cancelIsPersonExist();

    std::shared_ptr<ValidationData>validation_;
    WhichPerson whichPerson_ { WhichPerson::NoPerson };

    std::string name_ { };
    std::string surname_ { };
    std::string address_ { };
    std::string peselNumber_ { };
    char gender_ { };
    std::string indexNumber_ { };
    std::string salary_ { };

    ansvers yesNoAnsver_ { ansvers::NoConfirm };
    ExistingPersonMenu existingPersonMenu_ { ExistingPersonMenu::NoChoice };
};