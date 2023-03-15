#include "dialog.h"
#include "./ui_dialog.h"

# include <QGridLayout>
# include <QPushButton>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QGridLayout* layout = new QGridLayout();
    int row = 0, col = 0;
    for (int idx = 0; idx < 50; ++idx) {
        QPushButton* button = new QPushButton("Button " + QString::number(idx));
        int row = idx % 5;
        col += (idx/5);
        layout->addWidget(button, row, col, 1, 1);
    }
    ui->scrollAreaWidgetContents->setLayout(layout);
}

Dialog::~Dialog()
{
    delete ui;
}

