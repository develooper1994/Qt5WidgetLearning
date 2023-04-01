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


// slots
void Dialog::on_btnLogin_clicked(){
    Login* loginDialog = new Login();
    loginDialog->exec();
    if (loginDialog->getName()=="admin" && loginDialog->getPassword()=="admin123") {
        ui->lblLogin->setText("Welcome: " + loginDialog->getName());
    } else {
        ui->lblLogin->setText("Not Logged In");
        QMessageBox::critical(this, "Invalid Login", "Wrong User or Password");
    }

    loginDialog->deleteLater();
}

// getter-setter
