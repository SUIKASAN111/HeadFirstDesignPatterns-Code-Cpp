#ifndef CAFFEINE_BEVERAGE_H
#define CAFFEINE_BEVERAGE_H

#include <iostream>
#include <string>

class CaffeineBeverage {
public:
    void prepareRecipe()
    {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments())
        {
            addCondiments();
        }
    }

    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    virtual void boilWater()
    {
        std::cout << "Boiling water" << std::endl;
    }

    virtual void pourInCup()
    {
        std::cout << "Pouring into cup" << std::endl;
    }

    virtual bool customerWantsCondiments()
    {
        return true;
    }
};


class Coffee : public CaffeineBeverage {
public:
    void brew() override
    {
        std::cout << "Dripping Coffee through filter" << std::endl;
    }

    void addCondiments() override
    {
        std::cout << "Adding Sugar and Milk" << std::endl;
    }

    bool customerWantsCondiments() override
    {
        char answer = getUserInput();

        if (answer == 'y' || answer == 'Y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    char getUserInput()
    {
        std::cout << "Would you like milk and sugar with your coffee (y/n)? " << std::endl;
        char answer;
        while (std::cin >> answer)
        {
            if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
            {
                return answer;
            }
            else
            {
                std::cout << "IO error trying to read your answer" << std::endl;
            }
        }
        return 'n';
    }
};

class Tea : public CaffeineBeverage {
public:
    void brew() override
    {
        std::cout << "Steeping the tea" << std::endl;
    }

    void addCondiments() override
    {
        std::cout << "Adding Lemon" << std::endl;
    }

    bool customerWantsCondiments() override
    {
        char answer = getUserInput();

        if (answer == 'y' || answer == 'Y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    char getUserInput()
    {
        std::cout << "Would you like lemon with your tea (y/n)? " << std::endl;
        char answer;
        while (std::cin >> answer)
        {
            if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
            {
                return answer;
            }
            else
            {
                std::cout << "IO error trying to read your answer" << std::endl;
            }
        }
        return 'n';
    }
};

#endif // CAFFEINE_BEVERAGE_H
