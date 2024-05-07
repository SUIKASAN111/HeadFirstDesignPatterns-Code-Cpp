#ifndef DISPLAY_ELEMENT_H
#define DISPLAY_ELEMENT_H

#include <iostream>

#include "observer.h"
#include "weather_data.h"

class DisplayElement : public Observer {
public:
    virtual void display() = 0;
};

class CurrentConditionsDisplay : public DisplayElement {
public:
    CurrentConditionsDisplay(WeatherData* weatherData)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure)
    {
        this->temperature = temperature;
        this->humidity = humidity;
        display();
    }

    void display()
    {
        std::cout << "------------------------------" << std::endl;
        std::cout << "Current condition: " << temperature << " Celsius and "
            << humidity << "% humidity" << std::endl;
        std::cout << "------------------------------" << std::endl;
    }

private:
    float temperature;
    float humidity;
    WeatherData* weatherData;
};

class StatisticDisplay : public DisplayElement {
public:
    StatisticDisplay(WeatherData* weatherData)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure)
    {
        tempSum += temperature;
        ++numReadings;

        if (temperature > maxTemp)
            maxTemp = temperature;

        if (temperature < minTemp)
            minTemp = temperature;

        display();
    }

    void display()
    {
        std::cout << "------------------------------" << std::endl;
        std::cout << "Avg/Max/Min temperature = " << tempSum / numReadings
            << "/" << maxTemp << "/" << minTemp << std::endl;
        std::cout << "------------------------------" << std::endl;
    }

private:
    float maxTemp = 0.0f;
    float minTemp = 200;
    float tempSum = 0.0f;
    int numReadings;
    WeatherData* weatherData;
};

class ForecastDisplay : public DisplayElement {
public:
    ForecastDisplay(WeatherData* weatherData)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure)
    {
        lastPressure = currentPressure;
        currentPressure = pressure;

        display();
    }
    
    void display()
    {
        std::cout << "------------------------------" << std::endl;
        if (currentPressure > lastPressure)
        {
            std::cout << "Improving weather on the way!" << std::endl;
        }
        else if (currentPressure == lastPressure)
        {
            std::cout << "More of the same" << std::endl;
        }
        else
        {
            std::cout << "Watch out for cooler, rainy weather" << std::endl;
        }
        std::cout << "------------------------------" << std::endl;
    }

private:
    float currentPressure = 29.92f;
    float lastPressure;
    WeatherData* weatherData;
};

#endif // DISPLAY_ELEMENT_H