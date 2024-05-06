#ifndef HAS_QUARTER_STATE_H
#define HAS_QUARTER_STATE_H

#include "state.h"

#include <iostream>
#include <string>

class HasQuarterState : public State {
public:
    HasQuarterState(GumballMachine* _gumballMachine)
        : gumballMachine(_gumballMachine) {}

    void insertQuarter() override
    {
        std::cout << "You can't insert another quarter" << std::endl;
    }

    void ejectQuarter() override;

    void turnCrank() override;

    void dispense() override
    {
        std::cout << "No gumball dispensed" << std::endl;
    }

    void refill() override {}

    std::string getInfo() override
    {
        return "waiting for turn of crank";
    }

private:
    GumballMachine* gumballMachine;
};

#endif // HAS_QUARTER_STATE_H
