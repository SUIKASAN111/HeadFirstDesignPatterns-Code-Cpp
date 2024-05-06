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
        level = 100;
        std::cout << location << " light is on" << std::endl;
    }

    void off()
    {
        level = 0;
        std::cout << location << " light is off" << std::endl;
    }

    void dim(int level)
    {
        this->level = level;
        if (level == 0)
        {
            this->off();
        }
        else
        {
            std::cout << "Light is dimmed to " << level << "%" << std::endl;
        }
    }

    int getLevel()
    {
        return level;
    }

private:
    std::string location;
    int level;
};


class CeilingFan {
public:
    enum class Speed {
        OFF = 0, LOW, MEDIUM, HIGH
    };

    CeilingFan(std::string location)
    {
        this->location = location;
        speed = Speed::OFF;
    }

    void high()
    {
        speed = Speed::HIGH;
        std::cout << location << " ceiling fan is on high" << std::endl;
    }

    void medium()
    {
        speed = Speed::MEDIUM;
        std::cout << location << " ceiling fan is on medium" << std::endl;
    }

    void low()
    {
        speed = Speed::LOW;
        std::cout << location << " ceiling fan is on low" << std::endl;
    }

    void off()
    {
        speed = Speed::OFF;
        std::cout << location << " ceiling fan is off" << std::endl;
    }

    Speed getSpeed()
    {
        return speed;
    }

private:
    std::string location;
    Speed speed;
};

#endif // APPLIANCE_H