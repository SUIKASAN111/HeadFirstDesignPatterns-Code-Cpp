#ifndef PIZZA_INGREDIENT_FACTORY_H
#define PIZZA_INGREDIENT_FACTORY_H

#include <vector>

#include "ingredients.h"

class PizzaIngredientFactory {
public:
    virtual Dough* createDough() = 0;
    virtual Sauce* createSauce() = 0;
    virtual Cheese* createCheese() = 0;
    virtual Pepperoni* createPepperoni() = 0;
    virtual Clams* createClam() = 0;
    virtual std::vector<Veggies*> createVeggies() = 0;
};

// concrete ingredient factory
class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    virtual Dough* createDough()
    {
        return new ThickCrustDough();
    }

    virtual Sauce* createSauce()
    {
        return new PlumTomatoSauce();
    }

    virtual Cheese* createCheese()
    {
        return new MozzarellaCheese();
    }

    virtual Pepperoni* createPepperoni()
    {
        return new SlicedPepperoni();
    }

    virtual Clams* createClam()
    {
        return new FrozenClams();
    }

    virtual std::vector<Veggies*> createVeggies()
    {
        std::vector<Veggies*> veggies{ new BlackOlives(),
                                       new Spinach(),
                                       new Eggplant() };
        return veggies;
    }
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    virtual Dough* createDough()
    {
        return new ThinCrustDough();
    }

    virtual Sauce* createSauce()
    {
        return new MarinaraSauce();
    }

    virtual Cheese* createCheese()
    {
        return new ReggianoCheese();
    }

    virtual Pepperoni* createPepperoni()
    {
        return new SlicedPepperoni();
    }

    virtual Clams* createClam()
    {
        return new FreshClams();
    }

    virtual std::vector<Veggies*> createVeggies()
    {
        std::vector<Veggies*> veggies{ new Garlic(),
                                       new Onion(),
                                       new Mushroom(),
                                       new RedPepper() };
        return veggies;
    }
};

#endif // PIZZA_INGREDIENT_FACTORY_H