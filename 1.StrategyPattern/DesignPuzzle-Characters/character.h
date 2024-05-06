#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

#include "Weapon_behavior.h"

class Character {
public:
    Character(WeaponBehavior* wb)
        : weaponBehavior(wb)
    {}

    ~Character()
    {
        delete weaponBehavior;
        weaponBehavior = nullptr;
    }

    void setWeaponBehavior(WeaponBehavior* wb)
    {
        delete weaponBehavior;
        weaponBehavior = wb;
    }
    
    virtual void fight()
    {
        weaponBehavior->useWeapon();
    }

    virtual void display() = 0;
private:
    WeaponBehavior* weaponBehavior;
};

class King : public Character {
public:
    King()
        : Character(new SwordBehavior())
    {}

    void display()
    {
        std::cout << "I'm King" << std::endl;
    }
};

class Queen : public Character {
public:
    Queen()
        : Character(new KnifeBehavior())
    {}

    void display()
    {
        std::cout << "If the Queen had balls, She'd be the King :)" << std::endl;
    }
};

class Knight : public Character {
public:
    Knight()
        : Character(new BowAndArrowBehavior())
    {}

    void display()
    {
        std::cout << "I'm the Knight" << std::endl;
    }
};

class Troll : public Character {
public:
    Troll()
        : Character(new AxeBehavior())
    {}

    void display()
    {
        std::cout << "I'm the Troll" << std::endl;
    }
};

#endif // CHARACTER_H