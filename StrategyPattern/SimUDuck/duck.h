#ifndef DUCK_H
#define DUCK_H

#include <iostream>

#include "fly_behavior.h"
#include "quack_behavior.h"

class Duck {
public:
    virtual void display() = 0;

    Duck(FlyBehavior* fb, QuackBehavior* qb)
        : flyBehavoir(fb), quackBehavior(qb)
    {}
        
    virtual ~Duck()
    {
        delete flyBehavoir;
        flyBehavoir = nullptr;
        delete quackBehavior;
        quackBehavior = nullptr;
    }
    
    void setFlyBehavior(FlyBehavior* fb)
    {
        delete flyBehavoir;
        flyBehavoir = fb;
    }

    void setQuackBehavior(QuackBehavior* qb)
    {
        delete quackBehavior;
        quackBehavior = qb;
    }

    void performFly()
    {
        flyBehavoir->fly();
    }

    void performQuack()
    {
        quackBehavior->quack();
    }

    void swim()
    {
        std::cout << "All ducks floats, even decoys!" << std::endl;
    }

private:
    FlyBehavior* flyBehavoir;
    QuackBehavior* quackBehavior;
};


// MallardDuck
class MallardDuck : public Duck {
public:
    MallardDuck()
        : Duck(new FlyWithWings(), new Quack())
    {}
        
    void display()
    {
        std::cout << "I'm a real Mallard duck" << std::endl;
    }
};

// ModelDuck
class ModelDuck : public Duck {
public:
    ModelDuck()
        : Duck(new FlyNoWay(), new Quack())
    {}

    void display()
    {
        std::cout << "I'm a model duck" << std::endl;
    }
};

#endif // DUCK_H