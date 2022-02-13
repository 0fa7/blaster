#pragma once

//#include "CommandInterpreter.hpp"
#include "Observer.hpp"

class CommandIssuedObserver : public Observer
{
public:
    //explicit CommandIssuedObserver(CommandInterpreter& ci);

private:
    void notifyImpl(const any&) override;

    //CommandInterpreter& ci_;
};