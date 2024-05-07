#include "duck.h"
#include "turkey.h"
#include "duck_adapter.h"
#include "turkey_adapter.h"

static void testDuck(Duck*);

int main()
{
    std::cout << "-----Duck Test-----" << std::endl;
    
    Duck* duck = new MallardDuck();

    Turkey* turkey = new WildTurkey();
    Duck* turkeyAdapter = new TurkeyAdapter(turkey);

    std::cout << "The Turkey says..." << std::endl;
    turkey->gobble();
    turkey->fly();

    std::cout << "\nThe Duck says..." << std::endl;
    testDuck(duck);

    std::cout << "\nThe Turkey/Adapter says..." << std::endl;
    testDuck(turkeyAdapter);

    
    std::cout << "-----Turkey Test-----" << std::endl;

    Turkey* duckAdapter = new DuckAdapter(duck);

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "The DuckAdapter says..." << std::endl;
        duckAdapter->gobble();
        duckAdapter->fly();
    }

    delete duck, turkey, turkeyAdapter, duckAdapter;

    return 0;
}

void testDuck(Duck* duck)
{
    duck->quack();
    duck->fly();
}