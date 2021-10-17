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
        Cancel,
        Back
    }; 

    enum class EditPerson {
        NoChoice,
        LeaveOld,
        AddNew,
        Edit,
        Cancel
    }; 

private:
    WhichPerson selectPerson()  ;
    std::string insertPersonName();
    std::string insertPersonSurname();
    std::string insertPersonAddress();
    std::string insertPersonPesel();
    std::string insertPersonGender();
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
    void printMenuIfPersonExist(std::vector<std::shared_ptr<Person>>& person);
    ExistingPersonMenu isPersonExistMenu(AddPerson::ExistingPersonMenu userChoice, std::vector<std::shared_ptr<Person>>& person);
    ExistingPersonMenu isPersonExistMenuUserChoice(int optionNumber);

    ExistingPersonMenu saveNewIsPersonExist(std::vector<std::shared_ptr<Person>>& person);
    ExistingPersonMenu leaveExistIsPersonExist();
    ExistingPersonMenu editIsPersonExist();
    ExistingPersonMenu cancelIsPersonExist();

    void editName();
    void editSurname();
    void editAddress();
    void editPeselNumber();
    void editGender();
    void editIndexNumber();
    void editSalary();

    
    void clearTemporaryData();
    std::string confirmEditPerson(std::string oldRecord, std::string newRecord, EditPerson userAnswer, std::string editAnswer = "");
    int printMenuConfirmEditPerson();
    EditPerson userChoiceConfirmEditPerson();

    std::shared_ptr<ValidationData>validation_;
    WhichPerson whichPerson_ { WhichPerson::NoPerson };
    std::vector<std::shared_ptr<Person>>::iterator existPerson_ { nullptr };

    std::string name_ { };
    std::string surname_ { };
    std::string address_ { };
    std::string peselNumber_ { };
    std::string gender_ { };
    std::string indexNumber_ { };
    std::string salary_ { };

    ansvers yesNoAnsver_ { ansvers::NoConfirm };
    ExistingPersonMenu existingPersonMenu_ { ExistingPersonMenu::NoChoice };
};