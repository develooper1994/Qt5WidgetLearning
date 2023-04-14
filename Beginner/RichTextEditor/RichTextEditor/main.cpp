#include "mainwindow.h"

#include <QApplication>

// resource:
// https://github.com/voidrealms/qtwb-9-10/tree/master
// https://github.com/voidrealms/qtwb-9-assign

// very very basic rich editor


void setup(QApplication& app){
    app.setOrganizationName("Home");
    app.setOrganizationDomain("https://www.youtube.com/channel/UCSOVO6gW85DOlHlTdDcuyVg");
    app.setApplicationName("Rich Text Editor");
    app.setApplicationDisplayName("Rich Text Editor with C++ and Qt 6 Widget");
    app.setApplicationVersion("0.2 Alpha");
}


int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    setup(app);

    MainWindow w;
    w.show();
    return app.exec();
}
