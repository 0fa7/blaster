#pragma once

#include "Command.hpp"
#include "Mp3Player.hpp"

class Start : public Command
{
public:
    Start()
    {}

    ~Start() = default;

private:
    void executeImpl() override
    {
        std::cout << "START" << std::endl;
    }
};

class Stop : public Command
{
public:
    Stop()
    {}

    ~Stop() = default;

private:
    void executeImpl() override
    {
        std::cout << "STOP" << std::endl;
    }
};

class Add : public Command
{
public:
    Add(string_view song) : song_(song)
    {}

    ~Add() = default;

private:
    void executeImpl() override
    {
        std::cout << "ADD" << std::endl;
    }

    std::string song_;
};

class Remove : public Command
{
public:
    Remove()
    {}

    ~Remove() = default;

private:
    void executeImpl() override
    {
        std::cout << "REMOVE" << std::endl;
    }
};