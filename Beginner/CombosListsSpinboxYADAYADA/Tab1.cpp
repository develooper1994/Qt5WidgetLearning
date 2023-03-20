#include "dialog.h"
#include <QSettings>

void Dialog::init()
{
    ui->comboBox->clear();

    for (int idx = 0; idx < 10; ++idx) {
        ui->comboBox->addItem("Item Number: "+QString::number(idx));
    }
}


void Dialog::load()
{
    QSettings settings("CombosListsSpinboxYADAYADA", "CombosListsSpinboxYADAYADATab1");
    QVariant value = settings.value("settings", 0);

    bool ok;
    int index = value.toInt(&ok);

    if (!ok) {
        QMessageBox::critical(this, "Loading Error!", "Loading Error! due to integer casting");
        return;
    }


    if (index < ui->comboBox->count()) {
        ui->comboBox->setCurrentIndex(index);
    }
    else {
        ui->comboBox->setCurrentIndex(0);
    }
}


void Dialog::on_comboBox_currentIndexChanged(int index){
    ui->lblCmbBasics2->setText(QString::number(index) + " " + ui->comboBox->currentText());
}


void Dialog::on_btnCmbBasics_clicked(){
    QSettings settings("CombosListsSpinboxYADAYADA", "CombosListsSpinboxYADAYADATab1");
    settings.setValue("settings", ui->comboBox->currentIndex());

    QMessageBox::information(this, "Saved", "Selection saved, now get back to work!");
}
