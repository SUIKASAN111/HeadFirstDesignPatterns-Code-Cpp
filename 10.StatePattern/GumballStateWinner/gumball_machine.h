#ifndef GUMBALL_MACHINE_H
#define GUMBALL_MACHINE_H

#include "state.h"
#include "no_quarter_state.h"
#include "has_quarter_state.h"
#include "sold_out_state.h"
#include "sold_state.h"
#include "winner_state.h"

#include <iostream>

class GumballMachine {
public:
    GumballMachine(int numberGumballs)
        : count(numberGumballs)
    {
        soldOutState = new SoldOutState(this);
        noQuarterState = new NoQuarterState(this);
        hasQuarterState = new HasQuarterState(this);
        soldState = new SoldState(this);
        winnerState = new WinnerState(this);

        if (numberGumballs > 0)
            state = noQuarterState;
    }

    void insertQuarter()
    {
        state->insertQuarter();
    }

    void ejectQuarter()
    {
        state->ejectQuarter();
    }

    void turnCrank()
    {
        state->turnCrank();
        state->dispense();
    }

    void setState(State* _state)
    {
        this->state = _state;
    }

    void releaseBall(){
        std::cout << "A gumball comes rolling out the slot..." << std::endl;
        if (count > 0)
            --count;
    }

    int getCount()
    {
        return count;
    }

    void refill(int _count)
    {
        this->count = _count;
        std::cout << "The gumball machine was just refilled; its new count is: "
            << this->count << std::endl;
        state->refill();
    }

    State* getState()
    {
        return state;
    }

    State* getSoldOutState()
    {
        return soldOutState;
    }

    State* getNoQuarterState()
    {
        return noQuarterState;
    }

    State* getHasQuarterState()
    {
        return hasQuarterState;
    }

    State* getSoldState()
    {
        return soldState;
    }

    State* getWinnerState()
    {
        return winnerState;
    }

    std::string getInfo()
    {
        std::string result;
        result += "\nMighty Gumball, Inc.\n";
        result += "CPP-enabled Standing Gumball Model #2004\n";
        result += "Inventory: " + std::to_string(count) + " gumball";
        if (count != 1)
        {
            result += "s";
        }
        result += "\nMachine is " + state->getInfo() + "\n";
        return result;
    }

private:
    State* soldOutState;
    State* noQuarterState;
    State* hasQuarterState;
    State* soldState;
    State* winnerState;

    State* state;
    int count = 0;
};

#endif // GUMBALL_MACHINE_H
