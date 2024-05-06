#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <vector>

#include "ingredients.h"
#include "pizza_ingredient_factory.h"

class Pizza {
public:
    virtual ~Pizza()
    {
        delete dough;
        delete sauce;
        delete cheese;
        delete pepperoni;
        delete clam;
    }
    
    const std::string& getName()
    {
        return this->name;
    }

    void setName(std::string name)
    {
        this->name = name;
    }
    
    virtual void prepare() = 0;

    void bake()
    {
        std::cout << "Bake for 25 minutes at 350" << std::endl;
    }

    void cut()
    {
        std::cout << "Cut the pizza into diagonal slices" << std::endl;
    }

    void box()
    {
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    }

    std::string getInfo()
    {
        std::string result;
        result.append("---- " + this->getName() + " Ingredients ----\n");
        if (dough != nullptr)
            result.append(dough->getInfo() + "\n");
        if (sauce != nullptr)
            result.append(sauce->getInfo() + "\n");
        if (cheese != nullptr)
            result.append(cheese->getInfo() + "\n");
        if (clam != nullptr)
            result.append(clam->getInfo() + "\n");
        if (pepperoni != nullptr)
            result.append(pepperoni->getInfo() + "\n");
        if (!veggies.empty())
        {
            for (Veggies* veggie : veggies)
            {
                result.append(veggie->getInfo());
                if (veggie != veggies.back())
                    result.append(", ");
            }
        }
        return result;
    }

    void setdDough(Dough* dough)
    {
        this->dough = dough;
    }

    void setSauce(Sauce* sauce)
    {
        this->sauce = sauce;
    }

    void setCheese(Cheese* cheese)
    {
        this->cheese = cheese;
    }

    void setPepperoni(Pepperoni* pepperoni)
    {
        this->pepperoni = pepperoni;
    }

    void setClam(Clams* clam)
    {
        this->clam = clam;
    }

    void setVeggie(std::vector<Veggies*> veggies)
    {
        this->veggies = veggies;
    }

private:
    std::string name;

    Dough* dough;
    Sauce* sauce;
    Cheese* cheese;
    Pepperoni* pepperoni;
    Clams* clam;
    std::vector<Veggies*> veggies;
};

// concrete pizza
class CheesePizza : public Pizza {
public:
    CheesePizza(PizzaIngredientFactory* ingredientFactory)
    {
        this->ingredientFactory = ingredientFactory;
    }

    virtual ~CheesePizza()
    {
        delete ingredientFactory;
    }

    virtual void prepare()
    {
        std::cout << "Preparing " << this->getName() << std::endl;
        setdDough(ingredientFactory->createDough());
        setSauce(ingredientFactory->createSauce());
        setCheese(ingredientFactory->createCheese());
    }

private:
    PizzaIngredientFactory* ingredientFactory;
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza(PizzaIngredientFactory* ingredientFactory)
    {
        this->ingredientFactory = ingredientFactory;
    }

    virtual ~PepperoniPizza()
    {
        delete ingredientFactory;
    }
    
    virtual void prepare()
    {
        std::cout << "Preparing " << this->getName() << std::endl;
        setdDough(ingredientFactory->createDough());
        setSauce(ingredientFactory->createSauce());
        setCheese(ingredientFactory->createCheese());
        setPepperoni(ingredientFactory->createPepperoni());
        setVeggie(ingredientFactory->createVeggies());
    }

private:
    PizzaIngredientFactory* ingredientFactory;
};

class VeggiePizza : public Pizza {
public:
    VeggiePizza(PizzaIngredientFactory* ingredientFactory)
    {
        this->ingredientFactory = ingredientFactory;
    }

    virtual ~VeggiePizza()
    {
        delete ingredientFactory;
    }

    virtual void prepare()
    {
        std::cout << "Preparing " << this->getName() << std::endl;
        setdDough(ingredientFactory->createDough());
        setSauce(ingredientFactory->createSauce());
        setCheese(ingredientFactory->createCheese());
        setVeggie(ingredientFactory->createVeggies());
    }

private:
    PizzaIngredientFactory* ingredientFactory;
};

class ClamPizza : public Pizza {
public:
    ClamPizza(PizzaIngredientFactory* ingredientFactory)
    {
        this->ingredientFactory = ingredientFactory;
    }

    virtual ~ClamPizza()
    {
        delete ingredientFactory;
    }

    virtual void prepare()
    {
        std::cout << "Preparing " << this->getName() << std::endl;
        setdDough(ingredientFactory->createDough());
        setSauce(ingredientFactory->createSauce());
        setCheese(ingredientFactory->createCheese());
        setClam(ingredientFactory->createClam());
    }

private:
    PizzaIngredientFactory* ingredientFactory;
};

#endif // PIZZA_H