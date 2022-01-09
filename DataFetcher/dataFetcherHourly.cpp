#include "dataFetcher.h"

/// @brief Fetches the next 48 hours from the json data
/// @returns An array of the next 48 hours
/// @author Ryan Truong
QVector<QString> DataFetcher::fetchHours() {
    QVector<QString> hours;

    QJsonArray future = data["hourly"].toArray();
    for (int i = 0; i < future.size(); i++) {
        QJsonObject hour = future.at(i).toObject();
        QString suffix = " am";
        time_t timestamp = hour["dt"].toInt();
        tm *ltm = localtime(&timestamp);

        int currHour = ltm->tm_hour;

        if (currHour == 0)
            currHour = 12;
        else if (currHour > 12) {
            currHour -= 12;
            suffix = " pm";
        }

        hours.append(QString::number(currHour) + suffix);
    }

    return hours;
}

/// @brief Fetches the temperature for the next 48 hours.
/// @returns An array full of the temperatures for the next 48 hours
/// @author Stuart Fong
QVector<double> DataFetcher::fetchHourlyTemperatures() {
    QVector<double> hourlyTemps;

    QJsonArray hourly = data["hourly"].toArray();
    for (int i = 0; i < hourly.size(); i++) {
        QJsonObject hour = hourly.at(i).toObject();
        hourlyTemps.append(round(hour["temp"].toDouble()));
    }

    return hourlyTemps;
}

/// @brief Fetches the condition for the next 48 hours.
/// @returns An array full of the conditions for the next 48 hours
/// @author Stuart Fong
QVector<QString> DataFetcher::fetchHourlyConditions() {
    QVector<QString> hourlyConditions;

    QJsonArray hourly = data["hourly"].toArray();

    for (int i = 0; i < hourly.size(); i++) {
        QJsonObject hour = hourly.at(i).toObject();
        QJsonObject weather = hour["weather"].toArray().at(0).toObject();
        hourlyConditions.append(capitalize(weather["description"].toString()));
    }

    return hourlyConditions;
}

/// @brief Fetches the weather icons for the next 48 hours.
/// @returns An array full of the weather icons for the next 48 hours
/// @author Stuart Fong
QVector<QPixmap> DataFetcher::fetchHourlyIcons() {
    QVector<QPixmap> hourlyIcons;

    QJsonArray hourly = data["hourly"].toArray();

    for (int i = 0; i < hourly.size(); i++) {
        QJsonObject hour = hourly.at(i).toObject();
        QJsonObject weather = hour["weather"].toArray().at(0).toObject();
        hourlyIcons.append(fetchIcon(weather["icon"].toString()));
    }

    return hourlyIcons;
}

/// @brief Fetches the precipitation for the next 48 hours.
/// @returns An array full of the precipitation for the next 48 hours
/// @author Stuart Fong
QVector<double> DataFetcher::fetchHourlyPrecipitations() {
    QVector<double> hourlyPrecip;

    QJsonArray hourly = data["hourly"].toArray();
    for (int i = 0; i < hourly.size(); i++) {
        QJsonObject hour = hourly.at(i).toObject();
        hourlyPrecip.append(hour["pop"].toDouble() * 100);
    }

    return hourlyPrecip;
}

/// @brief Fetches the humidity for the next 48 hours.
/// @returns An array full of the humidity for the next 48 hours
/// @author Stuart Fong
QVector<double> DataFetcher::fetchHourlyHumidities() {
    QVector<double> hourlyHumidity;

    QJsonArray hourly = data["hourly"].toArray();
    for (int i = 0; i < hourly.size(); i++) {
        QJsonObject hour = hourly.at(i).toObject();
        hourlyHumidity.append(hour["humidity"].toDouble());
    }

    return hourlyHumidity;
}
