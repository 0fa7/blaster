#pragma once

#include <memory>

#include "CommandManager.hpp"
#include "CoreCommands.hpp"

using std::make_unique;

class CommandInterpreter
{
public:
    class CommandInterpreterImpl
    {
    public:
        CommandInterpreterImpl(UserInterface& ui) :
        ui_(ui)
        {}

        void executeCommand(const string& command)
        {
            handleCommand(command);
        }

    private:
        void handleCommand(const string& command)
        {
            string_view sv{command};

            if(sv == "play")
            {
                cm_.executeCommand(MakeCommandPtr<Add>(command));
                cm_.executeCommand(MakeCommandPtr<Start>());
            }
            else if(sv == "start")
                cm_.executeCommand(MakeCommandPtr<Start>());
            else if(sv == "stop")
                cm_.executeCommand(MakeCommandPtr<Stop>());
            else if(sv == "add")
                cm_.executeCommand(MakeCommandPtr<Add>(command));
            else if(sv == "remove")
                cm_.executeCommand(MakeCommandPtr<Remove>());
            
        }

        CommandManager cm_;
        UserInterface& ui_;
    };

    CommandInterpreter(UserInterface& ui) :
    pimpl_(make_unique<CommandInterpreterImpl>(ui))
    {}

    ~CommandInterpreter() 
    {}

    void commandEntered(const string& command)
    {
        pimpl_->executeCommand(command);
    }

private:
    CommandInterpreter(const CommandInterpreter&) = delete;
    CommandInterpreter(CommandInterpreter&&) = delete;
    CommandInterpreter& operator=(const CommandInterpreter&) = delete;
    CommandInterpreter& operator=(CommandInterpreter&&) = delete;

    unique_ptr<CommandInterpreterImpl> pimpl_;
};