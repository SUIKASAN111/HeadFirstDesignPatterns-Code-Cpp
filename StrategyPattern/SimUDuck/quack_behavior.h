#ifndef QUACK_BEHAVIOR_H
#define QUACK_BEHAVIOR_H

#include <iostream>

// QuackBehavior Interface
class QuackBehavior {
public:
    virtual void quack() = 0;
};

class Quack : public QuackBehavior {
public:
    void quack()
    {
        std::cout << "Quack" << std::endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    void quack()
    {
        std::cout << "<<Silence>>" << std::endl;
    }
};

class Squeak : public QuackBehavior {
public:
    void quack()
    {
        std::cout << "Squeak" << std::endl;
    }
};

#endif // QUACK_BEHAVIOR_H