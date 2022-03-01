#pragma once

#include "Command.hpp"

class CommandManager
{
public:
    CommandManager() = default;
    ~CommandManager() = default;

    void executeCommand(CommandPtr c)
    {
        c->execute();
    }
};