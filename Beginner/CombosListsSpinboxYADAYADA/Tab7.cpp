#include "dialog.h"

void Dialog::init_TAB7(){
    ui->dte->setDateTime(QDateTime::currentDateTime());
}

void Dialog::load_TAB7(){

}

void Dialog::save_TAB7(){

}



// slots
void Dialog::on_de_userDateChanged(const QDate &date){
    ui->dte->setDate(date);
}


void Dialog::on_te_userTimeChanged(const QTime &time){
    ui->dte->setTime(time);
}


void Dialog::on_btnBoxDateAndTime_accepted(){
    QMessageBox::information(this, "Selected", "You Selected: " + ui->dte->dateTime().toLocalTime().toString());
    accept();
}


void Dialog::on_btnBoxDateAndTime_rejected(){
    reject();
}
