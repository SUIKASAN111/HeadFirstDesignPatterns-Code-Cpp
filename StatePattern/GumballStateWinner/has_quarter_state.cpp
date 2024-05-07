#include "has_quarter_state.h"
#include "gumball_machine.h"

void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned" << std::endl;
    gumballMachine->setState(gumballMachine->getNoQuarterState());
}

void HasQuarterState::turnCrank()
{
    std::cout << "You turned..." << std::endl;
    int winner = rand();
    if (winner % 10 == 0 && gumballMachine->getCount() > 1)
    {
        gumballMachine->setState(gumballMachine->getWinnerState());
    }
    else
    {
        gumballMachine->setState(gumballMachine->getSoldState());
    }
}