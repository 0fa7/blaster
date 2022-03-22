#pragma once

#include "CommandInterpreter.hpp"
#include "Observer.hpp"

class CommandIssuedObserver : public Observer
{
public:
    CommandIssuedObserver(CommandInterpreter& ci) : 
    Observer{"CommandIssued"}, ci_(ci)
    {}
    
    ~CommandIssuedObserver() 
    {}

    void notifyImpl(const any& data) override
    {
        auto cmds = std::any_cast<vector<string>>(data);
        ci_.commandEntered(cmds);
    }

    CommandInterpreter& ci_;
};