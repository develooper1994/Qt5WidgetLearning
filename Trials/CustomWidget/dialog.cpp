#include "dialog.h"
#include "./ui_dialog.h"

#include "cardwidget.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    cardWidget* w = new cardWidget(this);
    cardWidget* w2 = new cardWidget(this);
    cardWidget* w3 = new cardWidget(this);
    QGridLayout* lay = new QGridLayout(this);
    lay->addWidget(w, 0, 0, 1, 1);
    lay->addWidget(w2, 0, 1, 1, 1);
    lay->addWidget(w3, 1, 0, 1, 1);
    lay->addWidget(ui->frame, 1, 1, 1, 1);


    window()->setLayout(lay);
    //window()->adjustSize();
}

Dialog::~Dialog()
{
    delete ui;
}

