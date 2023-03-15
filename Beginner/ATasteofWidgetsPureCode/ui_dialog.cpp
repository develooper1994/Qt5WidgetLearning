#include "ui_dialog.h"

Ui_Dialog::Ui_Dialog()
{

}

void Ui_Dialog::setupUi(QDialog *Dialog)
{
    // setup everthing
    if (Dialog->objectName().isEmpty()) {
        Dialog->setObjectName("MainDialog");
    }
    //main dialog settings
    Dialog->resize(300,170);
    Dialog->setMaximumSize(QSize(300,170));
    // elements - labels
    Type_label = new QLabel(Dialog);
    Type_label->setObjectName("Type_label");
    Value_label = new QLabel(Dialog);
    Value_label->setObjectName("Value_label");
    Multiplier_label = new QLabel(Dialog);
    Multiplier_label->setObjectName("Multiplier_label");
    Result_label = new QLabel(Dialog);
    Result_label->setObjectName("Result_label");
    // elements - combobox
    Type_comboBox = new QComboBox(Dialog);
    Type_comboBox->setObjectName("Type_comboBox");
    // elements - lineEdits
    Value_lineEdit = new QLineEdit(Dialog);
    Value_lineEdit->setObjectName("Value_lineEdit");
    Multiplier_lineEdit = new QLineEdit(Dialog);
    Value_lineEdit->setObjectName("Multiplier_lineEdit");
    Result_lineEdit = new QLineEdit(Dialog);
    Value_lineEdit->setObjectName("Result_lineEdit");
    // elements - spacer
    horizontalSpacer =new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    // elements - button
    Calculate_pushButton = new QPushButton(Dialog);
    Calculate_pushButton->setObjectName("Calculate_pushButton");
    // layouts
    verticalLayout = new QVBoxLayout(Dialog);
    verticalLayout->setObjectName("vertical layout");
    horizantalLayout = new QHBoxLayout(Dialog);
    horizantalLayout->setObjectName("horizantial layout");
    gridLayout = new QGridLayout(Dialog);
    gridLayout->setObjectName("grid layout");
    // place things inside layouts
    // note: spanning = yayılma. eleman kaç satır ve sütun kaplayacak?
        // grid
            // 0.satır
    gridLayout->addWidget(Type_label,         0,0,1,1);
    gridLayout->addWidget(Type_comboBox,      0,1,1,1);
            // 1.satır
    gridLayout->addWidget(Value_label,        1,0,1,1);
    gridLayout->addWidget(Value_lineEdit,     1,1,1,1);
            // 2.satır
    gridLayout->addWidget(Multiplier_label,    2,0,1,1);
    gridLayout->addWidget(Multiplier_lineEdit, 2,1,1,1);
            // 3.satır
    gridLayout->addWidget(Result_label,       3,0,1,1);
    gridLayout->addWidget(Result_lineEdit,    3,1,1,1);
        // horizontial
    horizantalLayout->addItem(horizontalSpacer);
    horizantalLayout->addWidget(Calculate_pushButton);
        // vertical
    verticalLayout->addItem(gridLayout);
    verticalLayout->addItem(horizantalLayout);





    retranslateUi(Dialog);
}

void Ui_Dialog::retranslateUi(QDialog *Dialog)
{
    // main dialog
    Dialog->setWindowTitle("Dialog");
    // elements
    Type_label->setText("Type");
    Value_label->setText("Value");
    Multiplier_label->setText("Multiplier");
    Result_label->setText("Result");
    Calculate_pushButton->setText("Calculate");
}
