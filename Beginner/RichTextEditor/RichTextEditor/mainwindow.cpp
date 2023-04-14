#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setup();
    init();
    load();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setup(){
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    setupStatusbar();
}

void MainWindow::init(){
    m_path="";
    m_changed = false;
    newFile();
}

void MainWindow::load(){

}

void MainWindow::setupStatusbar(){
    for(auto&& lbl : lblVectorStatus) {
        lbl = new QLabel(this);  // lblIcon/lblStatus/lblFile
    }

    QLabel* lblIcon = lblVectorStatus.at(0);
    lblIcon->setPixmap(QPixmap(":/files/images/new.png"));
    ui->statusbar->addWidget(lblIcon);

    // lblStatus
    QLabel* lblStatus = lblVectorStatus.at(1);
    lblStatus->setText("Not Saved");
    ui->statusbar->addWidget(lblStatus);

    // lblFile
    QLabel* lblFile = lblVectorStatus.at(2);
    lblFile->setText("New");
    ui->statusbar->addWidget(lblFile);
}

void MainWindow::updateStatusbar(QStringView status){
    //ui->statusbar->showMessage(status.toString());
/*
    foreach(QObject* obj, ui->statusbar->children()){
        qDebug() << obj;
    }
*/

    /*
    // METHOD-1
    // 0->sizegrip, 3->horizontal_layout
    QLabel* lblIcon = qobject_cast<QLabel*>(ui->statusbar->children().at(1));
    QLabel* lblStatus = qobject_cast<QLabel*>(ui->statusbar->children().at(2));
    QLabel* lblFile = qobject_cast<QLabel*>(ui->statusbar->children().at(4));
*/
    // METHOD-2
    QLabel* lblIcon = lblVectorStatus.at(0);
    QLabel* lblStatus = lblVectorStatus.at(1);
    QLabel* lblFile = lblVectorStatus.at(2);

    if (m_changed) {
        lblIcon->setPixmap(QPixmap(":/files/images/new.png"));
        lblStatus->setText("Not Saved");
    } else{
        lblIcon->setPixmap(QPixmap(":/files/images/save.png"));
        lblStatus->setText("File Saved");
    }

    lblFile->setText(m_path);
}


// methods
void MainWindow::newFile(){
    ui->textEdit->clear();
    updateStatusbar(tr("New File"));
    m_path = "";
    m_changed = false;
}

void MainWindow::openFile(){
    QString path = QFileDialog::getOpenFileName(this, "Open File", QString(), dialogFilter);
    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::OpenModeFlag::ReadOnly)) {
        QMessageBox::critical(this, "Open Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->textEdit->setHtml(stream.readAll());
    file.close();

    m_path=path;
    updateStatusbar(m_path);
    m_changed = false;
}

void MainWindow::saveFile(QStringView path){
    if (path.isEmpty()) {
        saveAsFile();
        return;
    }

    QFile file(path.toString());
    if (!file.open(QIODevice::OpenModeFlag::WriteOnly)) {
        QMessageBox::critical(this, "Save Error", file.errorString());
        updateStatusbar("Save Error: " + file.errorString());
        saveAsFile();
        return;
    }

    QTextStream stream(&file);
    stream << ui->textEdit->toHtml();
    file.close();

    m_path = path.toString();
    updateStatusbar(m_path);
    m_changed=false;
}

void MainWindow::saveAsFile(){
    QString path = QFileDialog::getSaveFileName(this, "Save File", QString(), dialogFilter);
    if (path.isEmpty()) return;
    saveFile(path);
}

void MainWindow::checkFileSaved(){
    if (!m_changed) return;
    if (ui->textEdit->toHtml().isEmpty()) return;

    QMessageBox::StandardButton value = QMessageBox::question(this, "File Unsaved!",  "Do you wan to save? ");
    if (value!=QMessageBox::StandardButton::Yes) return;  // don't care file saved
    saveFile(m_path);  // m_path.isEmpty() is inside of method
}

// QWidget interface
void MainWindow::closeEvent(QCloseEvent *event){
    checkFileSaved();
    event->accept();
}




// slots
    //menu-action slots
        // menu-File
void MainWindow::on_actionNew_triggered(){
    checkFileSaved();
    newFile();
}


void MainWindow::on_actionOpen_triggered(){
    checkFileSaved();
    openFile();
}


void MainWindow::on_actionSave_triggered(){
    saveFile(m_path);
}


void MainWindow::on_actionSave_As_triggered(){
    saveAsFile();
}


void MainWindow::on_actionExit_triggered(){
    close();  // triggers close_event
}

        // menu-Edit

void MainWindow::on_actionCopy_triggered(){
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered(){
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered(){
    ui->textEdit->paste();
}


void MainWindow::on_actionFind_triggered(){
    FindDialog* dlg = new FindDialog(this);
    if (!dlg->exec()) return;

    QTextDocument::FindFlags flags;
    if(dlg->caseSensitive()) flags = flags | QTextDocument::FindFlag::FindCaseSensitively;
    if(dlg->wholeWords()) flags = flags | QTextDocument::FindFlag::FindWholeWords;
    if(dlg->backwards()) flags = flags | QTextDocument::FindFlag::FindBackward;

    bool value = ui->textEdit->find(dlg->text(), flags);
    if(!value) QMessageBox::information(this, "Not Found", "Was not able to find:" + dlg->text());
}


void MainWindow::on_actionReplace_triggered(){
    ReplaceDialog *dlg = new ReplaceDialog(this);
    if(!dlg->exec()) return;

    bool isAll = dlg->all();
    QString dlg_text = dlg->text();
    QString dlg_replaceText = dlg->replaceText();
    if(isAll){
        //Replace all
        QString text = ui->textEdit->toHtml();
        text = text.replace(dlg_text, dlg_replaceText);
        ui->textEdit->setHtml(text);
    }
    else{
        //Replace one
        bool value = ui->textEdit->find(dlg_text);
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.insertHtml(dlg_replaceText);
        if(!value) QMessageBox::information(this,"not Found","Was not able to find " + dlg_text);
    }
}


void MainWindow::on_actionSelect_All_triggered(){
    ui->textEdit->selectAll();
}


void MainWindow::on_actionUndo_triggered(){
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered(){
    ui->textEdit->redo();
}

        // menu-view

void MainWindow::on_actionZoom_In_triggered(){
    ui->textEdit->zoomIn(1); // multiplier
}


void MainWindow::on_actionZoom_Out_triggered(){
    ui->textEdit->zoomOut(1); // multiplier
}

        // menu-Text

void MainWindow::on_actionBold_triggered(){
    // there is a font family.
    // Each indivisual text has diffirent font.
    QFont font = ui->textEdit->currentFont();
    font.setBold( font.bold() ? false : true );
    ui->textEdit->setCurrentFont(font);
}


void MainWindow::on_actionItalic_triggered(){
    // there is a font family.
    // Each indivisual text has diffirent font.
    QFont font = ui->textEdit->currentFont();
    font.setItalic( font.italic() ? false : true );
    ui->textEdit->setCurrentFont(font);
}


void MainWindow::on_actionUnderline_triggered(){
    // there is a font family.
    // Each indivisual text has diffirent font.
    QFont font = ui->textEdit->currentFont();
    font.setUnderline( font.underline() ? false : true );
    ui->textEdit->setCurrentFont(font);
}


void MainWindow::on_actionStrike_triggered(){
    // there is a font family.
    // Each indivisual text has diffirent font.
    QFont font = ui->textEdit->currentFont();
    font.setStrikeOut( font.strikeOut() ? false : true );
    ui->textEdit->setCurrentFont(font);
}


void MainWindow::on_actionColor_triggered(){
    QColor current = ui->textEdit->currentCharFormat().foreground().color();
    QColor color = QColorDialog::getColor(current, this, "Select a Color");

    ui->textEdit->setTextColor(color);
    m_changed = true;
}


void MainWindow::on_actionFont_triggered(){
    QFont current = ui->textEdit->currentFont();
    bool ok;
    QFont font = QFontDialog::getFont(&ok, current, this, "Select a Font");
    if(ok) ui->textEdit->setCurrentFont(font);

    m_changed=true;
}


void MainWindow::on_actionHelp_triggered(){
    QDesktopServices::openUrl(QApplication::organizationDomain());
}


void MainWindow::on_actionAbout_triggered(){
    //QMessageBox::information(this, "About", "Qt 5 Widget Tutorial. 9.Section(Text Editor Section)");
    AboutDialog* dlg = new AboutDialog(this);
    if(!dlg->exec()) return;
}

    // menu-insert
void MainWindow::on_actionCustom_triggered(){
    ui->textEdit->insertHtml("<font size='40' color='red'><b>T</b><i>est</i></font><br<br>");
    ui->textEdit->insertHtml("<ul><li>Coffee</li><li>Tea</li><li>Water</li></ul>");
}

    //item slots
void MainWindow::on_textEdit_textChanged(){
    m_changed = true;
}



// getter-setter
bool MainWindow::changed() const{
    return m_changed;
}
void MainWindow::setChanged(bool newChanged){
    m_changed = newChanged;
}
QString MainWindow::filename() const{
    return m_path;
}
void MainWindow::setFilename(const QString &newFilename){
    m_path = newFilename;
}


void MainWindow::on_actionAnimals_triggered(){
    ui->textEdit->insertHtml("<ul>"
                                "<li><font color='red'>Free Bird</font></li>"
                                "<li><font color='yellow'>Eagle</font></li>"
                                "<li><font color='green'>Raven</font></li>"
                             "</ul>");

    /*
    QString html;
    html.append("<ul>");
    html.append("<li><font color='red'>Dog</font></li>");
    html.append("<li><font color='green'>Cat</font></li>");
    html.append("<li><font color='blue'>Bird</font></li>");
    html.append("</ul>");
    ui->textEdit->insertHtml(html);
    */
}

