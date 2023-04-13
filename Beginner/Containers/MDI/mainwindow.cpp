#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionNew_triggered(){

}

void MainWindow::on_actionSave_triggered(){

}

void MainWindow::on_actionSave_As_triggered(){

}

void MainWindow::on_actionExit_triggered(){

}

void MainWindow::on_actionCopy_triggered(){

}

void MainWindow::on_actionCut_triggered(){

}

void MainWindow::on_actionPaste_triggered(){

}

void MainWindow::on_actionSelect_All_triggered(){

}

void MainWindow::on_actionNext_triggered(){

}

void MainWindow::on_actionPrevious_triggered(){

}

void MainWindow::on_actionCascade_triggered(){

}

void MainWindow::on_actionTile_triggered(){

}

void MainWindow::on_actionClose_triggered(){

}

void MainWindow::on_actionClose_All_triggered(){

}


QMdiSubWindow *MainWindow::newDocument(){

}

