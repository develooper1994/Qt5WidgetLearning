
#include "dialog.h"
#include "./ui_dialog.h"


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


// slots
void Dialog::on_btnWith_clicked(){
    Dialog2* dialog2 = new Dialog2(this);
    //Dialog2 dialog2;  // creates and destroys when out of scope! Not even works with exec!
    dialog2->exec(); // !focus on this window!
}


void Dialog::on_btnWithout_clicked(){
    Dialog2* dialog2 = new Dialog2(this);
    dialog2->exec(); // ???focus on this window??? not every Operation Systems are the same!
}

