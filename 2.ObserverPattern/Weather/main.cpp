#include "weather_data.h"
#include "display_element.h"

int main()
{
    WeatherData* weatherData = new WeatherData();

    CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(weatherData);
    StatisticDisplay* statisticDisplay = new StatisticDisplay(weatherData);
    ForecastDisplay* forecastDisplay = new ForecastDisplay(weatherData);

    weatherData->setMeasurement(23, 65, 30.4f);
    std::cout << std::endl;
    weatherData->setMeasurement(25, 70, 29.2f);
    std::cout << std::endl;
    weatherData->setMeasurement(19, 90, 29.2f);

    return 0;
}