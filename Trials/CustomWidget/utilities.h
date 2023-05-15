#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <QApplication>


// utilities
bool ayniSecim(QStringView hatIdOld, QStringView calismaTuruOld, QStringView hatIdNew, QStringView calismaTuruNew);
QString loadStyle();
void applyStyle(QApplication& app);


#endif // UTILITIES_H
