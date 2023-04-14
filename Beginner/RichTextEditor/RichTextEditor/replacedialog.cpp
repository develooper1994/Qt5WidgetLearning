#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    init();
    saveUserInput();
}

ReplaceDialog::~ReplaceDialog(){
    delete ui;
}

void ReplaceDialog::init(){
    QPushButton* btnReplace = new QPushButton("Replace", this);
    QPushButton* btnReplaceAll = new QPushButton("Replace All", this);

    connect(btnReplace, &QPushButton::clicked, this, &ReplaceDialog::replace);
    connect(btnReplaceAll, &QPushButton::clicked, this, &ReplaceDialog::replaceAll);

    ui->buttonBox->addButton(btnReplace, QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnReplaceAll, QDialogButtonBox::ButtonRole::ActionRole);

}

void ReplaceDialog::saveUserInput(){
    m_text=ui->txtFind->text();
    m_replaceText=ui->txtReplace->text();
    m_all=false;
}

// slots
void ReplaceDialog::on_buttonBox_rejected(){
    reject();  // don't care inputs.
}
void ReplaceDialog::replace(){
    saveUserInput();
    accept();
}
void ReplaceDialog::replaceAll(){
    saveUserInput();
    m_all=true;
    accept();
}



// getter-setter
QString ReplaceDialog::text() const{
    return m_text;
}
QString ReplaceDialog::replaceText() const{
    return m_replaceText;
}
bool ReplaceDialog::all() const{
    return m_all;
}
