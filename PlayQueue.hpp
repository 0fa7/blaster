#pragma once

#include <string>
#include <string_view>

#include "Publisher.hpp"

class PlayQueue
{
public:
    static PlayQueue& Instance()
    {
        static PlayQueue instance;
        return instance;
    }
    
    void add(std::string_view song)
    {
        playList_ = song;
    }

    void remove(std::string_view song)
    {
        if(playList_ == song)
            playList_ = "";
    }

    void clear()
    {}

    static std::string PlayQueueChanged()
    {
        return "";
    }
    
    static std::string PlayQueueError()
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

    std::string playList_;
};