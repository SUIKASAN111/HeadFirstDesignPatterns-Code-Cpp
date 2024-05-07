#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <iostream>
#include <string>

// Dough
class Dough {
public:
    virtual std::string getInfo() = 0;
};

class ThickCrustDough : public Dough {
public:
    virtual std::string getInfo()
    {
        return "ThickCrust style extra thick crust dough";
    }
};

class ThinCrustDough : public Dough {
public:
    virtual std::string getInfo()
    {
        return "Thin Crust Dough";
    }
};

// Sauce
class Sauce {
public:
    virtual std::string getInfo() = 0;
};

class PlumTomatoSauce : public Sauce {
public:
    virtual std::string getInfo()
    {
		return "Tomato sauce with plum tomatoes";
    }
};

class MarinaraSauce : public Sauce {
public:
    virtual std::string getInfo()
    {
		return "Marinara Sauce";
    }
};

// Cheese
class Cheese {
public:
    virtual std::string getInfo() = 0;
};

class ReggianoCheese : public Cheese {
public:
    virtual std::string getInfo()
    {
		return "Reggiano Cheese";
    }
};

class MozzarellaCheese : public Cheese {
public:
    virtual std::string getInfo()
    {
        return "Shredded Mozzarella";
    }
};

class ParmesanCheese : public Cheese {
public:
    virtual std::string getInfo()
    {
		return "Shredded Parmesan";
    }
};

// Pepperoni
class Pepperoni {
public:
    virtual std::string getInfo() = 0;
};

class SlicedPepperoni : public Pepperoni {
public:
    virtual std::string getInfo()
    {
		return "Sliced Pepperoni";
    }
};

// Clams
class Clams {
public:
    virtual std::string getInfo() = 0;
};

class FreshClams : public Clams {
public:
    virtual std::string getInfo()
    {
        return "Fresh Clams from Long Island Sound";
    }
};

class FrozenClams : public Clams {
public:
    virtual std::string getInfo()
    {
        return "Frozen Clams from Chesapeake Bay";
    }
};

// Veggies
class Veggies {
public:
    virtual std::string getInfo() = 0;
};

class Eggplant : public Veggies {
public:
    virtual std::string getInfo()
    {
        return "Eggplant";
    }
};

class Garlic : public Veggies {
public:
    virtual std::string getInfo()
    {
		return "Garlic";
    }
};

class RedPepper : public Veggies {
public:
    virtual std::string getInfo()
    {
        return "Red Pepper";
    }
};

class Spinach : public Veggies {
public:
    virtual std::string getInfo()
    {
		return "Spinach";
    }
};

class BlackOlives : public Veggies {
public:
    virtual std::string getInfo()
    {
		return "Black Olives";
    }
};

class Mushroom : public Veggies {
public:
    virtual std::string getInfo()
    {
        return "Mushrooms";
    }
};

class Onion : public Veggies {
public:
    virtual std::string getInfo()
    {
        return "Onion";
    }
};

#endif // INGREDIENTS_H