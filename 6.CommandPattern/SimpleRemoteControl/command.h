#ifndef COMMAND_H
#define COMMAND_H

#include "appliance.h"

class Command {
public:
    virtual void execute() = 0;
};

// Concrete Command
class LightOnCommand : public Command {
public:
    LightOnCommand(Light* light)
    {
        this->light = light;
    }

    virtual void execute()
    {
        light->on();
    }

private:
    Light* light;
};

class LightOffCommand : public Command {
public:
    LightOffCommand(Light* light)
    {
        this->light = light;
    }

    virtual void execute()
    {
        light->off();
    }

private:
    Light* light;
};

class GarageDoorOpenCommand : public Command {
public:
    GarageDoorOpenCommand(GarageDoor* garageDoor)
    {
        this->garageDoor = garageDoor;
    }

    void execute()
    {
        garageDoor->up();
    }

private:
    GarageDoor* garageDoor;
};

#endif // COMMAND_H