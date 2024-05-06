#ifndef PIZZA_STORE_H
#define PIZZA_STORE_H

#include "simple_pizza_factory.h"
#include "pizza.h"

class PizzaStore {
public:
    PizzaStore(SimplePizzaFactory* factory)
        : factory(factory)
    {}

    Pizza* orderPizza(std::string type)
    {
        Pizza* pizza;

        pizza = factory->createPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

private:
    SimplePizzaFactory* factory;
};

#endif // PIZZA_STORE_H