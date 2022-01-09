#include "dataFetcher.h"

/// @brief Fetches the next 7 days timestamp from the json data
/// @returns An array of timestamps of the next 7 days
/// @author Stuart Fong
QVector<time_t> DataFetcher::fetchDays() {
    QVector<time_t> days;

    QJsonArray future = data["daily"].toArray();
    // Skips over the first element since the API includes the current day in
    // the daily array.
    for (int i = 1; i < future.size(); i++) {
        QJsonObject day = future.at(i).toObject();
        days.append(day["dt"].toInt());
    }

    return days;
}

/// @brief Fetches the daily temperatures for the next 7 days from the json data
/// @returns An array of the temperatures for next 7 days
/// @author Stuart Fong
QVector<double> DataFetcher::fetchFutureTemperatures() {
    QVector<double> futureTemps;

    QJsonArray future = data["daily"].toArray();
    // Skips over the first element since the API includes the current day in
    // the daily array.
    for (int i = 1; i < future.size(); i++) {
        QJsonObject day = future.at(i).toObject();
        QJsonObject temperature = day["temp"].toObject();
        futureTemps.append(round(temperature["day"].toDouble()));
    }

    return futureTemps;
}

/// @brief Fetches the conditions for the next 7 days from the json data
/// @returns An array of the conditions for next 7 days
/// @author Stuart Fong
QVector<QString> DataFetcher::fetchFutureConditions() {
    QVector<QString> futureConditions;

    QJsonArray future = data["daily"].toArray();

    for (int i = 1; i < future.size(); i++) {
        QJsonObject day = future.at(i).toObject();
        QJsonObject weather = day["weather"].toArray().at(0).toObject();
        futureConditions.append(capitalize(weather["description"].toString()));
    }

    return futureConditions;
}

/// @brief Fetches the icons for the next 7 days from the json data
/// @returns An array of the icons for next 7 days
/// @author Stuart Fong
QVector<QPixmap> DataFetcher::fetchFutureIcons() {
    QVector<QPixmap> futureIcons;

    QJsonArray future = data["daily"].toArray();

    for (int i = 1; i < future.size(); i++) {
        QJsonObject day = future.at(i).toObject();
        QJsonObject weather = day["weather"].toArray().at(0).toObject();
        futureIcons.append(fetchIcon(weather["icon"].toString()));
    }

    return futureIcons;
}
/// @brief Fetches the precipitations for the next 7 days from the json data
/// @returns An array of the precipitations for next 7 days
/// @author Stuart Fong
QVector<double> DataFetcher::fetchFuturePreciptations() {
    QVector<double> futurePrecip;

    QJsonArray future = data["daily"].toArray();
    // Skips over the first element since the API includes the current day in
    // the daily array.
    for (int i = 1; i < future.size(); i++) {
        QJsonObject day = future.at(i).toObject();
        futurePrecip.append(day["pop"].toDouble() * 100);
    }

    return futurePrecip;
}

/// @brief Fetches the humidity for the next 7 days from the json data
/// @returns An array of the humidity for next 7 days
/// @author Stuart Fong
QVector<double> DataFetcher::fetchFutureHumidities() {
    QVector<double> futureHumidity;

    QJsonArray future = data["daily"].toArray();
    // Skips over the first element since the API includes the current day in
    // the daily array.
    for (int i = 1; i < future.size(); i++) {
        QJsonObject day = future.at(i).toObject();
        futureHumidity.append(day["humidity"].toDouble());
    }

    return futureHumidity;
}

/// @brief Fetches the sunrise times for the next 7 days from the json data
/// @returns An array of the sun rise times for next 7 days
/// @author Stuart Fong
QVector<QString> DataFetcher::fetchFutureSunrises() {
    QVector<QString> futureSunrise;

    QJsonArray future = data["daily"].toArray();
    // Skips over the first element since the API includes the current day in
    // the daily array.
    for (int i = 1; i < future.size(); i++) {
        QJsonObject day = future.at(i).toObject();
        futureSunrise.append(formatTime(day["sunrise"].toInt()));
    }

    return futureSunrise;
}

/// @brief Fetches the sunset times for the next 7 days from the json data
/// @returns An array of the sunset times for next 7 days
/// @author Stuart Fong
QVector<QString> DataFetcher::fetchFutureSunsets() {
    QVector<QString> futureSunset;

    QJsonArray future = data["daily"].toArray();
    // Skips over the first element since the API includes the current day in
    // the daily array.
    for (int i = 1; i < future.size(); i++) {
        QJsonObject day = future.at(i).toObject();
        futureSunset.append(formatTime(day["sunset"].toInt()));
    }

    return futureSunset;
}
