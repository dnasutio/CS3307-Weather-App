#ifndef GUICARD_H
#define GUICARD_H

#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

/// @brief Class to display the hourly and future temperatures
/// @author Ryan Truong
class GUICard : public QWidget {
   protected:
    QVBoxLayout *layout;
    QLabel *icon, *temperature, *conditions, *precipitation, *humidity;

   public:
    void setTemperature(QString temperature);
    void setIcon(QPixmap icon);
    void setConditions(QString conditions);
    void setPrecipitation(QString precipitation);
    void setHumidity(QString humidity);

    virtual void display();
};

#endif
