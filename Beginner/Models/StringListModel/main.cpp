#include "dialog.h"

#include <QApplication>

// resource:
// https://github.com/voidrealms/qtwb-10-2

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
