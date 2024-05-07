#ifndef DEVICES_H
#define DEVICES_H

#include <string>
#include <iostream>

class Amplifier;
class Tuner;
class StreamingPlayer;
class CdPlayer;
class Projector;
class TheaterLights;
class Screen;
class PopcornPopper;

class Tuner {
public:
    Tuner(std::string description, Amplifier* amplifier)
        : description(description), amplifier(amplifier) {}

    void on()
    {
        std::cout << description << " on" << std::endl;
    }

    void off()
    {
        std::cout << description << " off" << std::endl;
    }

    void setFrequency(double frequency)
    {
        std::cout << description << " setting frequency to" << frequency << std::endl;
        this->frequency = frequency;
    }

    void setAm()
    {
        std::cout << description << " setting AM mode" << std::endl;
    }

    void setFm()
    {
        std::cout << description << " setting FM mode" << std::endl;
    }

    std::string info()
    {
        return description;
    }

private:
    std::string description;
    Amplifier* amplifier;
    double frequency;
};

class StreamingPlayer {
public:
    StreamingPlayer(std::string description, Amplifier* amplifier)
        : description(description), amplifier(amplifier) {}
    
    void on()
    {
        std::cout << description << " on" << std::endl;
    }

    void off()
    {
        std::cout << description << " off" << std::endl;
    }

    void play(std::string movie)
    {
        this->movie = movie;
        currentChapter = 0;
        std::cout << description << " playing \"" << movie << "\"" << std::endl;
    }

    void play(int chapter)
    {
        if (movie.empty())
        {
            std::cout << " can't play chapter " << chapter << " no movie selected" << std::endl;
        }
        else
        {
            currentChapter = chapter;
            std::cout << description << " playing chapter " << currentChapter << " of \"" << movie << "\"" << std::endl;
        }
    }

    void stop()
    {
        currentChapter = 0;
        std::cout << description << " stopped \"" << movie << "\"" << std::endl;
    }

    void pause()
    {
        std::cout << description << " paused \"" << movie << "\"" << std::endl;
    }

    void setTwoChannelAudio()
    {
        std::cout << description << " set two channel audio" << std::endl;
    }

    void setSurroundAudio()
    {
        std::cout << description << " set surround audio" << std::endl;
    }

    std::string info()
    {
        return description;
    }

    operator std::string()
    {
        return description;
    }

private:
    std::string description;
    int currentChapter;
    Amplifier* amplifier;
    std::string movie;
};

class Amplifier {
public:
    Amplifier(std::string description) : description(description) {}

    void on()
    {
        std::cout << description << " on" << std::endl;
    }

    void off()
    {
        std::cout << description << " off" << std::endl;
    }

    void setStereoSound()
    {
        std::cout << description << " stereo mode on" << std::endl;
    }

    void setSurroundSound()
    {
        std::cout << description << " surround sound on (5 speakers, 1 subwoofer)" << std::endl;
    }

    void setVolume(int level)
    {
        std::cout << description << " setting volume to " << level << std::endl;
    }

    void setTuner(Tuner* tuner)
    {
        std::cout << description << " setting tuner to" << tuner->info() << std::endl;
        this->tuner = tuner;
    }

    void setStreamingPlayer(StreamingPlayer* player)
    {
        std::cout << description << " setting Streaming player to " << player->info() << std::endl;
        // std::cout << description << " setting Streaming player to " << player << std::endl;
        this->player = player;
    }

    std::string info()
    {
        return description;
    }
    
private:
    std::string description;
    Tuner* tuner;
    StreamingPlayer* player;
};

class CdPlayer {
public:
    CdPlayer(std::string description, Amplifier* amplifier)
        : description(description), amplifier(amplifier) {}

    void on()
    {
        std::cout << description << " on" << std::endl;
    }

    void off()
    {
        std::cout << description << " off" << std::endl;
    }

    void eject()
    {
        title = "";
        std::cout << description << " eject" << std::endl;
    }

    void play(std::string title)
    {
        this->title = title;
        currentTrack = 0;
        std::cout << description << " playing \"" << title << "\"" << std::endl;
    }

    void play(int track)
    {
        if (title.empty())
        {
            std::cout << description << " can't play track " << currentTrack << ", no cd inserted" << std::endl;
        }
        else
        {
            currentTrack = track;
            std::cout << description << " playing track " << currentTrack;
        }
    }

    void stop()
    {
        currentTrack = 0;
        std::cout << description << " stopped" << std::endl;
    }

    void pause()
    {
        std::cout << description << " paused \"" << title << "\"" << std::endl;
    }

    std::string info()
    {
        return description;
    }

private:
    std::string description;
    int currentTrack;
    Amplifier* amplifier;
    std::string title;
};

class Projector {
public:
    Projector(std::string description, StreamingPlayer* player)
        : description(description), player(player) {}

    void on()
    {
        std::cout << description << " on" << std::endl;
    }

    void off()
    {
        std::cout << description << " off" << std::endl;
    }

    void wideScreenMode()
    {
        std::cout << description << " in widescreen mode (16x9 aspect ration)" << std::endl;
    }

    void tvMode()
    {
        std::cout << description << " in tv mode (4x3 aspect ration)" << std::endl;
    }

    std::string info()
    {
        return description;
    }

private:
    std::string description;
    StreamingPlayer* player;
};

class TheaterLights {
public:
    TheaterLights(std::string description) : description(description) {}
    
    void on()
    {
        std::cout << description << " on" << std::endl;
    }

    void off()
    {
        std::cout << description << " off" << std::endl;
    }

    void dim(int level)
    {
        std::cout << description << " dimming to " << level << "%" << std::endl;
    }

    std::string info()
    {
        return description;
    }

private:
    std::string description;
};

class Screen {
public:
    Screen(std::string description) : description(description) {}

    void up()
    {
        std::cout << description << " going up" << std::endl;
    }

    void down()
    {
        std::cout << description << " going down" << std::endl;
    }
    
    std::string info()
    {
        return description;
    }

private:
    std::string description;
};

class PopcornPopper {
public:
    PopcornPopper(std::string description) : description(description) {}
    
    void on()
    {
        std::cout << description << " on" << std::endl;
    }

    void off()
    {
        std::cout << description << " off" << std::endl;
    }

    void pop()
    {
        std::cout << description << " popping popcorn!" << std::endl;
    }

    std::string info()
    {
        return description;
    }

private:
    std::string description;
};

#endif // DEVICES_H