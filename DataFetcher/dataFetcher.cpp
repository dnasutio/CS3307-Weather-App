#include "dataFetcher.h"

/// @brief Constructor of the class takes in a string as the default location
/// @param location Initial location to display on startup
/// @author Ryan Truong
DataFetcher::DataFetcher(QString location) {
    this->location = location;
    manager = new QNetworkAccessManager();

    loop.connect(manager, &QNetworkAccessManager::finished, &loop,
                 &QEventLoop::quit);

    callAPI();
}

/// @brief Sets the new location
/// @param location New location
/// @author Ryan Truong
void DataFetcher::setLocation(QString location) { this->location = location; }

/// @brief Gets the weather data using the weather API given a latitude and
/// longitude
/// @param lat Latitude of the location
/// @param lon Longitude of the location
/// @author Ryan Truong
void DataFetcher::callAPI(QString lat, QString lon) {
    QNetworkReply *reply = manager->get(
        QNetworkRequest(QUrl("https://api.openweathermap.org/data/2.5/"
                             "onecall?units=metric&exclude=minutely&lat=" +
                             lat + "&lon=" + lon + "&appid=" + APIKey)));

    loop.exec();

    QString data = reply->readAll();
    this->data = QJsonDocument::fromJson(data.toUtf8()).object();

    reply->deleteLater();

    time_t currentTime;
    time(&currentTime);
    this->lastUpdated = formatTime(currentTime);
}

/// @brief Returns the time the callAPI method was called
/// @author Stuart Fong
QString DataFetcher::getLastUpdated() { return this->lastUpdated; }

/// @brief Fetches the latitude and longitude from a given location
/// @param location The address for which you want to get the latitude and
/// longitude
/// @returns Array consisting of 4 elements.  The first two is the latitude and
/// longitude respectively.  The third is the full name of the location entered.
/// The fourth is a execution code, 0 being location not found, and 1 being ok.
/// @author Stuart Fong
QJsonArray DataFetcher::fetchLatLon(QString location) {
    QNetworkReply *reply = manager->get(QNetworkRequest(
        QUrl("https://maps.googleapis.com/maps/api/geocode/json?address=" +
             location + "&key=AIzaSyDv9UdPp-A_s_aOBmUhBRAylcQyvnFuRms")));

    loop.exec();

    QString data = reply->readAll();

    QJsonObject fetchedLocation =
        QJsonDocument::fromJson(data.toUtf8()).object();

    QJsonArray latLon = {0, 0, "There are no results for this location", 0};

    QJsonArray results = fetchedLocation["results"].toArray();

    if (results.isEmpty()) return latLon;

    QJsonObject northeastLatLon = results.at(0)
                                      .toObject()["geometry"]
                                      .toObject()["bounds"]
                                      .toObject()["northeast"]
                                      .toObject();

    latLon.replace(0, QString::number(northeastLatLon["lat"].toDouble()));
    latLon.replace(1, QString::number(northeastLatLon["lng"].toDouble()));
    latLon.replace(2, results.at(0).toObject()["formatted_address"]);
    latLon.replace(3, 1);

    reply->deleteLater();

    return latLon;
}

/// @brief Formats a timestamp into 12 hour time
/// @param timestamp Timestamp to convert
/// @returns Formatted time in 12 hour time
/// @author Ryan Truong
QString DataFetcher::formatTime(time_t timestamp) {
    tm *ltm = localtime(&timestamp);
    QString suffix = " am";

    int hour = ltm->tm_hour;

    if (hour == 0)
        hour = 12;
    else if (hour > 12) {
        hour -= 12;
        suffix = " pm";
    }

    if (ltm->tm_min < 10)
        return QString::number(hour) + ":0" + QString::number(ltm->tm_min) +
               suffix;

    return QString::number(hour) + ":" + QString::number(ltm->tm_min) + suffix;
}

/// @brief Capitilizes the first letter of a string
/// @param timestamp String to capitilize
/// @returns Capitilized string
/// @author Ryan Truong
QString DataFetcher::capitalize(QString str) {
    str[0] = str[0].toUpper();
    return str;
}

/// @brief Fetches an icon from the weather API from a given icon name
/// @param iconName Name of icon
/// @returns QPixmap of icon
/// @author Ryan Truong
QPixmap DataFetcher::fetchIcon(QString iconName) {
    QDir dir("cache");

    if (!dir.exists()) dir.mkpath("cache");

    QString filename = "cache/" + iconName + "@4x.png";

    if (!QFile::exists(filename)) {
        QNetworkRequest request(
            QUrl("http://openweathermap.org/img/wn/" + iconName + "@4x.png"));
        QNetworkReply *reply = manager->get(request);

        loop.exec();

        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        file.write(reply->readAll());

        file.close();

        reply->deleteLater();
    }

    QPixmap icon(filename);

    return icon;
}

DataFetcher::~DataFetcher() {}