#include "sold_state.h"
#include "gumball_machine.h"

void SoldState::dispense()
{
    gumballMachine->releaseBall();
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
