#pragma once

#include "Command.hpp"
#include "Mp3Player.hpp"

class Play : public Command
{
public:
    Play(string_view song) : song_(song)
    {}

    ~Play() = default;

private:
    void executeImpl() override
    {}

    std::string song_;
};

class Stop : public Command
{
public:
    Stop()
    {}

    ~Stop() = default;

private:
    void executeImpl() override
    {}
};