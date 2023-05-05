#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    foreach (QScreen* screen, QGuiApplication::screens()) {
        ui->cmbScreens->addItem(screen->name());
    }

    //ui->btnScreen->setText("");
    ui->btnSave->setVisible(false);
}

Dialog::~Dialog(){
    delete ui;
}


// slots
void Dialog::on_btnScreen_clicked(){
    QScreen* screen = QGuiApplication::screens().at(ui->cmbScreens->currentIndex());
    if (!screen) {
        QMessageBox::critical(this, "Error", "Couldn't get screen");
        return;
    }

    this->hide();
    QTimer::singleShot(500, this, &Dialog::shoot);
}


void Dialog::on_btnSave_clicked(){
    QString path = QFileDialog::getSaveFileName(this, "Save", QString(), "PNG Image(*.png)");
    if (path.isEmpty()) return;

    QFileInfo fi;
    if (fi.exists(path)) {
        QMessageBox::StandardButton btn = QMessageBox::question(this, "Exist. Override?", "File already exist would you want to override?");
        if (QMessageBox::StandardButton::Yes!=btn) return;
    }

    if (!m_image.save(path, "PNG")) {
        QMessageBox::critical(this, "Error", "Couldn't save the image");
        return;
    }
}

void Dialog::shoot(){
    QScreen* screen = QGuiApplication::screens().at(ui->cmbScreens->currentIndex());
    if (!screen) {
        QMessageBox::critical(this, "Error", "Couldn't get screen");
        return;
    }

    m_image = screen->grabWindow(0);
    auto&& m_scaled = m_image.scaled(ui->lblScreen->width(), ui->lblScreen->height(), Qt::AspectRatioMode::KeepAspectRatio);

    ui->lblScreen->setPixmap(m_scaled);
    ui->btnSave->setVisible(true);

    this->show();
}

