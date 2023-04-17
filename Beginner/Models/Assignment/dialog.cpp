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
    for (int row = 0; row < 10; ++row) {
        QStandardItem* rowItem = new QStandardItem(tr("Item: %0").arg(row));
        QList<QStandardItem*> colItems;
        for (int col = 0; col < 5; ++col) {
            colItems.append(new QStandardItem(tr("Col: %0").arg(col)));
        }
        rowItem->appendColumn(colItems);
        model.appendRow(rowItem);
    }

    // introduce model to view
    ui->treeView->setModel(&model);
    ui->listView->setModel(&model);
    ui->tableView->setModel(&model);
}
