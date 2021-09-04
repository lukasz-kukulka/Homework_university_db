#include "Person.hpp"
#include "Command.hpp"
#include <vector>

class Menu :public Command {
public:
    ~Menu() = default;
    void operator()(std::vector<Person>*person) const override;

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

private:
    void printMenu() const;
    void switchMenu();
};

