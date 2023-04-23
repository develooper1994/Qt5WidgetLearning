#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->listWidget);
    ui->listWidget->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
    create();
}

MainWindow::~MainWindow(){
    delete ui;
}

// slots
void MainWindow::on_actionNew_triggered(){
    checkSaved();
    create();
}

void MainWindow::on_actionOpen_triggered(){
    checkSaved();
    QString path = QFileDialog::getOpenFileName(this, "Open", QString(), FileDialogFilter);
    if(path.isEmpty()) return;
    open(path);
}

void MainWindow::on_actionSave_triggered(){
    if(m_filename.isEmpty()){
        on_actionSave_As_triggered();
        return;
    }
    save(m_filename);
}

void MainWindow::on_actionSave_As_triggered(){
    QString path = QFileDialog::getSaveFileName(this, "Save", QString(), FileDialogFilter);
    if(path.isEmpty()) return;
    save(path);
}

void MainWindow::on_actionExit_triggered(){

    // is it fresh created?
    if(!(false == m_changed &&
          m_filename.isEmpty()))
        checkSaved();
    close();
}

void MainWindow::on_actionAdd_triggered(){
    createItem(Qt::CheckState::Unchecked, QString("New Item"));
    m_changed=true;
}

void MainWindow::on_actionRemove_triggered(){
    QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
    foreach (QListWidgetItem* item, list) {
        int idx=ui->listWidget->row(item);
        delete ui->listWidget->takeItem(idx);
    }
    m_changed=true;
}

void MainWindow::on_actionClear_triggered(){
    ui->listWidget->clear();
    m_changed=true;
}

void MainWindow::on_actionSelect_All_triggered(){
    ui->listWidget->selectAll();
}

void MainWindow::on_actionSelect_None_triggered(){
    ui->listWidget->clearSelection();
}

void MainWindow::on_actionChecked_triggered(){
    setCheckState(Qt::CheckState::Checked);
}

void MainWindow::on_actionUnchecked_triggered(){
    setCheckState(Qt::CheckState::Unchecked);
}

void MainWindow::on_actionPartially_triggered(){
    setCheckState(Qt::CheckState::PartiallyChecked);
}

void MainWindow::closeEvent(QCloseEvent *event){
    checkSaved();
    event->accept();
}




void MainWindow::create(){
    m_changed=false;
    m_filename.clear();
    ui->listWidget->clear();
}

void MainWindow::open(QString path){
    /*
        -*-*-* File Format *-*-*-
        - how many records are there?(count)
        - state
        - name
        - state
        - name
        - ...
    */
    QFile file(path);
    if(!file.open(QIODevice::OpenModeFlag::ReadOnly)){
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }
    create();  // clear data and ui than add items
    QDataStream stream(&file);
    int count;
    stream >> count;
    for (int idx = 0; idx < count; ++idx) {
        int state=0;
        QString name;
        stream >> state;
        stream >> name;
        Qt::CheckState checkState = static_cast<Qt::CheckState>(state);
        createItem(checkState, name);
    }
    file.close();
    m_filename = path;
    m_changed=false;
}

void MainWindow::save(QString path){
    /*
        -*-*-* File Format *-*-*-
        - how many records are there?(count)
        - state
        - name
        - state
        - name
        - ...
    */
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }
    QDataStream stream(&file);
    int count = ui->listWidget->count();
    stream << count;
    for (int idx = 0; idx < count; ++idx) {
        QListWidgetItem* item = ui->listWidget->item(idx) ;
        Qt::CheckState checkState = item->checkState();
        int state = static_cast<Qt::CheckState>(checkState);
        stream << state;
        stream << item->text();
    }

    file.close();
    m_filename = path;
    m_changed=false;
}

bool MainWindow::checkSaved(){
    if(!m_changed) return true; // if not changed do nothing
    QMessageBox::StandardButton btn = QMessageBox::question(this, "Save File?", "Do you want to save the file?",
                                                            QMessageBox::StandardButton::Yes|QMessageBox::StandardButton::No);
    if (btn == QMessageBox::StandardButton::Yes) {
        on_actionSave_triggered();
        return true;
    }
    return false;
}

void MainWindow::createItem(Qt::CheckState state, QString name){
    QListWidgetItem *item = new QListWidgetItem(name,ui->listWidget);
    item->setCheckState(state);
    item->setFlags(Qt::ItemFlag::ItemIsEnabled|
                   Qt::ItemFlag::ItemIsUserCheckable|
                   Qt::ItemFlag::ItemIsSelectable|
                   Qt::ItemFlag::ItemIsEditable|
                   Qt::ItemFlag::ItemIsUserTristate);
    ui->listWidget->addItem(item);
}

void MainWindow::setCheckState(Qt::CheckState state){
    QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
    foreach (QListWidgetItem* item, list) {
        item->setCheckState(state);
    }
    m_changed=true;
}

