#include "no_quarter_state.h"
#include "gumball_machine.h"

void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted a quarter" << std::endl;
    gumballMachine->setState(gumballMachine->getHasQuarterState());
}