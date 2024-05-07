#include "menu_item.h"
#include "menu.h"
#include "my_iterator.h"
#include "waitress.h"

int main()
{
    Menu* pancakeHouseMenu = new PancakeHouseMenu();
    Menu* dinerMenu = new DinerMenu();

    Waitress* waitress = new Waitress(pancakeHouseMenu, dinerMenu);

    waitress->printMenu();

    delete waitress;
    delete pancakeHouseMenu, dinerMenu;

    return 0;
}