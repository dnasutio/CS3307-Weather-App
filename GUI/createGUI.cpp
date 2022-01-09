#include "GUI.h"

/// @brief Initializes User, GUICards and sets up the layout
/// @author Dylan Nasution, Ryan Truong
GUI::GUI() {
    // initalize user and weather
    user = new User();
    user->setCurrentWeather();
    weather = user->getCurrentWeather();
    startTimer(1000);

    // initialize cards in QVectors
    for (int i = 0; i < 48; i++) hourlyCard.append(new GUICardHourly());
    for (int i = 0; i < 7; i++) futureCard.append(new GUICardFuture());

    // call functions to create GUI
    createSearchBox();

    // time display for the current day
    timeLabel = new QLabel(
        QDateTime::currentDateTime().toString("dddd, MMMM dd, h:mm ap"));
    QFont timeFont = timeLabel->font();
    timeFont.setPixelSize(20);
    timeLabel->setFont(timeFont);
    // timeLabel->setAlignment(Qt::AlignCenter);

    createCurrentBox();
    createHourlyBox();
    createWeekBox();
    createFooterBox();

    // add sections to the layout
    errorMessage = new QMessageBox();
    errorMessage->setText("Invalid location");
    errorMessage->setIcon(QMessageBox::Warning);

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(searchBox);
    mainLayout->addWidget(timeLabel);
    mainLayout->addWidget(currentBox);
    mainLayout->addWidget(hourlyBox);
    mainLayout->addWidget(weekBox);
    mainLayout->addWidget(footerBox);

    // set the background colour
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor("#03c2fc"));
    setAutoFillBackground(true);
    setPalette(pal);

    setLayout(mainLayout);

    setWindowTitle("WeatherApp");
}

/// @brief Initializes the search box
/// @author Dylan Nasution, Ryan Truong
void GUI::createSearchBox() {
    searchBox = new QWidget();
    searchLayout = new QVBoxLayout();

    locationSelector = new QLineEdit();
    locationSelector->setPlaceholderText("Enter a location");
    connect(locationSelector, &QLineEdit::returnPressed, this,
            &GUI::setUserLocation);

    googleLabel = new QLabel();
    googleLabel->setPixmap(QPixmap("google.png"));
    googleLabel->setAlignment(Qt::AlignRight);

    searchLayout->addWidget(locationSelector);
    searchLayout->addWidget(googleLabel);
    searchBox->setLayout(searchLayout);
}

/// @brief Initializes current layout
/// @author Dylan Nasution, Ryan Truong
void GUI::createCurrentBox() {
    currentBox = new QWidget();
    currentLayout = new QGridLayout();

    locationLabel = new QLabel();

    temperatureLabel = new QLabel();
    QFont temperatureFont = temperatureLabel->font();
    temperatureFont.setPixelSize(50);
    temperatureLabel->setFont(temperatureFont);

    feelsLikeLabel = new QLabel();
    conditionsLabel = new QLabel();
    iconLabel = new QLabel();
    sunriseLabel = new QLabel();
    sunsetLabel = new QLabel();
    humidityLabel = new QLabel();

    updateCurrentBox();

    currentLayout->addWidget(locationLabel, 0, 0);
    currentLayout->addWidget(temperatureLabel, 1, 0);
    currentLayout->addWidget(feelsLikeLabel, 2, 0);
    currentLayout->addWidget(conditionsLabel, 0, 1);
    currentLayout->addWidget(iconLabel, 1, 1, 4, 1);
    currentLayout->addWidget(sunriseLabel, 0, 2);
    currentLayout->addWidget(sunsetLabel, 1, 2);
    currentLayout->addWidget(humidityLabel, 2, 2);

    currentBox->setLayout(currentLayout);
}

/// @brief Initializes hourly layout
/// @author Dylan Nasution, Ryan Truong
void GUI::createHourlyBox() {
    hourlyBox = new QScrollArea();

    scrollWidget = new QWidget();
    hourlyLayout = new QHBoxLayout(scrollWidget);

    updateHourlyBox();

    for (int i = 0; i < 48; i++) {
        GUICardHourly *newHourlyCard = hourlyCard[i];
        newHourlyCard->display();
        hourlyLayout->addWidget(newHourlyCard);
    }

    hourlyBox->setFixedHeight(hourlyCard[0]->height() + 30);
    hourlyBox->setWidget(scrollWidget);
    hourlyBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    hourlyBox->verticalScrollBar()->setEnabled(false);
    hourlyBox->horizontalScrollBar()->setStyleSheet(
        "QScrollBar:horizontal { background: #03c2fc; }");
}

/// @brief Initializes week layout
/// @author Dylan Nasution, Ryan Truong
void GUI::createWeekBox() {
    weekBox = new QWidget();
    weekLayout = new QHBoxLayout();

    updateWeekBox();

    for (int i = 0; i < 7; i++) {
        GUICardFuture *newFutureCard = futureCard[i];
        newFutureCard->display();
        weekLayout->addWidget(newFutureCard);
    }

    weekBox->setLayout(weekLayout);
}

void GUI::createFooterBox() {
    footerBox = new QWidget();
    footerLayout = new QHBoxLayout();

    timeLastUpdatedLabel =
        new QLabel("Last updated at " + weather->getTimeLastUpdated());

    creditsLabel = new QLabel(credits);
    creditsLabel->setAlignment(Qt::AlignRight);

    footerLayout->addWidget(timeLastUpdatedLabel);
    footerLayout->addWidget(creditsLabel);
    footerBox->setLayout(footerLayout);
}

GUI::~GUI() {}
