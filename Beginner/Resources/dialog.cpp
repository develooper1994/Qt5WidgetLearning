#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //Tab1
    init();
    load();
    //Tab2
    //Tab3
    load_tab3();
    //Tab4
    init_tab4();
}

Dialog::~Dialog()
{
    delete ui;
}
