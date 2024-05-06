#ifndef DUCK_ADAPTER_H
#define DUCK_ADAPTER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "duck.h"
#include "turkey.h"

class DuckAdapter : public Turkey {
public:
    DuckAdapter(Duck* duck) : duck(duck) {}

    void gobble() override
    {
        duck->quack();
    }

    void fly() override
    {
        srand(time(nullptr));

        if (rand() % 5 == 0)
        {
            duck->fly();
        }
    }

private:
    Duck* duck;
};

#endif // DUCK_ADAPTER_H