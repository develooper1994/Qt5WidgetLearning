#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Tab 1
    init();
    load();
    // Tab 2
}

Dialog::~Dialog()
{
    delete ui;
}

