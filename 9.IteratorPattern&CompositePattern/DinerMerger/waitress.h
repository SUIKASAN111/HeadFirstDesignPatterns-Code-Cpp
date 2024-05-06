#ifndef WAITRESS_H
#define WAITRESS_H

#include "menu.h"

class Waitress {
public:
    Waitress(Menu* _pancakeHouseMenu, Menu* _dinerMenu)
        : pancakeHouseMenu(_pancakeHouseMenu), dinerMenu(_dinerMenu) {}

    void printMenu()
    {
        MyIterator* pancakeIterator = pancakeHouseMenu->createIterator();
        MyIterator* dinerIterator = dinerMenu->createIterator();

        std::cout << "MENU\n----\nBREAKFAST" << std::endl;
        printMenu(pancakeIterator);
        std::cout << "\nLUNCH" << std::endl;
        printMenu(dinerIterator);
    }


    void printVegetarianMenu(){
        printVegetarianMenu(pancakeHouseMenu->createIterator());
        printVegetarianMenu(dinerMenu->createIterator());
    }

    bool isItemVegetarian(std::string _name)
    {
        MyIterator* iterator = pancakeHouseMenu->createIterator();
        if (isVegetarian(_name, iterator))
        {
            return true;
        }
        iterator = dinerMenu->createIterator();
        if (isVegetarian(_name, iterator))
        {
            return true;
        }
        return false;
    }

private:
    Menu* pancakeHouseMenu;
    Menu* dinerMenu;
   
    void printMenu(MyIterator* iterator)
    {
        while (iterator->hasNext())
        {
            MenuItem* menuItem = iterator->next();
            std::cout << menuItem->getName() << ", "
                << menuItem->getPrice() << " -- "
                << menuItem->getDescription() << std::endl;
        }
    }

    void printVegetarianMenu(MyIterator* iterator)
    {
        while (iterator->hasNext())
        {
            MenuItem* menuItem = iterator->next();
            if (menuItem->isVegetarian())
            {
                std::cout << menuItem->getName() << "\t\t"
                    << menuItem->getPrice() << "\t"
                    << menuItem->getDescription() << std::endl;
            }
        }
    }

    bool isVegetarian(std::string _name, MyIterator* iterator)
    {
        while (iterator->hasNext())
        {
            MenuItem* menuItem = iterator->next();
            if (menuItem->getName() == _name)
            {
                if (menuItem->isVegetarian())
                {
                    return true;
                }
            }
        }
    }
};

#endif // WAITRESS_H