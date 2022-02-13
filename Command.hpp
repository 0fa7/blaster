#pragma once

#include <memory>

using std::unique_ptr;

class Command
{
public:
    Command() = default;
    
    virtual ~Command() = default;

    Command(const Command&) = default;

    Command(Command&&) = delete;

    Command& operator=(const Command&) = delete;
    
    Command& operator=(Command&&) = delete;

    void execute()
    {
    }

    void executeImpl()
    {
    }

    void deallocate()
    {}
};

inline void CommandDeleter(Command* p)
{
    if(p)
        p->deallocate();
}

using CommandPtr = unique_ptr<Command, decltype(&CommandDeleter)>;