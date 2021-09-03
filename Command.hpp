
#include "Person.hpp"
#include <vector>
class Command {
public:
    virtual ~Command() = default;
    virtual void operator()(std::vector<Person>*) = 0;
};