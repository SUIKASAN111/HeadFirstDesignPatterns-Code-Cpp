#ifndef SOLD_STATE_H
#define SOLD_STATE_H

#include "state.h"

#include <iostream>
#include <string>

class SoldState : public State {
public:
    SoldState(GumballMachine* _gumballMachine)
        : gumballMachine(_gumballMachine) {}

    void insertQuarter() override
    {
        std::cout << "Please wait, we're already giving you a gumball" << std::endl;
    }

    void ejectQuarter() override
    {
        std::cout << "Sorry, you already turned the crank" << std::endl;
    }

    void turnCrank() override
    {
        std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
    }

    void dispense() override;

    void refill() override {}

    std::string getInfo() override
    {
        return "dispensing a gumball";
    }

private:
    GumballMachine* gumballMachine;
};

#endif // SOLD_STATE_H
