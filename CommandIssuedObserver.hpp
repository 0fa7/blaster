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
        auto cmd = std::any_cast<string>(data);
        ci_.commandEntered(cmd);
    }

    CommandInterpreter& ci_;
};