#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "Tokenizer.hpp"
#include "Publisher.hpp"

using std::istringstream;

class UserInterface : public Publisher
{
public:
    virtual ~UserInterface() = default;
    
    virtual void postMessage(std::string message)
    {}

    static std::string commandEntered() 
    {
        return "commandEntered";
    }
};

class CliUserInterface : public UserInterface
{
public:
    CliUserInterface(std::istream& in, std::ostream& out) :
        in_(in), out_(out)
    {
        registerEvent(commandEntered());
    }

    ~CliUserInterface() override 
    {}

    void execute()
    {
        std::string buffer;

        while(std::getline(in_, buffer, '\n'))
        {   
            istringstream ts(buffer);
            Tokenizer tokenize(ts);

            if(tokenize.size() > 0)
            {
                if(tokenize[0] == "exit")
                    return;
                else
                    raise(commandEntered(), tokenize.tokens_);        
            }
        }
    }

private:
    std::istream& in_;
    std::ostream& out_;
};