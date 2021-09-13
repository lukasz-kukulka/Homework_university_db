#pragma once
#include "Command.hpp"
#include "ValidationData.hpp"
#include "Person.hpp"
#include <memory>
#include <string>
#include <limits> //for numeric_limits
#include <ios> // for std::streamsize

class AddPerson : public Command {
public:
    AddPerson(std::shared_ptr<ValidationData> validation);
    ~AddPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>> person) const override;

    enum class WhichPerson {
        NoPerson = 0,
        Student,
        Professor,
        Back
    };

private:
    WhichPerson selectPerson() const ;
    std::string insertPersonName();
    std::string insertPersonSurname();
    std::string insertPersonAddress();
    std::string insertPersonPesel();
    std::string insertPersonGender();
    std::string insertStudentIndexNumber();
    std::string insertProfessorSalary();
    
    void addingPerson(std::vector<std::shared_ptr<Person>>person) const ;
    void addStudentToDatabase(std::vector<std::shared_ptr<Person>>person) const ;
    void addProfessorToDatabase(std::vector<std::shared_ptr<Person>>person) const ;

    std::shared_ptr<ValidationData>validation_;
    WhichPerson whichPerson_ { WhichPerson::NoPerson };
};