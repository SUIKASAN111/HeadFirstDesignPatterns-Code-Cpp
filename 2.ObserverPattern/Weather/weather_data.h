#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <unordered_set>

#include "subject.h"
#include "observer.h"

class WeatherData : public Subject {
public:
    WeatherData() = default;

    void registerObserver(Observer* o)
    {
        observers.insert(o);
    }

    void removeObserver(Observer* o)
    {
        observers.erase(o);
    }

    void notifyObservers()
    {
        for (Observer* observer : observers)
        {
            observer->update(temperature, humidity, pressure);
        }
    }

    void measurementChanged()
    {
        notifyObservers();
    }

    void setMeasurement(float temperature, float humidity, float pressure)
    {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementChanged();
    }

private:
    std::unordered_set<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;
};

#endif // WEATHER_DATA_H