#pragma once

#include "Observer.hpp"

class CommandIssuedObserver : public Observer
{
public:
    CommandIssuedObserver() : Observer{"CommandIssued"}
    {}
    
    ~CommandIssuedObserver() 
    {}

    void notifyImpl(const any& data) override
    {
    }
};