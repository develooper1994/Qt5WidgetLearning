#include "../header/dialog.h"
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
void Dialog::on_btnWithParent_clicked(){
    // dependent to parent window by passing this
    //Dialog2* dialog2 = new Dialog2(this); // creates and not destroys when out of scope!
    Dialog2 dialog2;  // creates and destroys when out of scope!
    dialog2.show();
}


void Dialog::on_btnWithoutParent_clicked(){
    // dependent to parent window by passing nullptr
    Dialog2* dialog2 = new Dialog2(nullptr); // creates and not destroys when out of scope!
    dialog2->show();
}

