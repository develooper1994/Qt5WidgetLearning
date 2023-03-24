#include "dialog.h"

void Dialog::init_TAB3(){
    ui->fontComboBox->setCurrentFont(ui->lineEdit->font());
}

void Dialog::load_TAB3(){
    QSettings settings("CombosListsSpinboxYADAYADA", "Tab3");
    QString value= settings.value("font","").toString();
    QFont font;
    if (!value.isEmpty()) {
        // load font
        if(font.fromString(value)){
            // if font loaded, set it.
            ui->fontComboBox->setCurrentFont(font);
        }
    }
}

void Dialog::save_TAB3(){
    QSettings settings("CombosListsSpinboxYADAYADA", "Tab3");
    settings.setValue("font", ui->fontComboBox->currentFont());
}



void Dialog::on_fontComboBox_currentFontChanged(const QFont &f){
    if (ui->lineEdit->font().toString() != f.toString()) {
        ui->lineEdit->setFont(f);
    }
}

void Dialog::on_buttonBox_accepted(){
    accept();
    save_TAB3();
}


void Dialog::on_buttonBox_rejected(){
    reject();
}
