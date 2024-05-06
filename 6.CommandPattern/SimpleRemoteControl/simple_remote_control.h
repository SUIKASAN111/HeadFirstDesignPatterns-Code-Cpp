#ifndef SIMPLE_REMOTE_CONTROL_H
#define SIMPLE_REMOTE_CONTROL_H

#include "command.h"

class SimpleRemoteControl {
public:
    SimpleRemoteControl(){}

    void setCommand(Command* command)
    {
        this->slot = command;
    }

    void buttonWasPressed()
    {
        slot->execute();
    }

private:
    Command* slot;
};

#endif // SIMPLE_REMOTE_CONTROL_H