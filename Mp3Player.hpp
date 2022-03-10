#pragma once

#include <filesystem>

#include "Publisher.hpp"

class Mp3PlayerErrorData
{
public:
    enum class ErrorConditions { Empty, TooFewArguments };
    explicit Mp3PlayerErrorData(ErrorConditions e) : err_(e) { }

    static const char* Message(ErrorConditions ec);
    const char* message() const;
    ErrorConditions error() const { return err_; }

private:
    ErrorConditions err_;
};

class Mp3Player : private Publisher
{
public:
    static Mp3Player& Instance();
    void play(string_view song, bool suppressChangeEvent = false);
    void start(bool suppressChangeEvent = false);
    void stop(bool suppressChangeEvent = false);
    void add(string_view song, bool suppressChangeEvent = false);
    void remove(bool suppressChangeEvent = false);

    using Publisher::attach;
    using Publisher::detach;

    static string Mp3PlayerChanged();
    static string Mp3PlayerError();

private:
    Mp3Player();
    ~Mp3Player() = default;
    Mp3Player(const Mp3Player&) = delete;
    Mp3Player(Mp3Player&&) = delete;
    Mp3Player& operator=(const Mp3Player&) = delete;
    Mp3Player& operator=(const Mp3Player&&) = delete;

    string song_ = "";
    bool isPlaying_ = false;
};

void Mp3Player::play(string_view song, bool suppressChangeEvent)
{}

void Mp3Player::start(bool suppressChangeEvent)
{}

void Mp3Player::stop(bool suppressChangeEvent)
{}

void Mp3Player::add(string_view song, bool suppressChangeEvent)
{}

void Mp3Player::remove(bool suppressChangeEvent)
{}


string Mp3Player::Mp3PlayerChanged()
{
    return "Mp3PlayerChanged";
}

string Mp3Player::Mp3PlayerError()
{
    return "error";
}

const char* Mp3PlayerErrorData::Message(Mp3PlayerErrorData::ErrorConditions ec)
{
    switch(ec)
    {
    case ErrorConditions::Empty: return "Attempting to pop empty Mp3Player";
    case ErrorConditions::TooFewArguments: return "Need at least two Mp3Player elements to swap top";
    default: return "Unknown error";
    };
}

const char* Mp3PlayerErrorData::message() const
{
    return Message(err_);
}

Mp3Player& Mp3Player::Instance()
{
    static Mp3Player instance;
    return instance;
}

Mp3Player::Mp3Player()
{
    registerEvent( Mp3PlayerChanged() );
    registerEvent( Mp3PlayerError() );
}
