#ifndef PIZZA_STORE_H
#define PIZZA_STORE_H

#include <iostream>
#include <string>

#include "pizza.h"

class PizzaStore {
public:
    Pizza* orderPizza(const std::string& type)
    {
        Pizza* pizza = createPizza(type);
        std::cout << "--- Making a " << pizza->getName() << " ---" << std::endl;
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

    virtual Pizza* createPizza(const std::string& item) = 0;
};

// concrete pizza store
// Chicago store
class ChicagoPizzaStore : public PizzaStore {
    virtual Pizza* createPizza(const std::string& item)
    {
        if (item == "cheese")
            return new ChicagoStyleCheesePizza();
        else if (item == "veggie")
            return new ChicagoStyleVeggiePizza();
        else if (item == "clam")
            return new ChicagoStyleClamPizza();
        else if (item == "pepperoni")
            return new ChicagoStylePepperoniPizza();
        else
            return nullptr;
    }
};

// NY store
class NYPizzaStore : public PizzaStore {
    virtual Pizza* createPizza(const std::string& item)
    {
        if (item == "cheese")
            return new NYStyleCheesePizza();
        else if (item == "veggie")
            return new NYStyleVeggiePizza();
        else if (item == "clam")
            return new NYStyleClamPizza();
        else if (item == "pepperoni")
            return new NYStylePepperoniPizza();
        else
            return nullptr;
    }
};

#endif // PIZZA_STORE_H