#include "dataFetcher.h"

/// @brief Fetches the current temperature from the json data
/// @returns the current temperature
/// @author Ryan Truong
double DataFetcher::fetchTemperature() {
    return round(data["current"].toObject()["temp"].toDouble());
}

/// @brief Fetches the current feel like temperature from the json data
/// @returns The feel like temperature
/// @author Ryan Truong
double DataFetcher::fetchFeelsLike() {
    return round(data["current"].toObject()["feels_like"].toDouble());
}

/// @brief Fetches the current conditions from the json data
/// @returns Conditions
/// @author Ryan Truong
QString DataFetcher::fetchConditions() {
    return capitalize(data["current"]
                          .toObject()["weather"]
                          .toArray()
                          .at(0)
                          .toObject()["description"]
                          .toString());
}

/// @brief Fetches the icon name from the json data
/// @returns The icon name
/// @author Ryan Truong
QPixmap DataFetcher::fetchCurrentIcon() {
    return fetchIcon(data["current"]
                         .toObject()["weather"]
                         .toArray()
                         .at(0)
                         .toObject()["icon"]
                         .toString());
}

/// @brief Fetches the current humidity from the json data
/// @returns The current humidity
/// @author Ryan Truong
double DataFetcher::fetchHumidity() {
    return data["current"].toObject()["humidity"].toDouble();
}

/// @brief Fetches the days sunrise time from the json data
/// @returns The sunrise time
/// @author Ryan Truong
QString DataFetcher::fetchSunrise() {
    return formatTime(data["current"].toObject()["sunrise"].toInt());
}

/// @brief Fetches the days sunset time from the json data
/// @returns The sunset time
/// @author Ryan Truong
QString DataFetcher::fetchSunset() {
    return formatTime(data["current"].toObject()["sunset"].toInt());
}