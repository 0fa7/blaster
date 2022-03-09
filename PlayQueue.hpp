#pragma once

#include <string>
#include <string_view>

#include "Publisher.hpp"

using std::string;
using std::string_view;

class PlayQueue
{
public:
    static PlayQueue& Instance()
    {
        static PlayQueue instance;
        return instance;
    }
    
    void add(string_view song)
    {
        playList_ = song;
    }

    void remove(string_view song)
    {
        if(playList_ == song)
            playList_ = "";
    }

    void clear()
    {}

    static string PlayQueueChanged()
    {
        return "";
    }
    
    static string PlayQueueError()
    {
        return "";
    }

private:
    PlayQueue()
    {}

    ~PlayQueue() = default;
    
    PlayQueue(const PlayQueue&) = delete;
    
    PlayQueue(PlayQueue&&) = delete;
    
    PlayQueue& operator=(const PlayQueue&) = delete;
    
    PlayQueue& operator=(const PlayQueue&&) = delete;

    string playList_;
};