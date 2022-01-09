#include "guiCard.h"

/// @brief Sets the temperature label of the card
/// @param temperature The temperature for the card
/// @author Ryan Truong
void GUICard::setTemperature(QString temperature) {
    this->temperature->setText(temperature);
}

/// @brief Sets the condition label of the card
/// @param conditions The condition for the card
/// @author Ryan Truong
void GUICard::setConditions(QString conditions) {
    this->conditions->setText(conditions);
}

/// @brief Sets the icon of the card
/// @param conditions The icon for the card
/// @author Ryan Truong
void GUICard::setIcon(QPixmap icon) { this->icon->setPixmap(icon); }

/// @brief Sets the icon of the card
/// @param conditions The icon for the card
/// @author Ryan Truong
void GUICard::setPrecipitation(QString precipitation) {
    this->precipitation->setText(precipitation);
}

/// @brief Sets the humidity of the card
/// @param conditions The humidity for the card
/// @author Ryan Truong
void GUICard::setHumidity(QString humidity) {
    this->humidity->setText(humidity);
}

/// @brief Adds all components to card layout
/// @author Ryan Truong
void GUICard::display() {
    layout->addWidget(temperature);
    layout->addWidget(icon);
    layout->addWidget(conditions);
    layout->addWidget(precipitation);
    layout->addWidget(humidity);
}
