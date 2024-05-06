#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>

class Beverage {
public:
    virtual std::string getDescription()
    {
        return description;
    }

    void setDescription(const std::string& description)
    {
        this->description = description;
    }

    virtual double cost() = 0;

private:
    std::string description = "Unknown Beverage";
};


// Concrete Beverage
class Espresso : public Beverage {
public:
    Espresso()
    {
        setDescription("Espresso");
    }

    virtual double cost(){
        return 1.99;
    }
};

class HouseBlend : public Beverage {
public:
    HouseBlend()
    {
        setDescription("House Blend Coffee");
    }

    virtual double cost()
    {
        return 0.89;
    }
};

class DarkRoast : public Beverage {
public:
    DarkRoast()
    {
        setDescription("Dark Roast Coffee");
    }

    virtual double cost()
    {
        return 0.99;
    }

};

class Decaf : public Beverage {
public:
    Decaf()
    {
        setDescription("Decaf Coffee");
    }
};



#endif // BEVERAGE_H