#ifndef WAITRESS_H
#define WAITRESS_H

#include "menu_component.h"
#include "menu.h"
#include "menu_item.h"

class Waitress {
public:
    Waitress(MenuComponent* _allMenus)
        : allMenus(_allMenus) {}

    void printMenu()
    {
        allMenus->print();
    }

private:
    MenuComponent* allMenus;
};

#endif // WAITRESS_H
