#pragma once
#include "Person.hpp"
#include "Command.hpp"
#include <vector>
#include <memory>

class Menu {
public:

    enum class MenuOptions {
        AddPerson = 1,
        ShowPersons,
        SearchPerson,
        SortPerson,
        SaveLoadFile,
        GenerateData,
        DeletePerson,
        Exit
    };
    
    void startApp();
private:
    
    void printMenu() const;
    void switchMenu();
    std::vector<std::shared_ptr<Person>>person_;
    std::unique_ptr<Command>command_;
};

