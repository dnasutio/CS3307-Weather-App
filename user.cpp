#include "user.h"

User::User() {}

/// @brief Sets the location
/// @param location New location
/// @returns True if the weather for the given location exists, else false.
/// @author Dylan Nasution
bool User::setLocation(QString location) {
    this->location = location;
    if (currentWeather->updateWeather(location))
        return true;
    else
        return false;
}

/// @brief Initializes the weather object
/// @author Dylan Nasution
void User::setCurrentWeather() { currentWeather = new Weather(); }

/// @brief Gets weather object
/// @author Dylan Nasution
Weather* User::getCurrentWeather() { return currentWeather; }

/// @brief Gets location of user
/// @author Dylan Nasution
QString User::getLocation() { return location; }

User::~User() {}