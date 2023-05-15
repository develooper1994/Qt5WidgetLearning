#include "dialog.h"

#include <QApplication>
#include "utilities.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    applyStyle(a);
    Dialog w;
    w.show();
    return a.exec();
}
