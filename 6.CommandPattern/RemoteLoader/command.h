#ifndef COMMAND_H
#define COMMAND_H

#include "appliance.h"

class Command {
public:
    virtual void execute() = 0;
    virtual std::string getType() = 0;
};

class NoCommand : public Command {
public:
    virtual void execute() {}

    virtual std::string getType()
    {
        return std::string("NoCommand");
    }
};

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

    virtual std::string getType()
    {
        return std::string("LightOnCommand");
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

    virtual std::string getType()
    {
        return std::string("LightOffCommand");
    }

private:
    Light* light;
};

class LivingroomLightOnCommand : public Command {
public:
    LivingroomLightOnCommand(Light* light)
    {
        this->light = light;
    }

    virtual void execute()
    {
        light->on();
    }

    virtual std::string getType()
    {
        return std::string("LivingroomLightOnCommand");
    }

private:
    Light* light;
};

class LivingroomLightOffCommand : public Command {
public:
    LivingroomLightOffCommand(Light* light)
    {
        this->light = light;
    }

    virtual void execute()
    {
        light->off();
    }

    virtual std::string getType()
    {
        return std::string("LivingroomLightOffCommand");
    }

private:
    Light* light;
};

class HottubOnCommand : public Command {
public:
    HottubOnCommand(Hottub* hottub)
    {
        this->hottub = hottub;
    }

    virtual void execute()
    {
        hottub->on();
        hottub->heat();
        hottub->bubblesOn();
    }

    virtual std::string getType()
    {
        return std::string("HottubOnCommand");
    }

private:
    Hottub* hottub;    
};

class HottubOffCommand : public Command {
public:
    HottubOffCommand(Hottub* hottub)
    {
        this->hottub = hottub;
    }

    virtual void execute()
    {
        hottub->cool();
        hottub->off();
    }

    virtual std::string getType()
    {
        return std::string("HottubOffCommand");
    }

private:
    Hottub* hottub;    
};

class GarageDoorUpCommand : public Command {
public:
    GarageDoorUpCommand(GarageDoor* garageDoor)
    {
        this->garageDoor = garageDoor;
    }

    virtual void execute()
    {
        garageDoor->up();
    }

    virtual std::string getType()
    {
        return std::string("GarageDoorUpCommand");
    }

private:
    GarageDoor* garageDoor;
};

class GarageDoorDownCommand : public Command {
public:
    GarageDoorDownCommand(GarageDoor* garageDoor)
    {
        this->garageDoor = garageDoor;
    }

    virtual void execute()
    {
        garageDoor->down();
    }

    virtual std::string getType()
    {
        return std::string("GarageDoorDownCommand");
    }

private:
    GarageDoor* garageDoor;
};

class CeilingFanOnCommand : public Command {
public:
    CeilingFanOnCommand(CeilingFan* ceilingFan)
    {
        this->ceilingFan = ceilingFan;
    }

    virtual void execute()
    {
        ceilingFan->high();
    }

    virtual std::string getType()
    {
        return std::string("CeilingFanOnCommand");
    }

private:
    CeilingFan* ceilingFan;
};

class CeilingFanOffCommand : public Command {
public:
    CeilingFanOffCommand(CeilingFan* ceilingFan)
    {
        this->ceilingFan = ceilingFan;
    }

    virtual void execute()
    {
        ceilingFan->off();
    }

    virtual std::string getType()
    {
        return std::string("CeilingFanOffCommand");
    }

private:
    CeilingFan* ceilingFan;
};

class StereoOnWithCDCommand : public Command {
public:
    StereoOnWithCDCommand(Stereo* stereo)
    {
        this->stereo = stereo;
    }

    virtual void execute()
    {
        stereo->on();
        stereo->setCD();
        stereo->setVolume(11);
    }

    virtual std::string getType()
    {
        return std::string("StereoOnWithCDCommand");
    }

private:
    Stereo* stereo;
};

class StereoOffCommand : public Command {
public:
    StereoOffCommand(Stereo* stereo)
    {
        this->stereo = stereo;
    }

    virtual void execute()
    {
        stereo->off();
    }

    virtual std::string getType()
    {
        return std::string("StereoOffCommand");
    }

private:
    Stereo* stereo;
};

#endif // COMMAND_H