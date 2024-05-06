#include "simple_remote_control.h"

int main()
{
    SimpleRemoteControl* remote = new SimpleRemoteControl();
    Light* light = new Light();
    GarageDoor* garageDoor = new GarageDoor();
    LightOnCommand* lightOn = new LightOnCommand(light);
    GarageDoorOpenCommand* garageDoorOpen = new GarageDoorOpenCommand(garageDoor);

    remote->setCommand(lightOn);
    remote->buttonWasPressed();
    remote->setCommand(garageDoorOpen);
    remote->buttonWasPressed();

    return 0;
}