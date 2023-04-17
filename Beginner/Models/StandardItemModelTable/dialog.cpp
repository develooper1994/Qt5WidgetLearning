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
    model.insertRows(0,4);
    model.insertColumns(0,4);

    for (int r = 0; r < model.rowCount(); ++r) {
        for (int c = 0; c < model.rowCount(); ++c) {
            QStandardItem* item = new QStandardItem(tr("row: %0, col: %1").arg(r).arg(c));
            model.setItem(r, c, item);
        }
    }


    ui->tableView->setModel(&model);
    connect(&model, &QStandardItemModel::itemChanged, this, &Dialog::itemChanged);
}

void Dialog::itemChanged(QStandardItem *item){
    qDebug() << "row: " << item->index().row() << " coloumn: " << item->index().column() << " text:" << item->text();
}
