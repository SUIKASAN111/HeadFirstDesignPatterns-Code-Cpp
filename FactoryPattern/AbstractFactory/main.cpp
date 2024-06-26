#include <iostream>

#include "ingredients.h"
#include "pizza.h"
#include "pizza_ingredient_factory.h"
#include "pizza_store.h"

int main()
{
    PizzaStore* nyStore = new NYPizzaStore();
    PizzaStore* chicagoStore = new ChicagoPizzaStore();

    Pizza* pizza = nyStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
    std::cout << pizza->getInfo() << std::endl;
    std::cout << std::endl;
    delete pizza;

    pizza = chicagoStore->orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;
    std::cout << pizza->getInfo() << std::endl;
    std::cout << std::endl;
    delete pizza;

    pizza = nyStore->orderPizza("clam");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
    std::cout << std::endl;
    delete pizza;

    pizza = chicagoStore->orderPizza("clam");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;
    std::cout << std::endl;
    delete pizza;

    pizza = nyStore->orderPizza("pepperoni");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
    std::cout << std::endl;
    delete pizza;

    pizza = chicagoStore->orderPizza("pepperoni");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;
    std::cout << std::endl;
    delete pizza;

    pizza = nyStore->orderPizza("veggie");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
    std::cout << std::endl;
    delete pizza;

    pizza = chicagoStore->orderPizza("veggie");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;
    std::cout << std::endl;
    delete pizza;

    delete nyStore;
    delete chicagoStore;

    return 0;
}