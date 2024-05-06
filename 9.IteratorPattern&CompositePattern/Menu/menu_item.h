#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include "menu_component.h"

class MenuItem : public MenuComponent {
public:
    MenuItem(std::string _name, std::string _description, bool _vegetarian, double _price)
        : name(_name), description(_description), vegetarian(_vegetarian), price(_price) {}

    std::string getName() override
    {
        return name;
    }

    std::string getDescription() override
    {
        return description;
    }

    double getPrice() override
    {
        return price;
    }
    
    bool isVegetarian() override
    {
        return vegetarian;
    }

    void print() override
    {
        std::cout << "  " + getName();
        if (isVegetarian())
        {
            std::cout << "(v)";
        }
        std::cout << ", " << getPrice() << std::endl;
        std::cout << "     -- " << getDescription() << std::endl;
    }
    
private:
    std::string name;
    std::string description;
    bool vegetarian;
    double price;
};

#endif // MENU_ITEM_H
