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
        std::cout << "Prepare " << this->name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings: " << std::endl;
        for (auto topping : toppings)
        {
            std::cout << "   " << topping;
        }
        std::cout << std::endl;
    }

    void bake()
    {
        std::cout << "Bake for 25 minutes at 350" << std::endl;
    }

    virtual void cut()
    {
        std::cout << "Cut the pizza into diagonal slices" << std::endl;
    }

    void box()
    {
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    }

    std::string getInfo()
    {
        // code to display pizza name and ingredients
        std::string info = "----" + this->name + "----\n";
        info.append(this->dough + "\n");
        info.append(this->sauce + "\n");
        for (auto topping : this->toppings)
        {
            if (topping == this->toppings.back())
                info.append(topping);
            info.append(topping + ", ");    
        }
        info.append("\n" + std::string(40, '-') + "\n");
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
// chicago style
class ChicagoStyleCheesePizza : public Pizza {
public:
    ChicagoStyleCheesePizza()
        : Pizza("Chicago Style Deep Dish Cheese Pizza",
            "Extra Thick Crust Dough", "Plum Tomato Sauce")
    {
        addTopping("Shredded Mozzarella Cheese");
    }

    virtual void cut()
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStyleClamPizza : public Pizza {
public:
    ChicagoStyleClamPizza()
        : Pizza("Chicago Style Clam Pizza",
            "Extra Thick Crust Dough", "Plum Tomato Sauce")
    {
        addTopping("Shredded Mozzarella Cheese");
        addTopping("Frozen Clams from Chesapeake Bay");
    }

    virtual void cut()
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStylePepperoniPizza : public Pizza {
public:
    ChicagoStylePepperoniPizza()
        : Pizza("Chicago Style Pepperoni Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
    {
        addTopping("Shredded Mozzarella Cheese");
        addTopping("Black Olives");
        addTopping("Spinach");
        addTopping("Eggplant");
        addTopping("Sliced Pepperoni");
    }

    virtual void cut()
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStyleVeggiePizza : public Pizza {
public:
    ChicagoStyleVeggiePizza()
        : Pizza("Chicago Deep Dish Veggie Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
    {
        addTopping("Shredded Mozzarella Cheese");
        addTopping("Black Olives");
        addTopping("Spinach");
        addTopping("Eggplant");
    }

    virtual void cut()
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

// NY style
class NYStyleCheesePizza : public Pizza {
public:
    NYStyleCheesePizza()
        : Pizza("NY Style Sauce and Cheese Pizza", "Thin Crust Dough", "Marinara Sauce")
    {
        addTopping("Grated Reggiano Cheese");
    }
};

class NYStyleClamPizza : public Pizza {
public:
    NYStyleClamPizza()
        : Pizza("NY Style Clam Pizza",
            "Thin Crust Dough", "Marinara Sauce")
    {
        addTopping("Grated Reggiano Cheese");
        addTopping("Fresh Clams from Long Island Sound");
    }
};

class NYStylePepperoniPizza : public Pizza {
public:
    NYStylePepperoniPizza()
        : Pizza("NY Style Pepperoni Pizza",
            "Thin Crust Dough", "Marinara Sauce")
    {
        addTopping("Grated Reggiano Cheese");
        addTopping("Sliced Pepperoni");
        addTopping("Garlic");
        addTopping("Onion");
        addTopping("Mushrooms");
        addTopping("Red Pepper");
    }
};

class NYStyleVeggiePizza : public Pizza {
public:
    NYStyleVeggiePizza()
        : Pizza("NY Style Veggie Pizza",
            "Thin Crust Dough", "Marinara Sauce")
    {
        addTopping("Grated Reggiano Cheese");
        addTopping("Garlic");
        addTopping("Onion");
        addTopping("Mushrooms");
        addTopping("Red Pepper");
    }
};

#endif // PIZZA_H