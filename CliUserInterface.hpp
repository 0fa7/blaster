#pragma once

#include <iostream>
#include <string>

class UserInterface
{
public:
    virtual ~UserInterface() = default;
    
    virtual void postMessage(std::string message)
    {}

    virtual std::string commandEntered() 
    {
        return "commandEntered";
    }
};

class CliUserInterface : public UserInterface
{
public:
    CliUserInterface(std::istream& in, std::ostream& out) :
        in_(in), out_(out)
    {}

    ~CliUserInterface() override 
    {}

    void execute()
    {
        std::string buffer;

        while(std::getline(in_, buffer, '\n'))
        {   
            //auto tokens;
            if(buffer == "exit")
                return;
            else
                std::cout << ":" << buffer << std::endl;
            
        }
    }

private:
    std::istream& in_;
    std::ostream& out_;
};