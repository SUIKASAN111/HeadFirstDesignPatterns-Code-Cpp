#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <iomanip>
#include <vector>

#include "command.h"

class RemoteControl {
public:
    RemoteControl(Command* command)
    {
        onCommands.resize(7);
        offCommands.resize(7);

        for (int i = 0; i < 7; ++i)
        {
            onCommands[i] = command;
            offCommands[i] = command;
        }
    }

    void setCommand(int slot, Command* onCommand, Command* offCommand)
    {
        onCommands[slot] = onCommand;
        offCommands[slot] = offCommand;
    }

    void onButtonWasPushed(int slot)
    {
        onCommands[slot]->execute();
    }

    void offButtonWasPushed(int slot)
    {
        offCommands[slot]->execute();
    }

    void info()
    {
        std::cout << "----------------- Remote Control ------------------" << std::endl;
        for (int i = 0; i < onCommands.size(); ++i)
        {
            std::cout << "[slot " << i << "] "
                << std::left << std::setw(24) << onCommands[i]->getType()
                << offCommands[i]->getType() << std::endl;
        }
        std::cout << "---------------------------------------------------" << std::endl;
    }
    
private:
    std::vector<Command*> onCommands;
    std::vector<Command*> offCommands;
};

#endif // REMOTE_CONTROL_H