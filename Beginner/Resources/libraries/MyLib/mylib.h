#ifndef MYLIB_H
#define MYLIB_H


#include <QtCore/qglobal.h>

#if defined(MYLIB_LIBRARY)
#  define MYLIB_EXPORT Q_DECL_EXPORT
#else
#  define MYLIB_EXPORT Q_DECL_IMPORT
#endif

#include <QString>
#include <QFile>
#include <QTextStream>

class MYLIB_EXPORT MyLib
{
public:
    MyLib();

    QString message();
    QString test();
};


#endif // MYLIB_H
