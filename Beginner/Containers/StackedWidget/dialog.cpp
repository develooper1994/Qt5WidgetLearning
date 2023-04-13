#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::init(){
    btnNext = new QPushButton("Next", this);
    btnBack = new QPushButton("Back", this);
    connect(btnNext, &QPushButton::clicked, this, &Dialog::next);
    connect(btnBack, &QPushButton::clicked, this, &Dialog::back);
    ui->buttonBox->addButton(btnNext, QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnBack, QDialogButtonBox::ButtonRole::ActionRole);

    // add another page
    QWidget* widget = new QWidget(this);
    QHBoxLayout* hlay = new QHBoxLayout(this);
    QLabel* lblNothing = new QLabel("Add your controls here: ", this);
    hlay->addWidget(lblNothing);
    widget->setLayout(hlay);
    ui->stackedWidget->addWidget(widget);

    hideOrShowButtons();
}

void Dialog::hideOrShowButtons(){
    int min = 0;
    int max = ui->stackedWidget->count()-1;
    int idx = ui->stackedWidget->currentIndex();
    // First
    if (idx<=min) {
        btnBack->setEnabled(false);
        btnNext->setEnabled(true);
    }
    // Last
    else if (idx>=max) {
        btnBack->setEnabled(true);
        btnNext->setEnabled(false);
    }
    else{
    // Others
        btnBack->setEnabled(true);
        btnNext->setEnabled(true);
    }
}

// slots
void Dialog::on_buttonBox_accepted(){
    QMessageBox::information(this, "Ah ha!", ui->leFirst->text());
    accept();
}

void Dialog::on_buttonBox_rejected(){
    reject();
}

void Dialog::next(){
    int max = ui->stackedWidget->count() - 1;
    int idx = ui->stackedWidget->currentIndex();
    ++idx;
    if (idx>max) idx = max;
    ui->stackedWidget->setCurrentIndex(idx);
    hideOrShowButtons();
}

void Dialog::back(){
    int min = 0;
    int idx = ui->stackedWidget->currentIndex();
    --idx;
    if (idx<min) idx = min;
    ui->stackedWidget->setCurrentIndex(idx);
    hideOrShowButtons();
}

