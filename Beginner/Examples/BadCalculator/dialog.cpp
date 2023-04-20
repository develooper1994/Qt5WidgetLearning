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
    qDeleteAll(m_list);
    delete ui;
}

void Dialog::init(){
    // build keypad
    //   0 1 2
    // 0 7 8 9 --row
    // 1 4 5 6 |
    // 2 1 2 3 col
    // 3 0
    int row = 0;
    int col = 2;
    for (int i = 9;i >= 0;i--){
        QPushButton *btn = new QPushButton(QString::number(i), this);
        btn->setShortcut(btn->text());
        connect(btn,&QPushButton::clicked,this,&Dialog::number);

        ui->gridLayout->addWidget(btn,row,col);
        col--;
        if(col < 0){
            row++;
            col = 2;
            if(row == 3) col = 0;
        }
    }

    QPushButton *btnAdd = new QPushButton("+", this);
    btnAdd->setShortcut(btnAdd->text());
    QPushButton *btnSubtract = new QPushButton("-", this);
    btnSubtract->setShortcut(btnSubtract->text());
    QPushButton *btnMultiply = new QPushButton("*", this);
    btnMultiply->setShortcut(btnMultiply->text());
    QPushButton *btnDivide = new QPushButton("/", this);
    btnDivide->setShortcut(btnDivide->text());
    QPushButton *btnClear = new QPushButton("Clear", this);
    btnClear->setShortcut(tr("c"));
    QPushButton *btnRow = new QPushButton("Add Equation", this);
    btnRow->setShortcut(tr("a"));

    connect(btnAdd,&QPushButton::clicked,this,&Dialog::add);
    connect(btnSubtract,&QPushButton::clicked,this,&Dialog::subtract);
    connect(btnMultiply,&QPushButton::clicked,this,&Dialog::multiply);
    connect(btnDivide,&QPushButton::clicked,this,&Dialog::divide);
    connect(btnClear,&QPushButton::clicked,this,&Dialog::clear);
    connect(btnRow,&QPushButton::clicked,this,&Dialog::addEquation);

    ui->gridLayout->addWidget(btnAdd,0,3);
    ui->gridLayout->addWidget(btnSubtract,1,3);
    ui->gridLayout->addWidget(btnMultiply,2,3);
    ui->gridLayout->addWidget(btnDivide,3,3);

    ui->buttonBox->addButton(btnClear,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnRow,QDialogButtonBox::ButtonRole::ActionRole);

}

void Dialog::on_buttonBox_accepted(){
    double total=0;
    foreach (Equation* e, m_list) {
        bool ok;
        double value = e->sum().toDouble(&ok);
        if(!ok) continue;
        total += value;
    }
    QMessageBox::information(this, "Total", "Total is: " + QString::number(total));
    //accept();
}

void Dialog::clear(){
    qDeleteAll(m_list);
    m_list.clear();
    update();
}

void Dialog::add(){
    updateAction(Equation::Action::ADD);
}

void Dialog::subtract(){
    updateAction(Equation::Action::SUBTRACT);
}

void Dialog::multiply(){
    updateAction(Equation::Action::MULTIPLY);
}

void Dialog::divide(){
    updateAction(Equation::Action::DIVIDE);
}

void Dialog::number(){
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    bool ok;
    double value = btn->text().toDouble(&ok);
    Q_UNUSED(value);
    if(!ok) {
        QMessageBox::critical(this, "Error!", "something really screwed up");
        return;
    }

    updateValue(btn->text());
}

void Dialog::update(){
    // sync the data with ui(listWidget and m_list)
    int lastItemIndex = ui->listWidget->count()-1;
    if (ui->listWidget->count() != m_list.count()) {
        // out of sync
        // 1. clear the list
        // 2. add list to listwidget
        // 3. set listwidget->CurrentRow to last index of list
        ui->listWidget->clear();
        foreach (Equation* e, m_list) {
            ui->listWidget->addItem(e->toString());
        }
        ui->listWidget->setCurrentRow(lastItemIndex);
    } else {
        // sync
        // update the last one
        // 1. set listwidget->CurrentRow to last index of list
        // 2. get the last item
        // 3. set text to last item of list
        ui->listWidget->setCurrentRow(lastItemIndex);
        ui->listWidget->item(lastItemIndex)->setText(m_list.last()->toString());
    }
}

void Dialog::addEquation(){
    m_list.append(new Equation(this));
    update();
}

Equation *Dialog::getLast(){
    if (m_list.isEmpty()) m_list.append(new Equation(this));
    return m_list.last();
}

void Dialog::updateValue(QString data){
    Equation* equation = getLast();
    if (!equation) return;

    QString value;
    if (equation->action() == Equation::Action::NONE) {
        qDebug() << "None";
        value = equation->value1();
        value.append(data);
        equation->setValue1(value);
    } else {
        qDebug() << "Not None";
        value = equation->value2();
        value.append(data);
        equation->setValue2(value);
    }

    equation->calculate();
    update();  // update the display
}

void Dialog::updateAction(Equation::Action value){
    Equation* equation = getLast();
    if (!equation) return;

    equation->setAction(value);
    equation->calculate();
    update();  // update the display
}

