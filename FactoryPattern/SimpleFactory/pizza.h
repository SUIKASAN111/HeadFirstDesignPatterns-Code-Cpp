#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <vector>

class Pizza {
public:
    Pizza(const std::string& name, const std::string& dough, const std::string& sauce)
        : name(name), dough(dough), sauce(sauce)
    {}

    const std::string& getName()
    {
        return this->name;
    }

    void prepare()
    {
        std::cout << "Preparing " << this->name << std::endl;
    }

    void bake()
    {
        std::cout << "Baking " << this->name << std::endl;
    }

    void cut()
    {
        std::cout << "Cutting " << this->name << std::endl;
    }

    void box()
    {
        std::cout << "Boxing " << this->name << std::endl;
    }

    std::string getInfo()
    {
        // code to display pizza name and ingredients
        std::string info = "----" + this->name + "----\n";
        info.append(this->dough + "\n");
        info.append(this->sauce + "\n");
        for (auto topping : this->toppings)
        {
            info.append(topping + "\n");
        }
        return info;
    }

    void addTopping(const std::string& toppingName)
    {
        toppings.push_back(toppingName);
    }

private:
    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> toppings;
};

// concrete pizzas
class CheesePizza : public Pizza {
public:
    CheesePizza()
        : Pizza("Cheese Pizza", "Regulat Crust", "Marinara Pizza Sauce")
    {
        addTopping("Fresh Mozzarella");
        addTopping("Parmesan");
    }
};

class ClamPizza : public Pizza {
public:
    ClamPizza()
        : Pizza("Clam Pizza", "Thin Crust", "White Garlic Sauce")
    {
        addTopping("Clams");
        addTopping("Grated Parmesan Cheese");
    }
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza()
        : Pizza("Pepperoni Pizza", "Crust", "Marinara Sauce")
    {
        addTopping("Sliced Pepperoni");
        addTopping("Sliced Onion");
        addTopping("Sliced Pepperoni");
    }
};

class VeggiePizza : public Pizza {
public:
    VeggiePizza()
        : Pizza("Veggie Pizza", "Crust", "Marinara Sauce")
    {
        addTopping("Shredden mozzarella");
        addTopping("Grated parmesan");
		addTopping("Diced onion");
		addTopping("Sliced mushrooms");
		addTopping("Sliced red pepper");
		addTopping("Sliced black olives");
    }
};

#endif // PIZZA_H