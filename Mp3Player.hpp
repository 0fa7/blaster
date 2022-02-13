#pragma once

#include <filesystem>

class Mp3Player
{
public:
    struct Mp3PlayerState
    {
        bool isPlaying_ = false;
    };
    
    void play(std::filesystem::path path)
    {
        stop();

        // os/lib call to play audio
        state_.isPlaying_ = true;
    }

    void stop()
    {
        if(state_.isPlaying_)
        {
            // os/lib call to stop audio
            state_.isPlaying_ = false;
        }
    }

    void playStateChanged()
    { 
    }

    Mp3PlayerState state_;
    
};