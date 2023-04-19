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
    model.setRootPath(dir.rootPath());
    ui->treeView->setModel(&model);
    ui->listView->setModel(&model);

    for (int idx = 1; idx < model.columnCount(); ++idx) {
        ui->treeView->hideColumn(idx);
    }

    //ui->listView->setViewMode(QListView::ViewMode::ListMode);  // looks organized
    //ui->listView->setViewMode(QListView::ViewMode::IconMode);  // looks caotic
}


void Dialog::on_treeView_activated(const QModelIndex &index){
    ui->treeView->setRootIndex(index);
    ui->listView->setCurrentIndex(index);
}


void Dialog::on_listView_activated(const QModelIndex &index){
    ui->listView->setRootIndex(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->expand(index);
}

