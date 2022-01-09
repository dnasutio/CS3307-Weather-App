#ifndef WEATHER_H
#define WEATHER_H

#include <QPixmap>
#include <QString>
#include <QVector>
#include <ctime>

#include "DataFetcher/dataFetcher.h"

/// @brief Class to keep track of current, future, and hourly weather
/// @author Ryan Truong, Dylan Nasution
class Weather {
   private:
    QString timeLastUpdated;

    // for the current time of day
    double currTemperature;
    double feelsLike;
    double currHumidity;
    QString currConditions;
    QPixmap currIcon;

    // for 48 hours from current time of day and for the next 7 days not
    // including today
    QVector<time_t> day;
    QVector<QString> hour;
    QVector<double> futureTemperature, hourlyTemperature;
    QVector<double> futurePrecipitationChance, hourlyPrecipitationChance;
    QVector<double> futureHumidity, hourlyHumidity;
    QVector<QString> futureSunrise, futureSunset;
    QVector<QString> futureConditions, hourlyConditions;
    QVector<QPixmap> futureIcon, hourlyIcon;

    QString location;
    QString sunset;
    QString sunrise;
    DataFetcher *fetcher;

   public:
    Weather();
    ~Weather();

    bool updateWeather(QString location);
    QString getLocation();
    void fetchAll();
    QString getTimeLastUpdated();

    // for current time of day
    double getCurrTemperature();
    double getFeelsLike();
    double getCurrHumidity();
    QString getCurrConditions();
    QPixmap getCurrIcon();
    QString getSunset();
    QString getSunrise();

    // for 48 hours from current time of day
    QVector<QString> getHours();
    QVector<double> getHourlyTemperatures();
    QVector<double> getHourlyPrecipitations();
    QVector<double> getHourlyHumidities();
    QVector<QString> getHourlyConditions();
    QVector<QPixmap> getHourlyIcons();

    // for the next 7 days not including today
    QVector<time_t> getDays();
    QVector<double> getFutureTemperatures();
    QVector<double> getFuturePrecipitationChance();
    QVector<double> getFutureHumidities();
    QVector<QString> getFutureConditions();
    QVector<QPixmap> getFutureIcons();
    QVector<QString> getFutureSunsets();
    QVector<QString> getFutureSunrises();
};

#endif