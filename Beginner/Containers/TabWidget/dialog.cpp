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
    QPushButton *btnBack = new QPushButton("Back", this);
    QPushButton *btnNext = new QPushButton("Next", this);
    connect(btnBack,&QPushButton::clicked,this,&Dialog::backClicked);
    connect(btnNext,&QPushButton::clicked,this,&Dialog::nextClicked);

    ui->buttonBox->addButton(btnBack,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext,QDialogButtonBox::ButtonRole::ActionRole);

    //Update the tabs
    ui->tabWidget->setTabText(0,"Profile");
    ui->tabWidget->setTabText(1,"Notes");

    //Add tab
    QWidget *widget = new QWidget(this);
    ui->tabWidget->addTab(widget,"Send");
    QPushButton *btnHr = new QPushButton("Send to Human Resources", this);
    QPushButton *btnLegal = new QPushButton("Send to Legal", this);
    connect(btnHr,&QPushButton::clicked,this,&Dialog::hrClicked);
    connect(btnLegal,&QPushButton::clicked,this,&Dialog::legalClicked);

    QVBoxLayout *layout = new QVBoxLayout(widget);

    layout->addWidget(btnHr);
    layout->addWidget(btnLegal);

    widget->setLayout(layout);
}

QString Dialog::collectInfo(){
    QStringView name = ui->txtName->text();
    QStringView title = ui->txtTitle->text();
    QList<QCheckBox*> cbList = ui->tabWidget->findChildren<QCheckBox*>(QString(), Qt::FindChildOption::FindChildrenRecursively);
    QString selections;
    foreach (QCheckBox* cb, cbList) {
        if(cb->isChecked()){
            selections += cb->text() + ", ";
        }
    }
    QStringView text = ui->plainTextEdit->toPlainText();

    QString result;
    if (!name.isEmpty()) {
        result.append("|name: ").append(name)+" ";
    }
    if (!title.isEmpty()) {
        result.append("|title: ").append(title)+" ";
    }
    if (!selections.isEmpty()) {
        result.append("|selections: ").append(selections)+" |";
    }
    if (!text.isEmpty()) {
        result.append("|text: ").append(text);
    }

    return result;
}

void Dialog::backClicked(){
    int min = 0;
    int idx = ui->tabWidget->currentIndex();
    --idx;
    if(idx < min) idx = min;
    ui->tabWidget->setCurrentIndex(idx);
}

void Dialog::nextClicked(){
    int max = ui->tabWidget->count() - 1;
    int idx = ui->tabWidget->currentIndex();
    ++idx;
    if(idx > max) idx = max;
    ui->tabWidget->setCurrentIndex(idx);
}

void Dialog::on_buttonBox_accepted(){
    QString result = collectInfo();
    if(!result.isEmpty()){
        QMessageBox::information(this, "Collected Information", result);
    }
    accept();
}

void Dialog::hrClicked(){
    QString result = collectInfo();
    if(!result.isEmpty()){
        QMessageBox::information(this, "HR(Human Resource)", "Info sent to HR\n"+result);
    }
}

void Dialog::legalClicked(){
    QString result = collectInfo();
    if(!result.isEmpty()){
        QMessageBox::information(this, "Legal", "Info sent to Legal\n"+result);
    }
}

