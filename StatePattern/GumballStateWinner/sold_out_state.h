#ifndef SOLD_OUT_STATE_H
#define SOLD_OUT_STATE_H

#include "state.h"

#include <iostream>
#include <string>

class SoldOutState : public State {
public:
    SoldOutState(GumballMachine* _gumballMachine)
        : gumballMachine(_gumballMachine) {}

    void insertQuarter() override
    {
        std::cout << "You can't insert a quarter, the machine is sold out" << std::endl;
    }

    void ejectQuarter() override
    {
        std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl;
    }

    void turnCrank() override
    {
        std::cout << "You turned, but there are no gumballs" << std::endl;
    }

    void dispense() override
    {
        std::cout << "No gumball dispensed" << std::endl;
    }

    void refill() override;

    std::string getInfo() override
    {
        return "sold out";
    }

private:
    GumballMachine* gumballMachine;
};

#endif // SOLD_OUT_STATE_H
