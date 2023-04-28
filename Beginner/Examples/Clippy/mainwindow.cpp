#include "mainwindow.h"
#include "./ui_mainwindow.h"

#define StatusBarWait 2000

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->listView);
    auto toolbar = ui->toolBar;
    removeToolBar(toolbar);
    addToolBar(Qt::RightToolBarArea, toolbar);
    toolbar->show();

    init();
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::init(){
    m_list.clear();
    m_path="";
    m_changed=false;
    m_model.setStringList(m_list);
    ui->listView->setModel(&m_model);

    connect(&m_timer, &QTimer::timeout, this, &MainWindow::timeout);
    m_timer.setInterval(500);
    m_timer.start();
}

void MainWindow::checkSaved(){
    if (!m_changed) return;
    QMessageBox::StandardButton btn = QMessageBox::question(this, "Saved Changes?", "Would you want to save changes?", QMessageBox::StandardButton::Yes|QMessageBox::StandardButton::No, QMessageBox::StandardButton::Yes);
    if(btn==QMessageBox::StandardButton::Yes) on_actionSave_triggered();
}

void MainWindow::save(QString path, const QStringList& list){
    QFile file(path);
    if (!file.open(QIODevice::OpenModeFlag::WriteOnly)) {
        QMessageBox::critical(this, tr("Error!"), file.errorString());
        return;
    }
    //QDataStream instead to load and save multi-line
    QTextStream stream(&file);
    foreach (QStringView line, list) {
        stream << line << "\r\n";
    }
    file.close();
}

QStringList MainWindow::open(QString path){
    QFile file(path);
    if (!file.open(QIODevice::OpenModeFlag::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), file.errorString());
        return QStringList();
    }
    //QDataStream instead to load and save multi-line
    QTextStream stream(&file);
    QStringList list;
    while(!stream.atEnd()){
        list.append(stream.readLine());
    }
    return list;
}


// slots
void MainWindow::timeout(){
    QClipboard *clipboard = QApplication::clipboard();
    QString data = clipboard->text();
    if(!data.compare(this->m_last)) return;
    if(m_list.contains(data)) return;
    m_last = data;
    qDebug() << "Getting: " << m_last;
    m_list.append(m_last);
    m_model.setStringList(m_list);
    ui->statusbar->showMessage("Added form the clipboard",2000);
}

void MainWindow::on_actionNew_triggered(){
    checkSaved();
    m_list.clear();
    m_path.clear();
    m_changed=false;
    m_model.setStringList(m_list);
}

void MainWindow::on_actionOpen_triggered(){
    checkSaved();
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"));
    if (path.isEmpty()) return;
    m_path=path;

    QStringList list = open(path);
    if (list.isEmpty()) return;
    m_list=list;
    m_changed=false;
    m_model.setStringList(m_list);
    ui->statusbar->showMessage("Opened: " + m_path, StatusBarWait);
}

void MainWindow::on_actionSave_triggered(){
    if(m_path.isEmpty()){
        on_actionSave_As_triggered();
        return;
    }
    save(m_path, m_list);
    m_changed=false;
    ui->statusbar->showMessage("Saved: " + m_path, StatusBarWait);
}

void MainWindow::on_actionSave_As_triggered(){
    QString path = QFileDialog::getSaveFileName(this, "Save File");
    if (path.isEmpty()) return;
    m_path=path;
    on_actionSave_triggered();
}


void MainWindow::on_actionStart_triggered(){
    m_timer.start();
    ui->statusbar->showMessage("Listing on Clipboard", StatusBarWait);
}

void MainWindow::on_actionStop_triggered(){
    m_timer.stop();
    ui->statusbar->showMessage("Manuel Mode", StatusBarWait);
}

void MainWindow::on_actionCopy_triggered(){
    int idx = ui->listView->currentIndex().row();

    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(m_list.at(idx));

    ui->statusbar->showMessage("Copied: " + QString::number(idx), StatusBarWait);
}

void MainWindow::on_actionCut_triggered(){
    int idx = ui->listView->currentIndex().row();

    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(m_list.at(idx));

    m_list.removeAt(idx);
    m_model.setStringList(m_list);
    m_changed=true;

    ui->statusbar->showMessage("Copied: " + QString::number(idx), StatusBarWait);
}

void MainWindow::on_actionPaste_triggered(){
    timeout();
}

void MainWindow::on_actionDelete_triggered(){
    int idx = ui->listView->currentIndex().row();
    if(idx<0) return;

    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(m_list.at(idx));

    m_list.removeAt(idx);
    m_model.setStringList(m_list);
    m_changed=true;

    ui->statusbar->showMessage("Deleted: " + QString::number(idx), StatusBarWait);
}

void MainWindow::closeEvent(QCloseEvent *event){
    checkSaved();
    event->accept();
}
