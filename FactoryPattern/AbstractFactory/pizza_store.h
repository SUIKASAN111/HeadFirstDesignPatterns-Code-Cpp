#ifndef PIZZA_STORE_H
#define PIZZA_STORE_H

#include "pizza.h"

class PizzaStore {
public:
    virtual Pizza* createPizza(std::string item) = 0;

    Pizza* orderPizza(std::string type)
    {
        Pizza* pizza = createPizza(type);
        std::cout << "--- Making a " << pizza->getName() << " ---" << std::endl;
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore {
public:
    virtual Pizza* createPizza(std::string item)
    {
        Pizza* pizza = nullptr;
        PizzaIngredientFactory* ingredientFactory = new ChicagoPizzaIngredientFactory();

        if (item == "cheese")
        {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("Chicago Style Cheese Pizza");
        }
        else if (item == "veggie")
        {
            pizza = new VeggiePizza(ingredientFactory);
            pizza->setName("Chicago Style Veggie Pizza");
        }
        else if (item == "clam")
        {
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("Chicago Style Clam Pizza");
        }
        else if (item == "pepperoni")
        {
            pizza = new PepperoniPizza(ingredientFactory);
            pizza->setName("Chicago Style Pepperoni Pizza");
        }
        return pizza;
    }
};

class NYPizzaStore : public PizzaStore {
public:
    virtual Pizza* createPizza(std::string item)
    {
        Pizza* pizza = nullptr;
        PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory();

        if (item == "cheese")
        {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("New York Style Cheese Pizza");
        }
        else if (item == "veggie")
        {
            pizza = new VeggiePizza(ingredientFactory);
            pizza->setName("New York Style Veggie Pizza");
        }
        else if (item == "clam")
        {
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("New York Style Clam Pizza");
        }
        else if (item == "pepperoni")
        {
            pizza = new PepperoniPizza(ingredientFactory);
            pizza->setName("New York Style Pepperoni Pizza");
        }
        return pizza;
    }
};

#endif // PIZZA_STORE_H