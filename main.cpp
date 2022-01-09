#include <QApplication>

#include "GUI/GUI.h"

int main(int argc, char *argv[]) {
    // opens GUI
    QApplication app(argc, argv);
    GUI mainWindow;
    mainWindow.showNormal();

    return app.exec();
}