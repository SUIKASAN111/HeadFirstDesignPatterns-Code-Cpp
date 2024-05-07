#include "caffeine_beverage.h"

#include <iostream>

int main()
{
    Tea* tea = new Tea();
    Coffee* coffee = new Coffee();

    std::cout << "Making tea..." << std::endl;
    tea->prepareRecipe();

    std::cout << "Making coffee..." << std::endl;
    coffee->prepareRecipe();

    delete tea;
    delete coffee;

    return 0;
}