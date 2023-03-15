#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //signal-slot
    connect(ui->Type_comboBox, &QComboBox::currentIndexChanged,
            this, &Dialog::on_Type_comboBox_currentIndexChanged);
    connect(ui->Calculate_pushButton, &QPushButton::clicked,
            this, &Dialog::on_Calculate_pushButton_clicked);

    m_types.insert("Mustafa", 110);
    m_types.insert("Selçuk", 20);
    m_types.insert("Çağlar", 43);
    m_types.insert("C++", 14);

    ui->Type_comboBox->addItems(m_types.keys());
    ui->Type_comboBox->setCurrentIndex(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Type_comboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    int value = m_types.value(ui->Type_comboBox->currentText());
    ui->Multiplier_lineEdit->setText(QString::number(value));

}

void Dialog::on_Calculate_pushButton_clicked()
{
    bool ok = false;
    int value1 = ui->Value_lineEdit->text().toInt(&ok);
    if(!ok) ui->Value_lineEdit->setText("0");
    int value2 = ui->Multiplier_lineEdit->text().toInt(&ok);
    if(!ok) ui->Multiplier_lineEdit->setText("0");

    int result = value1 * value2;
    ui->Result_lineEdit->setText(QString::number(result));
}

