#include "dialog.h"


void Dialog::init_tab4(){
    MyLib mylib;
    ui->lineEdit->setText(mylib.message());

    QPixmap map(":/files/images/accept.png");
    ui->label->setPixmap(map);
}


// slots
void Dialog::on_buttonBox_accepted(){
    accept();
}
