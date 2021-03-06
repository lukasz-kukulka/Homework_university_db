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
    int userMenuOptionChoice();
    int validationUserInsertDataMenu();
    std::string insertSearchData(std::string searchChoice);
    SearchMenu searchMenu(int userChoice, std::vector<std::shared_ptr<Person>>& person);
    void copyFoundPersonsForPrint();
    void printSearchResult();
    void deleteRecords(std::vector<std::shared_ptr<Person>>& person);
    void deleteSingleRecord(std::vector<std::shared_ptr<Person>>& person, size_t indexNumber);
    void printDeleteInterface();
    std::string deleteInterfaceUserAnswer();
    bool validationDeleteInterfaceUserAnswer(std::string userAnswer);
    size_t insertIndexNumberToDelete();

    void searchByName(std::string nameToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchBySurname(std::string surnameToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchByAddress(std::string addressToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchByPeselNumber(std::string peselToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchByGender(std::string genderToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchByIndexNumber(std::string indexNumberToSearch, std::vector<std::shared_ptr<Person>>& person);
    void searchBySalary(std::string salaryToSearch, std::vector<std::shared_ptr<Person>>& person);

    std::shared_ptr<ValidationData>validation_;
    std::vector<std::shared_ptr<Person>>foundPersons_;
    std::vector<std::pair<std::shared_ptr<Person>, size_t>> foundPersonsPlusIndexNumber_;
    SearchMenu currentlyChoice_ { SearchMenu::NoChoice };
};