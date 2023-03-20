#include "dialog.h"

void Dialog::Page6Connection(){
    connect(ui->Btn0, SIGNAL(clicked()), this, SLOT(appendCode()));
    connect(ui->Btn1, SIGNAL(clicked()), this, SLOT(appendCode()));
    connect(ui->Btn2, SIGNAL(clicked()), this, SLOT(appendCode()));
    connect(ui->Btn3, SIGNAL(clicked()), this, SLOT(appendCode()));
    connect(ui->Btn4, SIGNAL(clicked()), this, SLOT(appendCode()));
    connect(ui->Btn5, SIGNAL(clicked()), this, SLOT(appendCode()));
    connect(ui->Btn6, SIGNAL(clicked()), this, SLOT(appendCode()));
    connect(ui->Btn7, SIGNAL(clicked()), this, SLOT(appendCode()));
    connect(ui->Btn8, SIGNAL(clicked()), this, SLOT(appendCode()));
    connect(ui->Btn9, SIGNAL(clicked()), this, SLOT(appendCode()));
}


void Dialog::appendCode(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if(!button) return;

    accumulated.append(button->text());
    ui->lblCode->setText(accumulated);

    if (code.isEmpty()) {
        ui->btnSave->setEnabled(true);
        ui->btnVerify->setEnabled(false);
    } else {
        ui->btnSave->setEnabled(false);
        ui->btnVerify->setEnabled(true);
    }
}


void Dialog::on_btnSave_clicked(){
    code = accumulated;
    accumulated.clear();
    ui->btnSave->setEnabled(false);
    ui->btnVerify->setEnabled(true);

    ui->lblCode->setText("Code saved, please re-enter the code and click verify");
    QMessageBox::information(this, "Saving...", "Code Saved");
}


void Dialog::on_btnVerify_clicked(){
    QString message;
    if (code == accumulated) {
        message = "Code Verified";
    } else {
        message = "Code Not Verified";
    }
    QMessageBox::information(this, "Verifing...", message);
    accumulated.clear();
    ui->lblCode->setText("Enter the code and click verify");
}
