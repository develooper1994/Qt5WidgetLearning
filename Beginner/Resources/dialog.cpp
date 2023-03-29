#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //Tab1
    init();
    load();
    //Tab2

}

Dialog::~Dialog()
{
    delete ui;
}

