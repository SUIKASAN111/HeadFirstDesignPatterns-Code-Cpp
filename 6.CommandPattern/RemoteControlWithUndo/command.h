#ifndef COMMAND_H
#define COMMAND_H

#include "appliance.h"

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::string getCommandType() = 0;
};

class NoCommand : public Command {
public:
    virtual void execute() {}

    virtual void undo() {}

    virtual std::string getCommandType()
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
        level = light->getLevel();
        light->on();
    }

    virtual void undo()
    {
        light->dim(level);
    }
    
    virtual std::string getCommandType()
    {
        return std::string("LightOnCommand");
    }

private:
    Light* light;
    int level;
};

class LightOffCommand : public Command {
public:
    LightOffCommand(Light* light)
    {
        this->light = light;
    }

    virtual void execute()
    {
        level = light->getLevel();
        light->off();
    }

    virtual void undo()
    {
        light->dim(level);
    }

    virtual std::string getCommandType()
    {
        return std::string("LightOffCommand");
    }

private:
    Light* light;
    int level;
};

class DimmerLightOnCommand : public Command {
public:
    DimmerLightOnCommand(Light* light)
    {
        this->light = light;
    }

    virtual void execute()
    {
        prevLevel = light->getLevel();
        light->dim(75);
    }

    virtual void undo()
    {
        light->dim(prevLevel);
    }
    
    virtual std::string getCommandType()
    {
        return std::string("DimmerLightOnCommand");
    }

private:
    Light* light;
    int prevLevel;
};

class DimmerLightOffCommand : public Command {
public:
    DimmerLightOffCommand(Light* light)
    {
        this->light = light;
        prevLevel = 100;
    }

    virtual void execute()
    {
        prevLevel = light->getLevel();
        light->off();
    }

    virtual void undo()
    {
        light->dim(prevLevel);
    }
    
    virtual std::string getCommandType()
    {
        return std::string("DimmerLightOffCommand");
    }

private:
    Light* light;
    int prevLevel;
};

class CeilingFanCommand : public Command {
public:
    CeilingFanCommand(CeilingFan* ceilingFan)
    {
        this->ceilingFan = ceilingFan;
    }

    virtual void undo() final
    {
        if (prevSpeed == CeilingFan::Speed::HIGH)
        {
            ceilingFan->high();
        }
        else if (prevSpeed == CeilingFan::Speed::MEDIUM)
        {
            ceilingFan->medium();
        }
        else if (prevSpeed == CeilingFan::Speed::LOW)
        {
            ceilingFan->low();
        }
        else if (prevSpeed == CeilingFan::Speed::OFF)
        {
            ceilingFan->off();
        }
    }

    CeilingFan* ceilingFan;
    CeilingFan::Speed prevSpeed;
};

class CeilingFanHighCommand : public CeilingFanCommand {
public:
    CeilingFanHighCommand(CeilingFan* ceilingFan)
        : CeilingFanCommand(ceilingFan) {}

    virtual void execute()
    {
        prevSpeed = ceilingFan->getSpeed();
        ceilingFan->high();
    }
    
    virtual std::string getCommandType()
    {
        return std::string("CeilingFanHighCommand");
    }
};

class CeilingFanMediumCommand : public CeilingFanCommand {
public:
    CeilingFanMediumCommand(CeilingFan* ceilingFan)
        : CeilingFanCommand(ceilingFan) {}
    
    virtual void execute()
    {
        prevSpeed = ceilingFan->getSpeed();
        ceilingFan->medium();
    }

    virtual std::string getCommandType()
    {
        return std::string("CeilingFanHighCommand");
    }
};

class CeilingFanLowCommand : public CeilingFanCommand {
public:
    CeilingFanLowCommand(CeilingFan* ceilingFan)
        : CeilingFanCommand(ceilingFan) {}
    
    virtual void execute()
    {
        prevSpeed = ceilingFan->getSpeed();
        ceilingFan->low();
    }

    virtual std::string getCommandType()
    {
        return std::string("CeilingFanHighCommand");
    }
};

class CeilingFanOffCommand : public CeilingFanCommand {
public:
    CeilingFanOffCommand(CeilingFan* ceilingFan)
        : CeilingFanCommand(ceilingFan) {}
    
    virtual void execute()
    {
        prevSpeed = ceilingFan->getSpeed();
        ceilingFan->off();
    }

    virtual std::string getCommandType()
    {
        return std::string("CeilingFanOffCommand");
    }
};

#endif // COMMAND_H