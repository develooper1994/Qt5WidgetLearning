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

    // Hide coloums
    for (int idx = 1; idx < dirModel.columnCount(); ++idx) {
        ui->treeView->hideColumn(idx);
    }

    fileModel.setRootPath(dirModel.rootPath());
    fileModel.setFilter(QDir::Filter::Files);

    ui->listView->setModel(&fileModel);

}


void Dialog::on_treeView_activated(const QModelIndex &index){
    QString path = dirModel.filePath(index);
    qDebug() << "path: " << path;
    fileModel.setFilter(QDir::Filter::Files);  // reset the filter. You don't have to
    ui->listView->setRootIndex(fileModel.setRootPath(path));
}



