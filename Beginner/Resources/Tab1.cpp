#include "dialog.h"

// note:
// If a file inside a resource file and you are trying to write a resource file, it gives an error.
// Resource files are readonly. They baked in to binary by rcc compiler.
// You cannot change baked file(very hard task)
// Example-readonly: https:                        https://github.com/voidrealms/qtwb-5-2
// Example-(like directory, collision detection) : https://github.com/voidrealms/qtwb-5-3
// Example-library resources :                     https://github.com/voidrealms/qtwb-5-4


void Dialog::init(){
    QPushButton* btnAccept = new QPushButton(QIcon(":/dialog/images/accept.png"), "Accept", this);
    QPushButton* btnReject = new QPushButton("Reject", this);
    btnReject->setIcon(QIcon(":/dialog/images/cancel.png"));

    ui->btnBox->addButton(btnAccept, QDialogButtonBox::ButtonRole::AcceptRole);
    ui->btnBox->addButton(btnReject, QDialogButtonBox::ButtonRole::RejectRole);

    connect(btnAccept, &QPushButton::clicked, this, &Dialog::on_btnAccept);
    connect(btnReject, &QPushButton::clicked, this, &QDialog::reject);
}

void Dialog::load(){
    QFile file("saved.txt");
    if(!file.exists()) return;
    if(!file.open(QIODevice::OpenModeFlag::ReadOnly)){
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->pte->setPlainText(stream.readAll());
    file.close();
    m_saved = true;
}

void Dialog::save(){
    QFile file("saved.txt");
    if(!file.open(QIODevice::OpenModeFlag::WriteOnly)){
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui->pte->toPlainText();
    file.close();
    m_saved = true;
}

// slots

void Dialog::on_btnNew_clicked(){
    ui->pte->clear();
}


void Dialog::on_btnOpen_clicked(){
    load();
}


void Dialog::on_btnSave_clicked(){
    save();
    QMessageBox::information(this, "Saved", "File Saved");
}

void Dialog::on_btnAccept()
{
    save();
    accept();
}

void Dialog::on_pte_textChanged(){
    m_saved=false;
}

void Dialog::closeEvent(QCloseEvent *event){
    if (!m_saved) {
        QMessageBox::StandardButton btn = QMessageBox::question(this, "Save File?", "Would you like to save file?");
        if(btn==QMessageBox::StandardButton::Yes) save();
    }
    event->accept();
}
