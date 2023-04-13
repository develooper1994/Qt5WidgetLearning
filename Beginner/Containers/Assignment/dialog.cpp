#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Dialog::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Dialog::on_buttonBox_rejected);
}

Dialog::~Dialog(){
    delete ui;
}

QString Dialog::getSelected(QGroupBox *groupbox){
    QString value;
    foreach(QObject* obj, groupbox->children()){
        QRadioButton* rb = qobject_cast<QRadioButton*>(obj);
        if (!rb) {
            continue;
        }
        if(rb->isChecked()){
            value = rb->text();
            break;
        }
    }

    return value;
}

void Dialog::on_buttonBox_accepted(){
    QString order;

    order.append("Size: " + getSelected(ui->grpSize) + "\n");
    order.append("Meal: " + getSelected(ui->grpMeal) + "\n");
    order.append("Drink: " + getSelected(ui->grpDrink) + "\n");

    QMessageBox::information(this, "Order", order);
    accept();
}

void Dialog::on_buttonBox_rejected(){
    reject();
}
