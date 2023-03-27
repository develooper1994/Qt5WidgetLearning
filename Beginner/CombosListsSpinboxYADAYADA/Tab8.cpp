#include "dialog.h"

void Dialog::init_TAB8(){
    QString emailValidatorRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    QRegularExpression regex(emailValidatorRegex, QRegularExpression::PatternOption::CaseInsensitiveOption);
    ui->txtEmail->setValidator(new QRegularExpressionValidator(regex, this));
    //connect(ui->txtEmail, &QLineEdit::textChanged, this, &Dialog::checkInput);
}

void Dialog::load_TAB8(){

}

void Dialog::save_TAB8(){

}


void Dialog::checkInput(){
    if (ui->txtEmail->hasAcceptableInput()) {
        ui->txtEmail->setStyleSheet("QLineEdit {color: black;}");
    } else {
        ui->txtEmail->setStyleSheet("QLineEdit {color: red;}");
    }
}



// slots
void Dialog::on_txtEmail_textChanged(const QString &arg1){
    checkInput();
}

void Dialog::on_btnBoxUserInputValidateRegex_accepted(){
    if (ui->txtEmail->hasAcceptableInput()) {
        QMessageBox::information(this, "Email", ui->txtEmail->text());
        accept();
    } else {
        QMessageBox::critical(this, "Email", "Not Valid!");
    }
}


void Dialog::on_btnBoxUserInputValidateRegex_rejected(){
    reject();
}
