#include "dialog.h"
#include "./ui_dialog.h"

# include <QVBoxLayout>
# include <QPushButton>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QVBoxLayout* layout = new QVBoxLayout();
    for (int idx = 0; idx < 50; ++idx) {
        QPushButton* button = new QPushButton("Button " + QString::number(idx));
        layout->addWidget(button);
    }
    ui->scrollAreaWidgetContents->setLayout(layout);
}

Dialog::~Dialog()
{
    delete ui;
}

