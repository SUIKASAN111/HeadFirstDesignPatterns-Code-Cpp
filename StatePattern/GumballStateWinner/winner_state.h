#ifndef WINNER_STATE_H
#define WINNER_STATE_H

#include "state.h"

#include <iostream>
#include <string>

class WinnerState : public State {
public:
    WinnerState(GumballMachine* _gumballMachine)
        : gumballMachine(_gumballMachine) {}

    void insertQuarter() override
    {
        std::cout << "Please wait, we're already giving you a Gumball" << std::endl;
    }

    void ejectQuarter() override
    {
        std::cout << "Please wait, we're already giving you a Gumball" << std::endl;
    }

    void turnCrank() override
    {
        std::cout << "Turning again doesn't get you another gumball!" << std::endl;
    }

    void dispense() override;

    void refill() override {}

    std::string getInfo() override
    {
        return "despensing two gumballs for your quarter, because YOU'RE A WINNER!";
    }

private:
    GumballMachine* gumballMachine;
};

#endif // WINNER_STATE_H
