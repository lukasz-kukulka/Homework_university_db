#include "Person.hpp"
#include "Command.hpp"
#include <vector>

class Menu :public Command {
public:
    ~Menu() = default;
    void operator()(std::vector<Person>*person) const override;
};

