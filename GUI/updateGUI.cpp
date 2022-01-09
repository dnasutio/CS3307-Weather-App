#include "GUI.h"

/// @brief Sets the current time
/// @author Dylan Nasution, Ryan Truong
void GUI::timerEvent(QTimerEvent *event) {
    timeLabel->setText(
        QDateTime::currentDateTime().toString("dddd, MMMM dd, h:mm ap"));
}

/// @brief Sets the location of the user
/// @author Dylan Nasution, Ryan Truong
void GUI::setUserLocation() {
    timeLastUpdatedLabel->setText("Updating...");
    if (user->setLocation(locationSelector->text()))
        update();
    else {
        timeLastUpdatedLabel->setText("Last updated at " +
                                      weather->getTimeLastUpdated());
        errorMessage->exec();
    }
}

/// @brief Updates the boxes after a data change
/// @author Dylan Nasution, Ryan Truong
void GUI::update() {
    updateCurrentBox();
    updateHourlyBox();
    updateWeekBox();

    timeLastUpdatedLabel->setText("Last updated at " +
                                  weather->getTimeLastUpdated());
}

/// @brief Updates the current box labels, and icons
/// @author Dylan Nasution, Ryan Truong
void GUI::updateCurrentBox() {
    locationLabel->setText(weather->getLocation());
    temperatureLabel->setText(QString::number(weather->getCurrTemperature()) +
                              "°C");
    feelsLikeLabel->setText(
        "Feels like: " + QString::number(weather->getFeelsLike()) + "°C");
    conditionsLabel->setText(weather->getCurrConditions());
    iconLabel->setPixmap(weather->getCurrIcon().scaled(400, 400));
    sunriseLabel->setText("Sunrise: " + weather->getSunrise());
    sunsetLabel->setText("Sunset: " + weather->getSunset());
    humidityLabel->setText(
        "Humidity: " + QString::number(weather->getCurrHumidity()) + "%");
}

/// @brief Updates the hourly box labels, and icons
/// @author Dylan Nasution, Ryan Truong
void GUI::updateHourlyBox() {
    QVector<QString> hour = weather->getHours();
    QVector<double> temp = weather->getHourlyTemperatures();
    QVector<QString> conditions = weather->getHourlyConditions();
    QVector<QPixmap> icon = weather->getHourlyIcons();
    QVector<double> pop = weather->getHourlyPrecipitations();
    QVector<double> humidity = weather->getHourlyHumidities();

    for (int i = 0; i < 48; i++) {
        hourlyCard[i]->setHour(hour[i]);
        hourlyCard[i]->setTemperature(QString::number(temp[i]) + "°C");
        hourlyCard[i]->setConditions(conditions[i]);
        hourlyCard[i]->setIcon(icon[i]);
        hourlyCard[i]->setPrecipitation("POP: " + QString::number(pop[i]) +
                                        "%");
        hourlyCard[i]->setHumidity("Humidity: " + QString::number(humidity[i]) +
                                   "%");
    }
}

/// @brief Updates the week box labels, and icons
/// @author Dylan Nasution, Ryan Truong
void GUI::updateWeekBox() {
    QVector<time_t> day = weather->getDays();
    QVector<double> temp = weather->getFutureTemperatures();
    QVector<double> pop = weather->getFuturePrecipitationChance();
    QVector<double> humidity = weather->getFutureHumidities();
    QVector<QString> conditions = weather->getFutureConditions();
    QVector<QPixmap> icon = weather->getFutureIcons();
    QVector<QString> sunrise = weather->getFutureSunrises();
    QVector<QString> sunset = weather->getFutureSunsets();

    for (int i = 0; i < 7; i++) {
        futureCard[i]->setDay(day[i]);
        futureCard[i]->setTemperature(QString::number(temp[i]) + "°C");
        futureCard[i]->setConditions(conditions[i]);
        futureCard[i]->setIcon(icon[i]);
        futureCard[i]->setPrecipitation("POP: " + QString::number(pop[i]) +
                                        "%");
        futureCard[i]->setHumidity("Humidity: " + QString::number(humidity[i]) +
                                   "%");
        futureCard[i]->setSunrise(sunrise[i]);
        futureCard[i]->setSunset(sunset[i]);
    }
}
