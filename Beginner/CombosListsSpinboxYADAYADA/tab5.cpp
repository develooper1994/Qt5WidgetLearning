#include "dialog.h"

#include <QPushButton>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>

void Dialog::init_TAB5(){
    //allow resize
    Qt::WindowFlags flags = Qt::WindowType::Widget; // 0
    flags |= Qt::WindowMinMaxButtonsHint;
    flags |= Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

    QPushButton *btnCopy = new QPushButton("Copy",this);
    QPushButton *btnCut = new QPushButton("Cut",this);
    QPushButton *btnPaste = new QPushButton("Paste",this);
    QPushButton *btnUndo = new QPushButton("Undo",this);
    QPushButton *btnRedo = new QPushButton("Redo",this);

    ui->buttonBox_2->addButton(btnCopy,QDialogButtonBox::ActionRole);
    ui->buttonBox_2->addButton(btnCut,QDialogButtonBox::ActionRole);
    ui->buttonBox_2->addButton(btnPaste,QDialogButtonBox::ActionRole);
    ui->buttonBox_2->addButton(btnUndo,QDialogButtonBox::ActionRole);
    ui->buttonBox_2->addButton(btnRedo,QDialogButtonBox::ActionRole);

    connect(btnCopy,&QPushButton::clicked,ui->plainTextEdit,&QPlainTextEdit::copy);
    connect(btnCut,&QPushButton::clicked,ui->plainTextEdit,&QPlainTextEdit::cut);
    connect(btnPaste,&QPushButton::clicked,ui->plainTextEdit,&QPlainTextEdit::paste);
    connect(btnUndo,&QPushButton::clicked,ui->plainTextEdit,&QPlainTextEdit::undo);
    connect(btnRedo,&QPushButton::clicked,ui->plainTextEdit,&QPlainTextEdit::redo);

}

void Dialog::load_TAB5(){
    QString filename("QPlainTextEdit.txt");
    QFile file(filename);
    if(!file.open(QIODevice::OpenModeFlag::ReadOnly | QIODevice::OpenModeFlag::Text)){
        QMessageBox::critical(this, "Error", file.errorString());
        qCritical() << "Error: " << file.errorString();
        return;
    }
    QTextStream stream(&file);
    stream.seek(0);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();
    m_saved = true;
}

void Dialog::save_TAB5(){
    QString filename("QPlainTextEdit.txt");
    QFile file(filename);
    if (!file.open(QIODevice::OpenModeFlag::WriteOnly | QIODevice::OpenModeFlag::Text)) {
        QMessageBox::critical(this, "Error", file.errorString());
        qCritical() << "Error: " << file.errorString();
        return;
    }
    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();
    m_saved=true;
    QMessageBox::information(this, "Saved", "File Saved");
}


// slots

void Dialog::on_plainTextEdit_textChanged()
{
    m_saved = false;
}


void Dialog::on_buttonBox_2_clicked(QAbstractButton *button){
    if (button->text().contains("Save")) {
        save_TAB5();
        return;
    }
    if (button->text().contains("Open")) {
        load_TAB5();
        return;
    }
}

void Dialog::closeEvent(QCloseEvent *event){
    // save and close
    save_TAB5();
    event->accept();
}
