QT       += core widgets network
TARGET = WeatherApp
TEMPLATE = app 
SOURCES +=  main.cpp \
            DataFetcher/dataFetcher.cpp DataFetcher/dataFetcherCurrent.cpp DataFetcher/dataFetcherFuture.cpp DataFetcher/dataFetcherHourly.cpp \
            GUI/createGUI.cpp GUI/updateGUI.cpp \
            weather.cpp user.cpp \
            GUICard/guiCard.cpp GUICard/guiCardFuture.cpp GUICard/guiCardHourly.cpp
HEADERS +=  DataFetcher/dataFetcher.h \
            GUI/GUI.h \
            weather.h user.h \
            GUICard/guiCard.h GUICard/guiCardFuture.h GUICard/guiCardHourly.h