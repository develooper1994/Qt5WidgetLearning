#include "dialog.h"
#include "./ui_dialog.h"

#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnAccept_clicked()
{
    QMessageBox::information(this, "qwert", "What are you doing in here? " + ui->lineEdit->text());

    /*
    this->accept();
    this->close();
    */
}

