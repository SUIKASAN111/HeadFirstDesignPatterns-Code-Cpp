#ifndef MENU_H
#define MENU_H

#include "menu_item.h"
#include "my_iterator.h"

#include <vector>
#include <iostream>

class Menu {
public:
    virtual MyIterator* createIterator() = 0;
};


class PancakeHouseMenu : public Menu {
public:
    PancakeHouseMenu()
    {
        menuItems.clear();
        addItem("K&B's Pancake Breakfast", 
			"Pancakes with scrambled eggs and toast", 
			true,
			2.99);
 
		addItem("Regular Pancake Breakfast", 
			"Pancakes with fried eggs, sausage", 
			false,
			2.99);
 
		addItem("Blueberry Pancakes",
			"Pancakes made with fresh blueberries",
			true,
			3.49);
 
		addItem("Waffles",
			"Waffles with your choice of blueberries or strawberries",
			true,
			3.59);
    }

    void addItem(std::string _name, std::string _description, bool _vegetarian, double _price)
    {
        MenuItem* menuItem = new MenuItem(_name, _description, _vegetarian, _price);
        menuItems.emplace_back(menuItem);
    }

    std::vector<MenuItem*> getMenuItems()
    {
        return menuItems;
    }

    MyIterator* createIterator() override
    {
        return new PancakeHouseMenuIterator(menuItems);
    }

    std::string getInfo(){
        return "Pancake House Menu";
    }

private:
    std::vector<MenuItem*> menuItems;
};

class DinerMenu : public Menu {
public:
    DinerMenu()
    {
        numberOfItems = 0;
        addItem("Vegetarian BLT",
			"(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
		addItem("BLT",
			"Bacon with lettuce & tomato on whole wheat", false, 2.99);
		addItem("Soup of the day",
			"Soup of the day, with a side of potato salad", false, 3.29);
		addItem("Hotdog",
			"A hot dog, with sauerkraut, relish, onions, topped with cheese",
			false, 3.05);
		addItem("Steamed Veggies and Brown Rice",
			"Steamed vegetables over brown rice", true, 3.99);
		addItem("Pasta",
			"Spaghetti with Marinara Sauce, and a slice of sourdough bread",
			true, 3.89);
    }

    void addItem(std::string _name, std::string _description, bool _vegetarian, double _price)
    {
        if (numberOfItems >= MAX_ITEMS)
        {
            std::cout << "Sorry, menu is full!  Can't add item to menu" << std::endl;
        }
        else
        {
            MenuItem* menuItem = new MenuItem(_name, _description, _vegetarian, _price);
            menuItems[numberOfItems++] = menuItem;
        }
    }

    auto getMenuItems()
    {
        return menuItems;
    }

    MyIterator* createIterator()
    {
        return new DinerMenuIterator(menuItems);
    }
    
private:
    static const size_t MAX_ITEMS = 6;
    size_t numberOfItems;
    MenuItem* menuItems[MAX_ITEMS];
};

    
#endif // MENU_H