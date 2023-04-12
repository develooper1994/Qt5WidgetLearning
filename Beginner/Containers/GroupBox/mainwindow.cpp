#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

QString MainWindow::getOptions(QGroupBox *group){
    QString value;
    foreach (QObject* obj, group->children()) {
        QCheckBox* cb = qobject_cast<QCheckBox*>(obj);
        if (!cb) continue;
        if(cb->isChecked()) value.append(cb->text() + "\r\n");
    }
    return value;
}



void MainWindow::on_buttonBox_accepted(){
    QString message;

    message.append("Email: " + ui->lblEmail->text() + "\r\n");
    message.append("Name: " + ui->lblName->text() + "\r\n");

    QString food = getOptions(ui->grpFood);
    message.append(food);

    QString activities = getOptions(ui->grpActivities);
    message.append(activities);

    QMessageBox::information(this, "Info", message);

    //accept();
}
void MainWindow::on_buttonBox_rejected(){
    //reject();
}

