#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog(){
    delete ui;
}


// slots
void Dialog::on_btnScreen_clicked(){

}


void Dialog::on_btnSave_clicked(){

}

void Dialog::shoot(){

}

