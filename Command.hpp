#pragma once
#include "Person.hpp"
#include <vector>
#include <memory>
class Command {
public:
    virtual ~Command() = default;
    virtual void operator()(std::vector<std::shared_ptr<Person>>& person)  = 0;
};