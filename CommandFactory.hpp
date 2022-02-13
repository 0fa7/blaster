#pragma once

#include <unordered_map>

#include "CliUserInterface.hpp"
#include "Command.hpp"

using std::unordered_map;

class CommandFactory
{
public:
    void registerCommand()
    {

    }

    using Factory = unordered_map<string, CommandPtr>;
    Factory factory_;
};

static void RegisterCoreCommands(UserInterface& ui)
{

}