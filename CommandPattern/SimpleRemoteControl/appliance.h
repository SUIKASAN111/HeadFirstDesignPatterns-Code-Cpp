#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <iostream>

class Light {
public:
    Light() {}

    void on()
    {
        std::cout << "Light is on" << std::endl;
    }

    void off()
    {
        std::cout << "Light is off" << std::endl;
    }
};

class GarageDoor {
public:
    GarageDoor(){}

    void up()
    {
        std::cout << "Garage Door is Open" << std::endl;
    }

    void down()
    {
        std::cout << "Garage Door is Closed" << std::endl;
    }

    void stop()
    {
        std::cout << "Garage Door is Stopped" << std::endl;
    }

    void LightOn()
    {
        std::cout << "Garage light is on" << std::endl;
    }

    void LightOff()
    {
        std::cout << "Garage light is off" << std::endl;
    }
};

#endif // APPLIANCE_H