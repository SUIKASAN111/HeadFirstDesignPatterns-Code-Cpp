#ifndef DUCK_H
#define DUCK_H

#include <iostream>

class Duck {
public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

// concrete duck
class MallardDuck : public Duck {
public:
    void quack() override
    {
        std::cout << "Quack" << std::endl;
    }

    void fly() override
    {
        std::cout << "I'm flying" << std::endl;
    }
};

#endif // DUCK_H