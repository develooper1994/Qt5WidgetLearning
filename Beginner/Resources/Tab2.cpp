#include "dialog.h"

void Dialog::on_btnLoad_clicked(){
    QFile file(":/documents/files/files/file.txt");
    if(!file.exists()){
        QMessageBox::critical(this,"File not found", "Sorry, we could not find that file!");
        return;
    }

    if(!file.open(QIODevice::OpenModeFlag::ReadOnly)){
        QMessageBox::critical(this, "Load Error", file.errorString());
        return;
    }
    QTextStream stream(&file);
    ui->pte2->setPlainText(stream.readAll());
    file.close();
}


void Dialog::on_btnSave_2_clicked(){
    QFile file(":/documents/files/files/file.txt");
    if(!file.exists()){
        QMessageBox::critical(this,"File not found","Sorry, we could not find that file!");
        return;
    }
    if(!file.isWritable()){
        QMessageBox::critical(this, "Non Writeable", "Can not write to file!!!");
        return;
    } else{
        QMessageBox::information(this, "Writeable", "Can write to file!!!");
    }
    if(!file.open(QIODevice::OpenModeFlag::WriteOnly)){
        QMessageBox::critical(this, "Save Error", file.errorString());
        return;
    }
    QTextStream stream(&file);
    stream << ui->pte2->toPlainText();
    file.close();
}
