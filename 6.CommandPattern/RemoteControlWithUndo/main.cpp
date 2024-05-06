#include "remote_control_with_undo.h"

int main()
{
    Command* noCommand = new NoCommand();
    RemoteControlWithUndo* remoteControl = new RemoteControlWithUndo(noCommand);

    Light* livingRoomLight = new Light("Living Room");

    LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
    LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);

    remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);
    
    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    remoteControl->info();
    remoteControl->undoButtonWasPushed();
    remoteControl->offButtonWasPushed(0);
    remoteControl->onButtonWasPushed(0);
    remoteControl->info();
    remoteControl->undoButtonWasPushed();

    delete livingRoomLightOn;
    delete livingRoomLightOff;
    delete livingRoomLight;

    CeilingFan* ceilingFan = new CeilingFan("Living Room");

    CeilingFanMediumCommand* ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
    CeilingFanHighCommand* ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
    CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

    remoteControl->setCommand(0, ceilingFanMedium, ceilingFanOff);
    remoteControl->setCommand(1, ceilingFanHigh, ceilingFanOff);

    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    remoteControl->info();
    remoteControl->undoButtonWasPushed();

    remoteControl->onButtonWasPushed(1);
    remoteControl->info();
    remoteControl->undoButtonWasPushed();

    delete ceilingFanMedium;
    delete ceilingFanHigh;
    delete ceilingFanOff;
    delete ceilingFan;
    
    return 0;
}