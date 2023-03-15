#include "dialog.h"

void Dialog::on_btnPizzaCancel_clicked()
{
    QMessageBox::critical(this, "WHAT!!!", "You do not want pizza??");
    reject();
}

void Dialog::on_btnPizzaOk_clicked()
{
    QString pizza = getPizzaOptions(ui->grpPizzaType);
    QString edge = getPizzaOptions(ui->grpEdgeType);
    QString payment = getPizzaOptions(ui->grpPayment);
    QString size = getPizzaOptions(ui->grpSize);
/*
    QString address = textEditAddress.text();
    QString note = textEditNote.text();
*/
    QString seperator = "\n\r";
    QString order="Order" + seperator;
    order += "Size: " + size + seperator;
    order += "Payment: " + payment + seperator;
    order += "Edge: " + edge + seperator;
    order += "Pizza Type: " + pizza + seperator;
/*
    order += "Address: " + address + seperator;
    order += "Note: " + note + seperator;
*/
    QMessageBox::information(this, "What!?", order);

    accept();
}

// helpful method
QString Dialog::getPizzaOptions(QObject *obj)
{
    QString value = "None";
    QList<QRadioButton*> lst = obj->findChildren<QRadioButton*>(QString(), Qt::FindChildOption::FindChildrenRecursively);

    foreach (QRadioButton* rdo, lst) {
        if (rdo->isChecked()) {
            value = rdo->text();
            break;
        }
    }

    return value;
}
