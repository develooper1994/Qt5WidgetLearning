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



void Dialog::on_pushButton_clicked(){
    Selections* selections = new Selections(this);
    //set default
    selections->setSelected(ui->lineEdit->text());
    //show on screen and focus on
    selections->exec();
    //Read back to new selections
    ui->lineEdit->setText(selections->selected());
}


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this, "Selected", "Selected Item: " + ui->lineEdit->text());
    accept();
}


void Dialog::on_buttonBox_rejected(){
    reject();
}

