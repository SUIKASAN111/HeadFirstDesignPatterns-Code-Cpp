#include <iostream>

#include "pizza.h"
#include "pizza_store.h"
#include "simple_pizza_factory.h"

int main()
{
    SimplePizzaFactory* factory = new SimplePizzaFactory();
    PizzaStore* store = new PizzaStore(factory);

    Pizza* pizza = store->orderPizza("cheese");
    std::cout << "We ordered a " << pizza->getName() << std::endl;
    std::cout << pizza->getInfo() << std::endl;

    pizza = store->orderPizza("veggie");
    std::cout << "We ordered a " << pizza->getName() << std::endl;
    std::cout << pizza->getInfo() << std::endl;
    
    return 0;
}