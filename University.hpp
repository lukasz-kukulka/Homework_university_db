#pragma once

class University {
public:
    University();

    enum class MenuOption {
        BaseMenu = 0,
        AddStudents,
        ShowStudent,
        SearchStudents,
        Exit,
        SearchBySurname,
        SearchByPESEL,
        SortBySurname,
        SortByPESEL,
        Back,
        Delete
    };

private:
    void printMenu();
    MenuOption menuOption { MenuOption::BaseMenu };
};