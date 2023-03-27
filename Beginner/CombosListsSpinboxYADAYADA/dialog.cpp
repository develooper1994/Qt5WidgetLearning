#include "dialog.h"

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
    init_TAB5();
    load_TAB5();
    // Tab 6
    init_TAB6();
    load_TAB6();
    // Tab 7
    init_TAB7();
    load_TAB7();
    // Tab 8
    init_TAB8();
    load_TAB8();
    // Tab 9 - Assignment
    init_TAB9();
}

Dialog::~Dialog(){
    delete ui;
}
