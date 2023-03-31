#include "selections.h"
#include "ui_selections.h"

Selections::Selections(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selections)
{
    ui->setupUi(this);

    init();
}

Selections::~Selections(){
    delete ui;
}



void Selections::init(){
    QDir root(":/file/images");
    QFileInfoList list = root.entryInfoList();
    foreach (QFileInfo fi, list) {
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
        item->setText(fi.absoluteFilePath());
        item->setIcon(QIcon(fi.absoluteFilePath()));
        ui->listWidget->addItem(item);
    }
}



// slots
void Selections::on_buttonBox_accepted(){
    QListWidgetItem* currentItem = ui->listWidget->currentItem();
    if (currentItem) {
        m_selected = currentItem->text();
    }
    accept();
}

void Selections::on_buttonBox_rejected(){
    reject();
}



// Getter-Setter
QString Selections::selected() const{
    return m_selected;
}

void Selections::setSelected(const QString &newSelected){
    if (newSelected.isEmpty()) {
        return;
    }
    m_selected = "";
    for (int idx = 0; idx < ui->listWidget->count(); ++idx) {
        QListWidgetItem* item = ui->listWidget->item(idx);
        if (item->text() == newSelected) {
            item->setSelected(true);
            m_selected = newSelected;
            return;
        }
    }
}
