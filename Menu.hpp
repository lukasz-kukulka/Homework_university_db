#pragma once
#include "Person.hpp"
#include "Command.hpp"
#include <vector>
#include <memory>

class Menu {
public:

    enum class MenuOptions {
        AddPerson,
        ShowStudent,
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
    void switchMenu() const;
    std::unique_ptr<Command>command_;
};

