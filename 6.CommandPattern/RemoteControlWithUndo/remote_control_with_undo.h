#ifndef REMOTE_CONTROL_WITH_UNDO_H
#define REMOTE_CONTROL_WITH_UNDO_H

#include <vector>
#include <iomanip>

#include "command.h"

class RemoteControlWithUndo {
public:
    RemoteControlWithUndo(Command* command)
    {
        onCommands.resize(7);
        offCommands.resize(7);

        for (int i = 0; i < 7; ++i)
        {
            onCommands[i] = command;
            offCommands[i] = command;
        }
        undoCommand = command;
    }

    void setCommand(int slot, Command* onCommand, Command* offCommand)
    {
        onCommands[slot] = onCommand;
        offCommands[slot] = offCommand;
    }

    void onButtonWasPushed(int slot)
    {
        onCommands[slot]->execute();
        undoCommand = onCommands[slot];
    }
    
    void offButtonWasPushed(int slot)
    {
        offCommands[slot]->execute();
        undoCommand = offCommands[slot];
    }

    void undoButtonWasPushed()
    {
        undoCommand->undo();
    }

    void info()
    {
        std::cout << "----------------- Remote Control ------------------" << std::endl;
        for (int i = 0; i < onCommands.size(); ++i)
        {
            std::cout << "[slot " << i << "] "
                << std::left << std::setw(24) << onCommands[i]->getCommandType()
                << offCommands[i]->getCommandType() << std::endl;
        }
        std::cout << "[ undo ] " << undoCommand->getCommandType() << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
    }

private:
    std::vector<Command*> onCommands;
    std::vector<Command*> offCommands;
    Command* undoCommand;
};

#endif // REMOTE_CONTROL_WITH_UNDO_H