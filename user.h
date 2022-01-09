#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>

#include "weather.h"

/// @brief Class to keep track of user location and other personal data
/// @author Dylan Nasution
class User {
   private:
    QString location;
    Weather* currentWeather;

   public:
    User();
    ~User();

    bool setLocation(QString selection);
    void setCurrentWeather();
    Weather* getCurrentWeather();
    QString getLocation();
};

#endif