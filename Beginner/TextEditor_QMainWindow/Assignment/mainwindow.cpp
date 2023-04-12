
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->plainTextEdit);
    ui->statusbar->showMessage("Assignment Complete");
}

MainWindow::~MainWindow(){
    delete ui;
}


