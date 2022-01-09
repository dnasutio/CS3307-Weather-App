#ifndef DATAFETCHER_H
#define DATAFETCHER_H

#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPixmap>
#include <QString>
#include <QVector>
#include <cmath>
#include <ctime>

/// @brief Class to fetch and process data from a weather API
/// @author Stuart Fong, Ryan Truong
class DataFetcher : QObject {
   private:
    const QString APIKey = "e7effe6f2ed2a1c90d50360e892f2673";

    QEventLoop loop;
    QNetworkAccessManager *manager;
    QJsonObject data;
    QString location;
    QString lastUpdated;

   public:
    
    DataFetcher(QString location = "");
    ~DataFetcher();

    void setLocation(QString location);
    void callAPI(QString lat = "42.983391", QString lon = "-81.23304");
    QString getLastUpdated();
    QString formatTime(time_t timestamp);
    QString capitalize(QString str);
    QPixmap fetchIcon(QString iconName);

    double fetchTemperature();
    double fetchFeelsLike();
    QString fetchConditions();
    QPixmap fetchCurrentIcon();
    double fetchHumidity();
    QString fetchSunrise();
    QString fetchSunset();
    QJsonArray fetchLatLon(QString location);

    QVector<time_t> fetchDays();
    QVector<double> fetchFutureTemperatures();
    QVector<QString> fetchFutureConditions();
    QVector<QPixmap> fetchFutureIcons();
    QVector<double> fetchFuturePreciptations();
    QVector<double> fetchFutureHumidities();
    QVector<QString> fetchFutureSunrises();
    QVector<QString> fetchFutureSunsets();

    QVector<QString> fetchHours();
    QVector<double> fetchHourlyTemperatures();
    QVector<QString> fetchHourlyConditions();
    QVector<QPixmap> fetchHourlyIcons();
    QVector<double> fetchHourlyPrecipitations();
    QVector<double> fetchHourlyHumidities();
};

#endif