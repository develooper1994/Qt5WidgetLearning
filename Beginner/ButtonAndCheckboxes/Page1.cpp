#include "dialog.h"

void Dialog::on_btnCheckable_clicked()
{
    qDebug() << "Checkable Button Clicked. " <<
        "Is button checkable?: " << ui->btnCheckable->isCheckable() <<
        "Is button checked?: " << ui->btnCheckable->isChecked();
}


void Dialog::on_btnAutoRepeat_clicked()
{
    qDebug() << "AutoRepeat Button Clicked. Is button autorepeat?: " << ui->btnAutoRepeat->autoRepeat();
}


void Dialog::on_btnDefault_clicked()
{
    qDebug() << "Default Button Clicked. Is button default?: " << ui->btnDefault->isDefault();
}


void Dialog::on_btnIsChecked_clicked()
{
    qDebug() << "Is Checked Button Clicked. Is button checked?: " <<
        "Is button checkable?: " << ui->btnCheckable->isCheckable() <<
        "Is button checked?: " << ui->btnCheckable->isChecked();
}


void Dialog::on_btnToggleAutoRepeat_clicked()
{
    qDebug() << "Toggle Auto Repeat Button Clicked";
    bool repeat = !ui->btnAutoRepeat->autoRepeat();
    ui->btnAutoRepeat->setAutoRepeat(repeat);
}


void Dialog::on_btnToggleDefault_clicked()
{
    qDebug() << "Toggle Default Button Clicked";
    bool makeDefault = !ui->btnDefault->isDefault();
    ui->btnDefault->setDefault(makeDefault);
}


void Dialog::on_btnQuit_clicked()
{
    qDebug() << "Quit Button Clicked";
    QGuiApplication::quit();
}
