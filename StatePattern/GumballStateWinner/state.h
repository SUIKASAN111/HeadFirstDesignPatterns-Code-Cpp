#ifndef STATE_H
#define STATE_H


#include <iostream>
#include <string>

class GumballMachine;

class State {
public:
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;

    virtual void refill() = 0;

    virtual std::string getInfo() = 0;
};

#endif // STATE_H
