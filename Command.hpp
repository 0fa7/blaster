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
        executeImpl();
    }

    void deallocate()
    {}

protected:
    virtual void executeImpl() = 0;
};

inline void CommandDeleter(Command* p)
{
    if(p)
        p->deallocate();
}

using CommandPtr = unique_ptr<Command, decltype(&CommandDeleter)>;

template<typename T, typename... Args>
auto MakeCommandPtr(Args&&... args) requires std::derived_from<T, Command>
{
    return CommandPtr{new T{std::forward<Args>(args)...}, &CommandDeleter};
}

inline auto MakeCommandPtr(Command* p)
{
    return CommandPtr{p, &CommandDeleter};
}