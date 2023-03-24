#include "dialog.h"
#include "qmetaobject.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Tab 1
    init_TAB1();
    load_TAB1();
    // Tab 2
    init_TAB2();
    load_TAB2();
    // Tab 3
    init_TAB3();
    load_TAB3();
    // Tab 4
    init_TAB4();
    load_TAB4();
    // Tab 5
}

Dialog::~Dialog(){
    delete ui;
}

