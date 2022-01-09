#ifndef GUI_H
#define GUI_H

#include <QDateTime>
#include <QErrorMessage>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QScrollArea>
#include <QScrollBar>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QWidget>

#include "../GUICard/guiCard.h"
#include "../GUICard/guiCardFuture.h"
#include "../GUICard/guiCardHourly.h"
#include "../user.h"

/// @brief Class to display current, future, and hourly weather
/// @author Ryan Truong, Dylan Nasution
class GUI : public QWidget {
    Q_OBJECT

   private:
    const QString credits = "Weather updated from OpenWeather (TM)";

    User *user;
    Weather *weather;
    QTimer *timer;

    QVBoxLayout *mainLayout;
    QGridLayout *currentLayout;
    QVBoxLayout *searchLayout;
    QHBoxLayout *hourlyLayout, *weekLayout, *footerLayout;

    QWidget *searchBox, *currentBox, *weekBox, *footerBox;
    QScrollArea *hourlyBox;
    QWidget *scrollWidget;

    QLabel *googleLabel, *locationLabel, *temperatureLabel, *feelsLikeLabel,
        *conditionsLabel, *iconLabel, *sunriseLabel, *sunsetLabel,
        *humidityLabel;
    QLabel *timeLabel, *timeLastUpdatedLabel;
    QLabel *creditsLabel;

    QLineEdit *locationSelector;

    QVector<GUICardHourly *> hourlyCard;
    QVector<GUICardFuture *> futureCard;
    QVector<QLabel *> weekLabel, hourlyLabel;

    QMessageBox *errorMessage;

    void createSearchBox();
    void createCurrentBox();
    void createWeekBox();
    void createHourlyBox();
    void createFooterBox();

    void update();
    void updateCurrentBox();
    void updateWeekBox();
    void updateHourlyBox();

   protected:
    void timerEvent(QTimerEvent *event);

   public:
    GUI();
    ~GUI();

   public slots:
    void setUserLocation();
};

#endif  // GUI_H