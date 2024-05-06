#ifndef WEAPON_BEHAVIOR_H
#define WEAPON_BEHAVIOR_H

#include <iostream>

class WeaponBehavior {
public:
    virtual void useWeapon() = 0;
};

class SwordBehavior : public WeaponBehavior {
    void useWeapon()
    {
        std::cout << "Wielding a sword" << std::endl;
    }
};

class KnifeBehavior : public WeaponBehavior {
    void useWeapon(){
        std::cout << "Stabbing with a knife" << std::endl;
    }
};

class BowAndArrowBehavior : public WeaponBehavior {
    void useWeapon()
    {
        std::cout << "Shooting with a bow and arrow" << std::endl;
    }
};

class AxeBehavior : public WeaponBehavior {
    void useWeapon()
    {
        std::cout << "Slashing with an axe" << std::endl;
    }
};

#endif // WEAPON_BEHAVIOR_H