#include "utilities.h"

#include <QDebug>
#include <QFile>

bool ayniSecim(QStringView hatIdOld, QStringView calismaTuruOld, QStringView hatIdNew, QStringView calismaTuruNew){
    return hatIdOld == hatIdNew && calismaTuruOld == calismaTuruNew;
}

QString loadStyle(){
    QString filename(":/style/style.qss");
    QFile file(filename);
    if(!file.open(QFile::ReadOnly)){
        qFatal("style cannot open");
        //exit(EXIT_FAILURE);
    }
    QString stylesheet(file.readAll());
    return stylesheet;
}

void applyStyle(QApplication& app){
    app.setStyleSheet(loadStyle());
    //app.setStyleSheet("QComboBox { combobox-popup: 0; }");
    //app.setFont(QFont("Arial", 10));
}
