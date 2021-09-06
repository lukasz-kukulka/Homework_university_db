#pragma once
#include "Person.hpp"
#include "Command.hpp"
#include "ValidationData.hpp"
#include <vector>
#include <memory>

class Menu {
public:
    Menu();
    
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
    
    void printMenu();
    void switchMenu();
    std::vector<std::shared_ptr<Person>>person_;
    std::unique_ptr<Command>command_;
    std::shared_ptr<ValidationData>valid_;
    size_t menuSize_ = { };
};

