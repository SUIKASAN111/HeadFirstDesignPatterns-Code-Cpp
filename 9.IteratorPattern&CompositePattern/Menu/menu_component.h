#ifndef MENU_COMPONENT_H
#define MENU_COMPONENT_H

#include <iostream>
#include <string>

struct UnsupportedException : public std::exception
{
    const char* what() const throw()
    {
        return "Unsupported Operation";
    }
};


class MenuComponent {
public:
    virtual void add(MenuComponent*)
    {
        throw UnsupportedException();
    }

    virtual void remove(MenuComponent*)
    {
        throw UnsupportedException();
    }

    virtual MenuComponent* getChild(size_t)
    {
        throw UnsupportedException();
    }

    virtual std::string getName()
    {
		throw UnsupportedException();
    }
    
    virtual std::string getDescription()
    {
        throw UnsupportedException();
    }

    virtual double getPrice()
    {
        throw UnsupportedException();
    }

    virtual bool isVegetarian()
    {
        throw UnsupportedException();
    }

    virtual void print()
    {
        throw UnsupportedException();
    }
};

#endif // MENU_COMPONENT_H