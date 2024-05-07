#include <iostream>

#include "Character.h"

int main()
{
    std::cout << "----------Test King----------" << std::endl;
    Character* king = new King();
    king->display();
    king->fight();
    delete king;
    king = nullptr;
    std::cout << "-----------------------------\n" << std::endl;

    std::cout << "----------Test Quenn----------" << std::endl;
    Character* queen = new Queen();
    queen->display();
    queen->fight();
    delete queen;
    queen = nullptr;
    std::cout << "------------------------------\n" << std::endl;

    std::cout << "----------Test Knight----------" << std::endl;
    Character* knight = new Knight();
    knight->display();
    knight->fight();
    knight->setWeaponBehavior(new KnifeBehavior());
    knight->fight();
    delete knight;
    knight = nullptr;
    std::cout << "-------------------------------\n" << std::endl;
    
    std::cout << "----------Test Troll----------" << std::endl;
    Character* troll = new Troll();
    troll->display();
    troll->fight();
    delete troll;
    troll = nullptr;
    std::cout << "------------------------------\n" << std::endl;

    return 0;
}