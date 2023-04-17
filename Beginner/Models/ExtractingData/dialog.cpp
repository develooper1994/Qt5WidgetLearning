#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog(){
    delete ui;
}


void Dialog::init(){
    for (int idx = 0; idx < 5; ++idx) {
        model.appendRow(new QStandardItem(tr("Item: %0").arg(idx)));
    }
    ui->listView->setModel(&model);
}


void Dialog::on_buttonBox_accepted(){
    QStringList list;
    for (int idx = 0; idx < model.rowCount(); ++idx) {
        QStandardItem* item = model.item(idx);
        list.append(item->text());
    }

    QString msg = list.join("\r\n");
    QMessageBox::information(this, "Items", msg);

    accept();
}

void Dialog::on_buttonBox_rejected(){
    reject();
}
