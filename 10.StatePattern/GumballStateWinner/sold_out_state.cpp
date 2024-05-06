#include "sold_out_state.h"
#include "gumball_machine.h"

void SoldOutState::refill()
{
    gumballMachine->setState(gumballMachine->getNoQuarterState());
}
