#include "weather.h"

/// @brief Initializes default location and DataFetcher object
/// @author Dylan Nasution
Weather::Weather() {
    // default location
    location = "London, ON, Canada";

    // fetcher to execute API calls
    fetcher = new DataFetcher(location);
    fetchAll();
}

/// @brief Updates the weather from a given location
/// @param location The new location
/// @return True if location is found and weather is updated, false if otherwise
/// @author Dylan Nasution, Stuart Fong
bool Weather::updateWeather(QString location) {
    QJsonArray loc = fetcher->fetchLatLon(location);
    if (loc.at(3).toInt() != 0) {
        this->location = loc.at(2).toString();
        fetcher->callAPI(loc.at(0).toString(), loc.at(1).toString());
        fetchAll();

        return true;
    } else
        return false;
}

/// @brief Gets the user location
/// @return Location
/// @author Dylan Nasution
QString Weather::getLocation() { return location; }

/// @brief Updates the weather from fetcher
/// @return Location
/// @author Dylan Nasution
void Weather::fetchAll() {
    timeLastUpdated = fetcher->getTimeLastUpdated();

    // for the current time of today
    currTemperature = fetcher->fetchTemperature();
    feelsLike = fetcher->fetchFeelsLike();
    currConditions = fetcher->fetchConditions();
    currIcon = fetcher->fetchCurrentIcon();
    sunrise = fetcher->fetchSunrise();
    sunset = fetcher->fetchSunset();
    currHumidity = fetcher->fetchHumidity();

    // for 48 hours from current time of day
    hour = fetcher->fetchHours();
    hourlyTemperature = fetcher->fetchHourlyTemperatures();
    hourlyPrecipitationChance = fetcher->fetchHourlyPrecipitations();
    hourlyHumidity = fetcher->fetchHourlyHumidities();
    hourlyConditions = fetcher->fetchHourlyConditions();
    hourlyIcon = fetcher->fetchHourlyIcons();

    // for next 7 days not including today
    day = fetcher->fetchDays();
    futureTemperature = fetcher->fetchFutureTemperatures();
    futurePrecipitationChance = fetcher->fetchFuturePreciptations();
    futureHumidity = fetcher->fetchFutureHumidities();
    futureConditions = fetcher->fetchFutureConditions();
    futureIcon = fetcher->fetchFutureIcons();
    futureSunset = fetcher->fetchFutureSunsets();
    futureSunrise = fetcher->fetchFutureSunrises();
}

/// @brief Gets the time that the weather was last updated
/// @return Time that the weather was last updated
/// @author Dylan Nasution
QString Weather::getTimeLastUpdated() { return timeLastUpdated; }

/// @brief Gets the current weather
/// @return The current weather
/// @author Dylan Nasution
double Weather::getCurrTemperature() { return currTemperature; }

/// @brief Gets the current conditions
/// @return Current conditions
/// @author Dylan Nasution
QString Weather::getCurrConditions() { return currConditions; }

/// @brief Gets the current weather icon
/// @return Current weather icon
/// @author Dylan Nasution
QPixmap Weather::getCurrIcon() { return currIcon; }

/// @brief Gets the feel like temperature
/// @return The feel like temperature
/// @author Dylan Nasution
double Weather::getFeelsLike() { return feelsLike; }

/// @brief Gets the current humidity
/// @return The current humidity
/// @author Dylan Nasution
double Weather::getCurrHumidity() { return currHumidity; }

/// @brief Gets todays sunset time
/// @return The sunset time
/// @author Dylan Nasution
QString Weather::getSunset() { return sunset; }

/// @brief Gets todays sunrise time
/// @return The sunrise time
/// @author Dylan Nasution
QString Weather::getSunrise() { return sunrise; }

/// @brief Gets the next 48 hours
/// @return Array of the next 48 hours
/// @author Dylan Nasution
QVector<QString> Weather::getHours() { return hour; };

/// @brief Gets the hourly weather
/// @return Array of the weather for the next 48 hours
/// @author Dylan Nasution
QVector<double> Weather::getHourlyTemperatures() { return hourlyTemperature; }

/// @brief Gets the hourly precipitation
/// @return Array of the precipitation for the next 48 hours
/// @author Dylan Nasution
QVector<double> Weather::getHourlyPrecipitations() {
    return hourlyPrecipitationChance;
}

/// @brief Gets the hourly humidity
/// @return Array of the humidity for the next 48 hours
/// @author Dylan Nasution
QVector<double> Weather::getHourlyHumidities() { return hourlyHumidity; }

/// @brief Gets the hourly conditions
/// @return Array of the conditions for the next 48 hours
/// @author Dylan Nasution
QVector<QString> Weather::getHourlyConditions() { return hourlyConditions; }

/// @brief Gets the hourly icons
/// @return Array of the weather icons for the next 48 hours
/// @author Dylan Nasution
QVector<QPixmap> Weather::getHourlyIcons() { return hourlyIcon; }

/// @brief Gets the next 7 days in timestamps
/// @return Array of the next 7 days in timestamps
/// @author Dylan Nasution
QVector<time_t> Weather::getDays() { return day; };

/// @brief Gets the weather for the next 7 days
/// @return Array of the weather for the next 7 days
/// @author Dylan Nasution
QVector<double> Weather::getFutureTemperatures() { return futureTemperature; }

/// @brief Gets the precipitation for the next 7 days
/// @return Array of the precipitation for the next 7 days
/// @author Dylan Nasution
QVector<double> Weather::getFuturePrecipitationChance() {
    return futurePrecipitationChance;
}

/// @brief Gets the humidity for the next 7 days
/// @return Array of the humidity for the next 7 days
/// @author Dylan Nasution
QVector<double> Weather::getFutureHumidities() { return futureHumidity; }

/// @brief Gets the conditions for the next 7 days
/// @return Array of the conditions for the next 7 days
/// @author Dylan Nasution
QVector<QString> Weather::getFutureConditions() { return futureConditions; }

/// @brief Gets the weather icons for the next 7 days
/// @return Array of the weather icons for the next 7 days
/// @author Dylan Nasution
QVector<QPixmap> Weather::getFutureIcons() { return futureIcon; }

/// @brief Gets the sunset times for the next 7 days
/// @return Array of the sunset times for the next 7 days
/// @author Dylan Nasution
QVector<QString> Weather::getFutureSunsets() { return futureSunset; }

/// @brief Gets the sunrise times for the next 7 days
/// @return Array of the sunrise times for the next 7 days
/// @author Dylan Nasution
QVector<QString> Weather::getFutureSunrises() { return futureSunrise; }

Weather::~Weather() {}