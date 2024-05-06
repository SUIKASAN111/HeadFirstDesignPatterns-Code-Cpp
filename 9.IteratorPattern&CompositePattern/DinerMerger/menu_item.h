#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>

class MenuItem {
public:
    MenuItem(std::string _name, std::string _description, bool _vegetarian, double _price)
        : name(_name), description(_description), vegetarian(_vegetarian), price(_price) {}

    std::string getName()
    {
        return name;
    }

    std::string getDescription()
    {
        return description;
    }

    bool isVegetarian()
    {
        return vegetarian;
    }

    double getPrice()
    {
        return price;
    }

    // bool operator==(MenuItem rhs)
    // {
    //     if (this->name == rhs.name &&
    //         this->description == rhs.description &&
    //         this->vegetarian == rhs.vegetarian &&
    //         this->price == rhs.price)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
    
    // MenuItem operator=(MenuItem rhs)
    // {
    //     if (rhs == *this)
    //     {
    //         return *this;
    //     }
    //     this->name = rhs.name;
    //     this->description = rhs.description;
    //     this->vegetarian = rhs.vegetarian;
    //     this->price = rhs.price;
    //     return *this;
    // }
    
private:
    std::string name;
    std::string description;
    bool vegetarian;
    double price;
};


#endif // MENU_ITEM_H