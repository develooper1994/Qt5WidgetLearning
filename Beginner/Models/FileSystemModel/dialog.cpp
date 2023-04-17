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
    dirModel.setRootPath(QDir::currentPath());
    dirModel.setFilter(QDir::Filter::Drives | QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);

    // setup tree veiw
    ui->treeView->setModel(&dirModel);
}


void Dialog::on_treeView_activated(const QModelIndex &index){

}



