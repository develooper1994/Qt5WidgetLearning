#include "cardwidget.h"
#include "ui_cardwidget.h"

cardWidget::cardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cardWidget)
{
    ui->setupUi(this);
}

cardWidget::~cardWidget()
{
    delete ui;
}
