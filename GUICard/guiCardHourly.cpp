#include "guiCardHourly.h"

/// @brief Resets values of the card
/// @author Ryan Truong
GUICardHourly::GUICardHourly() {
    layout = new QVBoxLayout(this);
    hour = new QLabel("");
    temperature = new QLabel("");
    conditions = new QLabel("");
    icon = new QLabel("");
    precipitation = new QLabel("");
    humidity = new QLabel("");
}

/// @brief Sets the hour of the card
/// @author Ryan Truong
void GUICardHourly::setHour(QString hour) { this->hour->setText(hour); }

/// @brief Adds all the components to the card and displays
/// @author Ryan Truong
void GUICardHourly::display() {
    layout->addWidget(hour);

    GUICard::display();

    this->show();
}

GUICardHourly::~GUICardHourly() {}
