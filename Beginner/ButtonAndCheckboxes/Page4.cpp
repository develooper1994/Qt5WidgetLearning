#include "dialog.h"

void Dialog::on_option1_clicked()
{
    selectPage4Option(sender());
}

void Dialog::on_option2_clicked()
{
    selectPage4Option(sender());
}

void Dialog::on_option3_clicked()
{
    selectPage4Option(sender());
}

void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this, "Ok", "Closing");
    accept();
}

void Dialog::on_buttonBox_rejected()
{
    QMessageBox::critical(this, "Cancel", "Closing");
    reject();
}

void Dialog::on_buttonBox_helpRequested()
{
    auto result = QMessageBox::question(this, "Help", "Closing");
    if(result == QMessageBox::StandardButton::Ok) accept();
    else if(result == QMessageBox::StandardButton::Cancel) reject();
}

// helpful methods
void Dialog::selectPage4Option(QObject *sender)
{
    QCommandLinkButton* btn = qobject_cast<QCommandLinkButton*>(sender);
    if(!btn) return;
    ui->lblSelected->setText(btn->text());
    QMessageBox::information(this, btn->text(), btn->description());
}
