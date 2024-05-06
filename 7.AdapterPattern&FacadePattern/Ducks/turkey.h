#ifndef TURKEY_H
#define TURKEY_H

#include <iostream>

class Turkey {
public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

// concrete turkey
class WildTurkey : public Turkey {
public:
    void gobble() override
    {
        std::cout << "Gobble gobble" << std::endl;
    }

    void fly() override
    {
        std::cout << "I'm flying a short distance" << std::endl;
    }
};

#endif // TURKEY_H