#ifndef MY_ITERATOR_H
#define MY_ITERATOR_H

#include "menu_item.h"

#include <vector>

class MyIterator {
public:
    virtual bool hasNext() = 0;
    virtual MenuItem* next() = 0;
};

class PancakeHouseMenuIterator : public MyIterator {
public:
    PancakeHouseMenuIterator(std::vector<MenuItem*> _items)
        : items(_items)
    {
        position = 0;
    }

    MenuItem* next() override
    {
        return items[position++];
    }

    bool hasNext() override
    {
        return items.size() > position;
    }
    
private:
    std::vector<MenuItem*> items;
    size_t position;
};

class DinerMenuIterator : public MyIterator {
public:
    DinerMenuIterator(MenuItem* _items[])
        : items(_items)
    {
        position = 0;
    }

    MenuItem* next() override
    {
        return items[position++];
    }

    bool hasNext() override
    {
        return MAX_ITEMS > position;
    }

private:
    static const size_t MAX_ITEMS = 6;
    MenuItem** items;
    size_t position;
};



#endif // MY_ITERATOR_H