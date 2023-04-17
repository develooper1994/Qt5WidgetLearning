
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
    // setup mvc
    QStringList headers;
    headers << "Name" << "Value";
    model.setHorizontalHeaderLabels(headers);
    ui->treeView->setModel(&model);

    QDir dir = QDir::current();
    QFileInfoList fil = dir.entryInfoList();

    foreach (QFileInfo info, fil) {
        if (info.isFile()) {
            addFile(model.invisibleRootItem(), info);
        }
    }
}

void Dialog::addFile(QStandardItem *root, QFileInfo info){
    QStandardItem* item = new QStandardItem(info.fileName());
    root->appendRow(item);

    item->setChild(0,0, new QStandardItem("Size"));
    item->setChild(0,1, new QStandardItem(info.size()));

    item->setChild(1,0, new QStandardItem("Created"));
    item->setChild(1,1, new QStandardItem(info.birthTime().toString()));

    item->setChild(2,0, new QStandardItem("Modified"));
    item->setChild(2,1, new QStandardItem(info.lastModified().toString()));

    item->setChild(3,0, new QStandardItem("Accessed"));
    item->setChild(3,1, new QStandardItem(info.lastRead().toString()));

    item->setChild(4,0, new QStandardItem("Readable"));
    item->setChild(4,1, new QStandardItem(info.isReadable() ? "Yes":"No"));

    item->setChild(5,0, new QStandardItem("Writable"));
    item->setChild(5,1, new QStandardItem(info.isWritable() ? "Yes" : "No"));

    item->setChild(6,0, new QStandardItem("Path"));
    item->setChild(6,1, new QStandardItem(info.path()));
}
