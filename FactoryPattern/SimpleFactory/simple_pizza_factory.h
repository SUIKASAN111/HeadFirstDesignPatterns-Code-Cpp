#ifndef SIMPLE_PIZZA_FACTORY_H
#define SIMPLE_PIZZA_FACTORY_H

#include <string>

#include "pizza.h"

class SimplePizzaFactory {
public:
    Pizza* createPizza(std::string type)
    {
        Pizza* pizza = nullptr;

        if (type == "cheese")
            pizza = new CheesePizza();
        else if (type == "pepperoni")
            pizza = new PepperoniPizza();
        else if (type == "clam")
            pizza = new ClamPizza();
        else if (type == "veggie")
            pizza = new VeggiePizza();

        return pizza;
    }

};

#endif // SIMPLE_PIZZA_FACTORY_H