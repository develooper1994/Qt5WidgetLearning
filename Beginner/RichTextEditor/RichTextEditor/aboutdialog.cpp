#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    ui->lblName->setText(QApplication::applicationName());
    ui->lblCompany->setText(QApplication::organizationName());
    ui->lblUrl->setText(QApplication::organizationDomain());
    ui->lblVersion->setText(QApplication::applicationVersion());
}

AboutDialog::~AboutDialog(){
    delete ui;
}

void AboutDialog::on_buttonBox_accepted(){
    accept();
}

