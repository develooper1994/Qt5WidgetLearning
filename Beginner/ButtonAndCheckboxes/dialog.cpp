#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    Page6Connection();
}

Dialog::~Dialog()
{
    delete ui;
}
