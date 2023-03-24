#include "dialog.h"

void Dialog::init_TAB2(){
    ui->cmbListWidget->setEnabled(true);
    ui->listWidget1->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
    ui->btnBoxListWidget->addButton("Clear", QDialogButtonBox::ButtonRole::ActionRole);
    ui->btnBoxListWidget->addButton("Remove", QDialogButtonBox::ButtonRole::ActionRole);
}

void Dialog::load_TAB2(){
    QSettings settings;
    settings.beginGroup("TAB2");
    // combobox-current
    ui->cmbListWidget->setCurrentText(settings.value("text", "").toString());
    // combobox-items
    int cmbSize = settings.beginReadArray("combo");
    for (int idx = 0; idx < cmbSize; ++idx) {
        settings.setArrayIndex(idx);
        ui->cmbListWidget->addItem(settings.value("item", "").toString());
    }
    settings.endArray();
    // listwidget-items
    int listSize = settings.beginReadArray("list");
    for (int idx = 0; idx < listSize; ++idx) {
        settings.setArrayIndex(idx);
        ui->listWidget1->addItem(settings.value("item", "").toString());
    }
    settings.endArray();

    settings.endGroup();
}

void Dialog::save_TAB2(){
    QSettings settings;
    settings.clear();  // clear ghost data
    settings.beginGroup("TAB2");
    // combobox-current
    settings.setValue("text", ui->cmbListWidget->currentText());
    // combobox-items
    settings.beginWriteArray("combo");
    for (int idx = 0; idx < ui->cmbListWidget->count(); ++idx) {
        settings.setArrayIndex(idx);
        settings.value("item", ui->cmbListWidget->itemText(idx));
    }
    settings.endArray();
    // listwidget-items
    settings.beginWriteArray("list");
    for (int idx = 0; idx < ui->listWidget1->count(); ++idx) {
        settings.setArrayIndex(idx);
        settings.value("item", ui->listWidget1->item(idx)->text());
    }
    settings.endArray();


    settings.endGroup();
}

void Dialog::on_btnListWidgetAdd_clicked(){
    // if typed text doesn't inside combobox then append it.
    // findText: search inside combobox
    // currentText: user typed in.
    if (ui->cmbListWidget->findText(ui->cmbListWidget->currentText())<0) {
        ui->cmbListWidget->addItem(ui->cmbListWidget->currentText());
    }
    ui->listWidget1->addItem(ui->cmbListWidget->currentText());
}


void Dialog::on_btnBoxListWidget_clicked(QAbstractButton *button){
    // detect which button clicked
    qDebug() << button->text();

    if (button->text().contains("Ok")) {
        save_TAB2();
        accept();
        return;
    }
    if (button->text().contains("Cancel")) {
        reject();
        return;
    }
    if (button->text().contains("Clear")) {
        ui->cmbListWidget->clear();
        ui->listWidget1->clear();
        return;
    }
    if (button->text().contains("Remove")) {
        QList<QListWidgetItem*> items = ui->listWidget1->selectedItems();
        foreach (QListWidgetItem* item, items) {
            ui->listWidget1->removeItemWidget(item);
            delete item;
        }
    }

}
