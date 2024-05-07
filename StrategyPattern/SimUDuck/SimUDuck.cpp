#include <iostream>

#include "duck.h"

int main()
{
    std::cout << "----------Test MallardDuck----------" << std::endl;
    Duck* mallard = new MallardDuck();
    mallard->performQuack();
    mallard->performFly();
    mallard->swim();
    delete mallard;
    mallard = nullptr;
    std::cout << "------------------------------------\n" << std::endl;

    std::cout << "----------Test ModelDuck----------" << std::endl;
    Duck* model = new ModelDuck();
    model->performFly();
    model->setFlyBehavior(new FlyRocketPowered());
    model->performFly();
    model->swim();
    delete model;
    model = nullptr;
    std::cout << "----------------------------------" << std::endl;

    return 0;
}

