#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <iostream>
#include <string>

class Light {
public:
    Light(std::string location)
    {
        this->location = location;
    }

    void on()
    {
        std::cout << location << " light is on" << std::endl;
    }

    void off()
    {
        std::cout << location << " light is off" << std::endl;
    }

private:
    std::string location;
};

class GarageDoor {
public:
    GarageDoor(std::string location)
    {
        this->location = location;
    }

    void up()
    {
        std::cout << location << "garage door is Up" << std::endl;
    }

    void down()
    {
        std::cout << location << "garage door is Down" << std::endl;
    }

    void stop()
    {
        std::cout << location << "garage door is Stopped" << std::endl;
    }

    void LightOn()
    {
        std::cout << location << "garage light is on" << std::endl;
    }

    void LightOff()
    {
        std::cout << location << "garage light is off" << std::endl;
    }

private:
    std::string location;
};

class CeilingFan {
public:
    enum class Level {
        OFF = 0, LOW, MEDIUM, HIGH
    };

    CeilingFan(std::string location)
    {
        this->location = location;
    }

    void high()
    {
        level = Level::HIGH;
        std::cout << location << " ceiling fan is on high" << std::endl;
    }

    void medium()
    {
        level = Level::MEDIUM;
        std::cout << location << " ceiling fan is on medium" << std::endl;
    }

    void low()
    {
        level = Level::LOW;
        std::cout << location << " ceiling fan is on low" << std::endl;
    }

    void off()
    {
        level = Level::OFF;
        std::cout << location << " ceiling fan is off" << std::endl;
    }

    Level getSpeedLevel()
    {
        return level;
    }

private:
    std::string location;
    Level level;
};

class Hottub {
public:
    Hottub(){}

    void on()
    {
        isOn = true;
    }

    void off()
    {
        isOn = false;
    }

    void bubblesOn()
    {
        if (isOn)
        {
            std::cout << "Hottub is bubbling!" << std::endl;
        }
    }

    void bubblesOff()
    {
        if (isOn)
        {
            std::cout << "Hottub is not bubbling!" << std::endl;
        }
    }

    void jetsOn()
    {
        if (isOn)
        {
            std::cout << "Hottub jets are on" << std::endl;
        }
    }

    void jetsOff()
    {
        if (isOn)
        {
            std::cout << "Hottub jets are off" << std::endl;
        }
    }

    void setTemperature(int temperature)
    {
        this->temperature = temperature;
    }

    void heat()
    {
        temperature = 105;
        std::cout << "Hottub is heating to a steaming 105 degrees" << std::endl;
    }

    void cool()
    {
        temperature = 98;
        std::cout << "Hottub is cooling to a 98 degrees" << std::endl;
    }

private:
    bool isOn;
    int temperature;
};

class Stereo {
public:
    Stereo(std::string location)
    {
        this->location = location;
    }

    void on()
    {
        std::cout << location << " stereo is on" << std::endl;
    }

    void off()
    {
        std::cout << location << " stereo is off" << std::endl;
    }

    void setCD()
    {
        std::cout << location << " stereo is set for CD input" << std::endl;
    }

    void setDVD()
    {
        std::cout << location << " stereo is set for DVD input" << std::endl;
    }

    void setRadio()
    {
        std::cout << location << " stereo is set for Radio" << std::endl;
    }

    void setVolume(int volume)
    {
        std::cout << location << " stereo volume set to " << volume << std::endl;
    }

private:
    std::string location;
};

class TV {
public:
    TV(std::string location)
    {
        this->location = location;
    }

    void on()
    {
        std::cout << "TV is on" << std::endl;
    }

    void off()
    {
        std::cout << "TV is off" << std::endl;
    }

    void setInputChannel()
    {
        this->channel = 3;
        std::cout << "Channel is set for VCR" << std::endl;
    }

private:
    std::string location;
    int channel;
};

#endif // APPLIANCE_H