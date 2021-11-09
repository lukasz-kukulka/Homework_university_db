#pragma once

#include "Command.hpp"
#include "Person.hpp"
#include "ValidationData.hpp"

#include <memory>
#include <utility>

class SearchPerson : public Command {
public:
    enum class SearchMenu{
        NoChoice,
        SearchByName,
        SearchBySurname,
        SearchByAddress,
        SearchByPeselNumber,
        SearchByGender,
        SearchByIndex,
        SearchBySalary,
        Back
    };
    SearchPerson(std::shared_ptr<ValidationData> validation);
    ~SearchPerson() = default;
    void operator()(std::vector<std::shared_ptr<Person>>& person) override;

private:
    int printSearchMenu();
    int validationUserInsertDataMenu(int userAnswer);
    std::string insertSearchData(std::string searchChoice);
    SearchMenu searchMenu(int userChoice, std::vector<std::shared_ptr<Person>>& person);
    void printSearchResult();
    void deleteRecord();

    void searchByName(std::string nameToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchBySurname(std::string surnameToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchByAddress(std::string addressToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchByPeselNumber(std::string peselToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchByGender(std::string genderToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchByIndexNumber(std::string indexNumberToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchBySalary(std::string salaryToSearch, std::vector<std::shared_ptr<Person>>& person);

    std::shared_ptr<ValidationData>validation_;
    std::vector<std::pair<std::shared_ptr<Person>>, std::unique_ptr<Person>> foundPersons_;
    SearchMenu currentlyChoice_ { SearchMenu::NoChoice };
};