#ifndef MENU_H
#define MENU_H

#include "menu_component.h"

#include <vector>

class Menu : public MenuComponent {
public:
    Menu(std::string _name, std::string _description)
        : name(_name), description(_description) {}

    void add(MenuComponent* menuComponent) override
    {
        menuComponents.emplace_back(menuComponent);
    }

    void remove(MenuComponent* menuComponent) override
    {
        for (auto iter = menuComponents.begin(); iter != menuComponents.end(); ++iter)
        {
            if (*iter == menuComponent)
            {
                menuComponents.erase(iter);
                break;
            }
        }
    }

    MenuComponent* getChild(size_t i) override
    {
        return menuComponents[i];
    }

    std::string getName() override
    {
        return name;
    }

    std::string getDescription() override
    {
        return description;
    }

    void print() override
    {
        std::cout << "\n" << getName()
            << ", " << getDescription() << std::endl;
        std::cout << "---------------------" << std::endl;

        for (auto iter = menuComponents.cbegin(); iter != menuComponents.cend(); ++iter)
        {
            (*iter)->print();
        }
    }

private:
    std::vector<MenuComponent*> menuComponents;
    std::string name;
    std::string description;
};


#endif // MENU_H
