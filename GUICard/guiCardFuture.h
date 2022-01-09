#ifndef GUICARDFUTURE_H
#define GUICARDFUTURE_H

#include <QHBoxLayout>

#include "guiCard.h"

/// @brief Class to display future temperatures
/// @author Ryan Truong
class GUICardFuture : public GUICard {
   private:
    const QString days[7] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};

    QHBoxLayout *sunTimes;
    QLabel *day, *date, *sunrise, *sunset;

   public:
    GUICardFuture();
    ~GUICardFuture();

    void setDay(time_t timestamp);
    void setSunrise(QString sunrise);
    void setSunset(QString sunset);

    void display() override;
};

#endif
