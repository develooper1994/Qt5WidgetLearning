# include "dialog.h"

void Dialog::init_TAB6(){

}

void Dialog::load_TAB6(){
    // no need to load it.
    ui->leSpingBoxName->setText("");
    ui->spinBoxAge->setValue(0);
    ui->doubleSpinBoxMoney->setValue(0);

    QFile file("QSpinBox.dat");
    if (!file.exists()) return;
    if (!file.open(QIODevice::OpenModeFlag::ReadOnly)) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QDataStream stream(&file);

    QString name;
    stream >> name;
    ui->leSpingBoxName->setText(name);

    int age;
    stream >> age;
    ui->spinBoxAge->setValue(age);

    double money;
    stream >> money;
    ui->doubleSpinBoxMoney->setValue(money);

    file.close();
}

void Dialog::save_TAB6(){
    QFile file("QSpinBox.dat");
    if (!file.open(QIODevice::OpenModeFlag::WriteOnly)) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }
    QDataStream stream(&file);
    stream << ui->leSpingBoxName->text();
    stream << ui->spinBoxAge->value();
    stream << ui->doubleSpinBoxMoney->value();

    file.close();
    QMessageBox::information(this, "Saved", "Information saved");
}


// slots
void Dialog::on_SpinBoxButtonBox_accepted(){
    save_TAB6();
    accept();
}


void Dialog::on_SpinBoxButtonBox_rejected(){
    reject();
}
