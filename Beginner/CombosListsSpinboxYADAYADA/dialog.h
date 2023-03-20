#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "ui_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    // Tab 1
    void on_comboBox_currentIndexChanged(int index);

    void on_btnCmbBasics_clicked();

private:
    Ui::Dialog *ui;
    // Tab 1
    void init();
    void load();
};
#endif // DIALOG_H
