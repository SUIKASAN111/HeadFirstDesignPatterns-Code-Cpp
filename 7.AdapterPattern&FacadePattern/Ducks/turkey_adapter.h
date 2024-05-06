#ifndef TURKEY_ADAPTER_H
#define TURKEY_ADAPTER_H

#include "duck.h"
#include "turkey.h"

class TurkeyAdapter : public Duck {
public:
    TurkeyAdapter(Turkey* turkey): turkey(turkey) {}

    void quack() override
    {
        turkey->gobble();
    }

    void fly() override
    {
        for (int i = 0; i < 5; ++i)
        {
            turkey->fly();
        }
    }

private:
    Turkey* turkey;
};

#endif // TURKEY_ADAPTER_H