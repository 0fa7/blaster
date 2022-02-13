#pragma once

class CommandInterpreter
{
public:
    CommandInterpreter(UserInterface& ui)
    {}

    ~CommandInterpreter() 
    {}
private:
    CommandInterpreter(const CommandInterpreter&) = delete;
    CommandInterpreter(CommandInterpreter&&) = delete;
    CommandInterpreter& operator=(const CommandInterpreter&) = delete;
    CommandInterpreter& operator=(CommandInterpreter&&) = delete;
};