#ifndef GUICARDHOURLY_H
#define GUICARDHOURLY_H

#include "guiCard.h"

/// @brief Class to display hourly temperatures
/// @author Ryan Truong
class GUICardHourly : public GUICard {
   private:
    QLabel *hour;

   public:
    GUICardHourly();
    ~GUICardHourly();

    void setHour(QString hour);

    void display() override;
};

#endif
