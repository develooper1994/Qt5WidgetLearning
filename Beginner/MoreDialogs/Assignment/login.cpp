#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

// slots
void Login::on_buttonBox_accepted(){
    name = ui->leUser->text();
    password = ui->lePassword->text();
    accept();
}

// getter-setters
QString Login::getName() const
{
    return name;
}

QString Login::getPassword() const
{
    return password;
}

