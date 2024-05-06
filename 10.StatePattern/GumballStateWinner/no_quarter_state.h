#ifndef NO_QUARTER_STATE_H
#define NO_QUARTER_STATE_H

#include "state.h"

#include <iostream>
#include <string>

class NoQuarterState : public State {
public:
    NoQuarterState(GumballMachine* _gumballMachine)
        : gumballMachine(_gumballMachine) {}

    void insertQuarter() override;

    void ejectQuarter() override
    {
        std::cout << "You haven't inserted a quarter" << std::endl;
    }

    void turnCrank() override
    {
        std::cout << "You turned, but there's no quarter" << std::endl;
    }

    void dispense() override
    {
        std::cout << "You need to pay first" << std::endl;
    }

    void refill() override {}

    std::string getInfo() override
    {
        return "waiting for quarter";
    }

private:
    GumballMachine* gumballMachine;
};

#endif // NO_QUARTER_STATE_H
