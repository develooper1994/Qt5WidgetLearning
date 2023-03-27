#include "dialog.h"


void Dialog::init_TAB4(){
    ui->cbLineEditEnabled->setChecked(ui->lineEditTest->isEnabled());
    ui->cbLineEditReadOnly->setChecked(ui->lineEditTest->isReadOnly());
    ui->cbLineEditClearButton->setChecked(ui->lineEditTest->isClearButtonEnabled());

    // get all "QLineEdit::EchoMode" modes and add to combobox
    echoModes = QMetaEnum::fromType<QLineEdit::EchoMode>();
    for (int idx = 0; idx < echoModes.keyCount(); ++idx) {
        // ui->cmbEchoLineEdit->addItem(echoModes.valueToKey(idx), echoModes.value(idx));
        ui->cmbEchoLineEdit->addItem(echoModes.valueToKey(idx));
    }
}

void Dialog::load_TAB4(){
    QSettings settings("CombosListsSpinboxYADAYADA", "Tab4");
}

void Dialog::save_TAB4(){
    QSettings settings("CombosListsSpinboxYADAYADA", "Tab4");
}


void Dialog::on_cmbEchoLineEdit_currentIndexChanged(int index){
    char* selectedItem = ui->cmbEchoLineEdit->currentText().toLocal8Bit().data();
    //
    int value = echoModes.keyToValue(selectedItem);
    QLineEdit::EchoMode mode = static_cast<QLineEdit::EchoMode>(value);
    ui->lineEditTest->setEchoMode(mode);
}


void Dialog::on_lineEditTest_textChanged(const QString &arg1){
    ui->lineEditDefault->setText(arg1);
}

void Dialog::on_btnLineEdit_accepted(){
    QMessageBox::information(this,"Entered:","You entered " + ui->lineEditTest->text());
    accept();
}


void Dialog::on_cbLineEditEnabled_toggled(bool checked){
    ui->lineEditTest->setEnabled(checked);
}

void Dialog::on_cbLineEditReadOnly_toggled(bool checked){
    ui->lineEditTest->setReadOnly(checked);
}

void Dialog::on_cbLineEditClearButton_toggled(bool checked){
    ui->lineEditTest->setClearButtonEnabled(checked);
}
