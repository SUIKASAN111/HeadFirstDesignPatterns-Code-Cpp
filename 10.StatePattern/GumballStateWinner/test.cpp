#include "state.h"
#include "no_quarter_state.h"
#include "has_quarter_state.h"
#include "sold_out_state.h"
#include "sold_state.h"
#include "winner_state.h"
#include "gumball_machine.h"

#include <time.h>

int main()
{
    srand(time(0));

    GumballMachine* gumballMachine = new GumballMachine(5);
    // gumballMachine->init();

    std::cout << gumballMachine->getInfo() << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << gumballMachine->getInfo() << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << gumballMachine->getInfo() << std::endl;
}