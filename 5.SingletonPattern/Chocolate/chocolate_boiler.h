#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include <iostream>

class ChocolateBoiler {
public:
    static ChocolateBoiler* getInstance()
    {
        if (uniqueInstance == nullptr)
        {
            std::cout << "Creating unique instance of Chocolate Boiler" << std::endl;
            uniqueInstance = new ChocolateBoiler();
        }
        std::cout << "Returning instance of Chocolate Boiler" << std::endl;
        return uniqueInstance;
    }

    void fill()
    {
        if (isEmpty())
        {
            std::cout << "filling..." << std::endl;
            empty = false;
            boiled = false;
        }
    }

    void drain()
    {
        if (!isEmpty() && isBoiled())
        {
            std::cout << "drain" << std::endl;
            empty = true;
        }
    }

    void boil()
    {
        if (!isEmpty() && !isBoiled())
        {
            std::cout << "boiling..." << std::endl;
            boiled = true;
        }
    }

    bool isEmpty()
    {
        return empty;
    }

    bool isBoiled()
    {
        return boiled;
    }

private:
    bool empty;
    bool boiled;
    static ChocolateBoiler* uniqueInstance;
    ChocolateBoiler() : empty(true), boiled(false) {}
};

ChocolateBoiler* ChocolateBoiler::uniqueInstance = nullptr;

# endif // CHOCOLATE_H