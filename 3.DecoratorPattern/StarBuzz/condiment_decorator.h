#ifndef CONDIMENT_DECORATOR_H
#define CONDIMENT_DECORATOR_H

#include "beverage.h"

class CondimentDecorator : public Beverage {
public:
    virtual Beverage* getBeverage(){
        return this->beverage;
    }

    void setBeverage(Beverage* beverage)
    {
        this->beverage = beverage;
    }

private:
    Beverage* beverage;
};


// Concrete Condiment
class Milk : public CondimentDecorator {
public:
    Milk(Beverage* beverage)
    {
        setBeverage(beverage);
    }

    virtual std::string getDescription()
    {
        return getBeverage()->getDescription() + ", Milk";
    }

    virtual double cost()
    {
        return 0.1 + getBeverage()->cost();
    }
};

class Mocha : public CondimentDecorator {
public:
    Mocha(Beverage* beverage)
    {
        setBeverage(beverage);
    }

    virtual std::string getDescription()
    {
        return getBeverage()->getDescription() + ", Mocha";
    }

    virtual double cost()
    {
        return 0.20 + getBeverage()->cost();
    }
};

class Soy : public CondimentDecorator {
public:
    Soy(Beverage* beverage)
    {
        setBeverage(beverage);
    }

    virtual std::string getDescription()
    {
        return getBeverage()->getDescription() + ", Soy";
    }

    virtual double cost()
    {
        return 0.15 + getBeverage()->cost();
    }
};

class Whip : public CondimentDecorator {
public:
    Whip(Beverage* beverage)
    {
        setBeverage(beverage);
    }

    virtual std::string getDescription()
    {
        return getBeverage()->getDescription() + ", Whip";
    }

    virtual double cost()
    {
        return 0.10 + getBeverage()->cost();
    }
};

#endif // CONDIMENT_DECORATOR_H