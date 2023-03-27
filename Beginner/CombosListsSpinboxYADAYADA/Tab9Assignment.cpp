#include "dialog.h"

void Dialog::init_TAB9(){
    ui->dteHire->setDateTime(QDateTime::currentDateTime());
}

void Dialog::on_btnBoxAssignment_accepted(){
    QString msg;
    msg.append("Name: " + ui->txtName->text() + "\n");
    msg.append("Name: " + ui->txtTitle->text() + "\n");
    msg.append("Name: " + ui->dteHire->dateTime().toLocalTime().toString() + "\n");

    QMessageBox::information(this, "Info", msg);
    accept();
}
