#include "dialog.h"
#include "./ui_dialog.h"

#include <QMessageBox>
#include <QPushButton>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
    load();
}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::init(){
    QPushButton* btnEdit=new QPushButton("Edit", this);
    ui->buttonBox->addButton(btnEdit, QDialogButtonBox::ButtonRole::ActionRole);
    connect(btnEdit, &QPushButton::clicked, this, &Dialog::on_edit);

    m_music.setArtist("Tool");
    m_music.setAlbum("Fear");
    m_music.setRelease(QDate(2023,3,31));
    m_music.setNotes("FINALLY!!!");
}

void Dialog::load(){
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setReadOnly(true);

    QString data;
    data.append("Album: "   + m_music.album()  + "\r\n");
    data.append("Artist: "  + m_music.artist() + "\r\n");
    data.append("Notes: "   + m_music.notes()  + "\r\n");
    data.append("Release: " + m_music.release().toString(Qt::TextDate) + "\r\n");
    ui->plainTextEdit->setPlainText(data);
}


// slots
void Dialog::on_buttonBox_accepted(){
    QMessageBox::information(this, "Selection", ui->plainTextEdit->toPlainText());
    accept();
}


void Dialog::on_buttonBox_rejected(){
    reject();
}

void Dialog::on_edit(){
    Editor* editor = new Editor(this);
    editor->setMusic(m_music);
    editor->exec();  // focus on

    m_music = editor->getMusic();
    load();

    delete editor;
}



// getter-setter
