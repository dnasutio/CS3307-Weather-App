#include "guiCardFuture.h"

/// @brief Resets values of card
/// @author Ryan Truong
GUICardFuture::GUICardFuture() {
    layout = new QVBoxLayout(this);
    sunTimes = new QHBoxLayout();
    day = new QLabel("");
    date = new QLabel("");
    temperature = new QLabel("");
    conditions = new QLabel("");
    icon = new QLabel("");
    precipitation = new QLabel("");
    humidity = new QLabel("");
    sunrise = new QLabel("");
    sunset = new QLabel("");
}

/// @brief Sets the day of the card
/// @author Ryan Truong
void GUICardFuture::setDay(time_t timestamp) {
    tm *ltm = localtime(&timestamp);

    QString day = days[ltm->tm_wday];
    QString date =
        QString::number(ltm->tm_mon + 1) + "/" + QString::number(ltm->tm_mday);

    this->day->setText(day);
    this->date->setText(date);
}

/// @brief Sets the sunrise of the card
/// @author Ryan Truong
void GUICardFuture::setSunrise(QString sunrise) {
    this->sunrise->setText(sunrise);
}

/// @brief Sets the sunset of the card
/// @author Ryan Truong
void GUICardFuture::setSunset(QString sunset) { this->sunset->setText(sunset); }

/// @brief Adds all the components to the layout of the card and displays
/// @author Ryan Truong
void GUICardFuture::display() {
    layout->addWidget(day);
    layout->addWidget(date);

    GUICard::display();

    sunTimes->addWidget(sunrise);
    sunTimes->addWidget(sunset);
    layout->addLayout(sunTimes);

    this->show();
}

GUICardFuture::~GUICardFuture() {}
