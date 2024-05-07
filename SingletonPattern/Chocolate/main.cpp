#include <chocolate_boiler.h>

int main()
{
    ChocolateBoiler* boiler = ChocolateBoiler::getInstance();
    boiler->fill();
    boiler->boil();
    boiler->drain();

    delete boiler;
    return 0;
}