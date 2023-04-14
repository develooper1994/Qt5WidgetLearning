#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    init();
    saveUserInput();
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::init(){
    //
    QPushButton* btnBack = new QPushButton("Back", this);
    connect(btnBack, &QPushButton::clicked, this, &FindDialog::goBack);
    ui->buttonBox->addButton(btnBack, QDialogButtonBox::ButtonRole::ActionRole);
}

void FindDialog::saveUserInput(){
    // take user inputs
    m_text = ui->lineEdit->text();
    m_caseSensitive = ui->chkCaseSensitive->isChecked();
    m_wholeWords = ui->chkMatchWholeWord->isChecked();
    m_backwards = false;
}

void FindDialog::on_buttonBox_accepted(){
    saveUserInput();
    accept();
}
void FindDialog::on_buttonBox_rejected(){
    reject();
}
void FindDialog::goBack(){
    saveUserInput();
    m_backwards=true;
    accept();
}



// getter-setter
QString FindDialog::text() const{
    return m_text;
}
bool FindDialog::caseSensitive() const{
    return m_caseSensitive;
}
bool FindDialog::wholeWords() const{
    return m_wholeWords;
}
bool FindDialog::backwards() const{
    return m_backwards;
}

