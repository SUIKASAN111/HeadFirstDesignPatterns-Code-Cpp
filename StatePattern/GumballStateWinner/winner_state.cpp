#include "winner_state.h"
#include "gumball_machine.h"

void WinnerState::dispense()
{
    gumballMachine->releaseBall();
    if (gumballMachine->getCount() == 0)
    {
        gumballMachine->setState(gumballMachine->getSoldOutState());
    }
    else
    {
        gumballMachine->releaseBall();
        std::cout << "YOU'RE A WINNER! You got two gumballs for your quarter" << std::endl;
        if (gumballMachine->getCount() > 0)
        {
            gumballMachine->setState(gumballMachine->getNoQuarterState());
        }
        else
        {
            std::cout << "Oops, out of gumballs!" << std::endl;
            gumballMachine->setState(gumballMachine->getSoldOutState());
        }
    }
}
