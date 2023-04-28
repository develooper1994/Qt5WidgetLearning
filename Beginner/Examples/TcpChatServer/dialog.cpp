
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

    ui->buttonBox->addButton(btnBack, QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext, QDialogButtonBox::ButtonRole::ActionRole);

    connect(btnBack, &QPushButton::clicked,this,&Dialog::back);
    connect(btnNext, &QPushButton::clicked,this,&Dialog::next);
    connect(&server, &Server::changed,this,&Dialog::changed);
    enableButtons();
}

void Dialog::enableButtons(){
    ui->btnStart->setEnabled(!server.isListening());
    ui->btnStop->setEnabled(server.isListening());

    //Only one page
    if(ui->stackedWidget->count() <= 1){
        btnBack->setEnabled(false);
        btnNext->setEnabled(false);
        return;
    }

    //First page
    if(ui->stackedWidget->currentIndex() == 0){
        btnBack->setEnabled(false);
        btnNext->setEnabled(true);
        return;
    }

    //Last page
    if(ui->stackedWidget->currentIndex() >= ui->stackedWidget->count() -1){
        btnBack->setEnabled(true);
        btnNext->setEnabled(false);
        return;
    }
}



void Dialog::on_btnStart_clicked(){
    qint16 port = static_cast<qint16>(ui->sbPort->value());

    server.setMessage(ui->txtMessage->text());
    if (!server.listen(QHostAddress::Any, port)) {
        QMessageBox::critical(this, "Error", server.errorString());
        return;
    }

    ui->lblStatus->setText("Listing...");
    enableButtons();
}

void Dialog::on_btnStop_clicked(){
    server.close();
    ui->lblStatus->setText("Closed");
    enableButtons();
}

void Dialog::next(){
    int max = ui->stackedWidget->count();
    int idx = ui->stackedWidget->currentIndex();
    ++idx;
    if (idx>=max)
        idx = max-1;
    ui->stackedWidget->setCurrentIndex(idx);
    enableButtons();
}

void Dialog::back(){
    int min = 0;
    int idx = ui->stackedWidget->currentIndex();
    --idx;
    if (idx<min)
        idx = min;
    ui->stackedWidget->setCurrentIndex(idx);
    enableButtons();
}

void Dialog::changed(){
    ui->lblStatus->setText(QString("There are %0 clients connected").arg(server.count()));
}



