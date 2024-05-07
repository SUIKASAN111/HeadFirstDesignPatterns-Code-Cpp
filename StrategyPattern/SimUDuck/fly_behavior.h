#ifndef FLY_BEHAVIOR_H
#define FLY_BEHAVIOR_H

#include <iostream>

// FlyBehavior Interface
class FlyBehavior {
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
public:
    void fly()
    {
        std::cout << "I'm flying!!" << std::endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly()
    {
        std::cout << "I can't fly" << std::endl;
    }
};

class FlyRocketPowered : public FlyBehavior {
public:
    void fly()
    {
        std::cout << "I'm flying with a rocket!" << std::endl;
    }
};

#endif // FLY_BEHAVIOR_H