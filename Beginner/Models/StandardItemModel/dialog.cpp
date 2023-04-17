
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
    QStringList headers;
    headers << "My Items";
    model.setHorizontalHeaderLabels(headers);  // introduce data to model

    QStandardItem* root = model.invisibleRootItem();
    for (int idx1 = 0; idx1 < 10; ++idx1) {
        QStandardItem* parent = new QStandardItem(QString("Parent %0").arg(idx1));
        root->appendRow(parent);
        for (int idx2 = 0; idx2 < 10; ++idx2) {
            QStandardItem* child = new QStandardItem(QString("Child %0").arg(idx2));
            parent->appendRow(child);
            for (int idx3 = 0; idx3 < 10; ++idx3) {
                QStandardItem* sub = new QStandardItem(QString("Sub %0").arg(idx3));
                child->appendRow(sub);
            }
        }
    }

    // give model to view
    ui->treeView->setModel(&model);
}
