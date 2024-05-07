#include "remote_control.h"



int main()
{
    Command* noCommand = new NoCommand();
    RemoteControl* remoteControl = new RemoteControl(noCommand);

    Light* livingRoomLight = new Light("Living Room");
    Light* KitchenLight = new Light("Kitchen");
    CeilingFan* ceilingFan = new CeilingFan("Living Room");
    GarageDoor* garageDoor = new GarageDoor("Garage");
    Stereo* stereo = new Stereo("Living Room");

    LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
    LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);
    LightOnCommand* kitchenLightOn = new LightOnCommand(KitchenLight);
    LightOffCommand* kitchenLightOff = new LightOffCommand(KitchenLight);

    CeilingFanOnCommand* ceilingFanOn = new CeilingFanOnCommand(ceilingFan);
    CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

    GarageDoorUpCommand* garageDoorUp = new GarageDoorUpCommand(garageDoor);
    GarageDoorDownCommand* garageDoorDown = new GarageDoorDownCommand(garageDoor);

    StereoOnWithCDCommand* stereoOnWithCD = new StereoOnWithCDCommand(stereo);
    StereoOffCommand* stereoOff = new StereoOffCommand(stereo);

    remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);
    remoteControl->setCommand(1, kitchenLightOn, kitchenLightOff);
    remoteControl->setCommand(2, ceilingFanOn, ceilingFanOff);
    remoteControl->setCommand(3, stereoOnWithCD, stereoOff);
    
    remoteControl->info();

    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    remoteControl->onButtonWasPushed(1);
    remoteControl->offButtonWasPushed(1);
    remoteControl->onButtonWasPushed(2);
    remoteControl->offButtonWasPushed(2);
    remoteControl->onButtonWasPushed(3);
    remoteControl->offButtonWasPushed(3);


    delete noCommand, remoteControl, livingRoomLight, KitchenLight,
        ceilingFan, garageDoor, livingRoomLightOn, livingRoomLightOff,
        kitchenLightOn, kitchenLightOff, ceilingFanOn, ceilingFanOff,
        garageDoorUp, garageDoorDown, stereoOnWithCD, stereoOff;
    
    return 0;
}