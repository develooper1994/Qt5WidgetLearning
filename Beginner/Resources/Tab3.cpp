#include "dialog.h"

#include <QListWidgetItem>
#include <QDir>

void Dialog::load_tab3(){
    QDir dir(":/");
    scan_tab3(dir.entryInfoList());
}

void Dialog::scan_tab3(QFileInfoList FIL){
    foreach (QFileInfo info, FIL){
        qInfo() << info.absoluteFilePath();
        if(info.isDir()){
            QDir dir(info.absoluteFilePath());
            scan_tab3(dir.entryInfoList());
        } else{
            QListWidgetItem *itm = new QListWidgetItem(ui->listWidget);
            itm->setText(info.absoluteFilePath());
            itm->setIcon(QIcon(info.absoluteFilePath()));
            ui->listWidget->addItem(itm);
        }
    }
}


// slots
void Dialog::on_listWidget_itemSelectionChanged(){
    QListWidgetItem* item = ui->listWidget->currentItem();
    ui->lblName->setText(item->text());
    ui->lblImage->setPixmap(item->icon().pixmap(32, 32));
}

void Dialog::on_btnBoxOk_accepted(){
    accept();
}
