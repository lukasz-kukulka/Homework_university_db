#pragma once

class University {
public:
    University();

    enum class MenuOption {
        BaseMenu = 0,
        AddStudents = 1,
        ShowStudent = 2,
        SearchStudents = 3,
        Exit = 4,
        SearchBySurname = 11,
        SearchByPESEL = 12,
        SortBySurname = 21,
        SortByPESEL = 22,
        Back = 100,
        Delete = 200
    };

private:
    void printMenu();
    MenuOption menuEngine();
    MenuOption menuOption_ { MenuOption::BaseMenu };
};