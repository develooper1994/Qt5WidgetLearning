#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include <QDebug>

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

    void on_btnListWidgetAdd_clicked();

    void on_btnBoxListWidget_clicked(QAbstractButton *button);

private:
    Ui::Dialog *ui;
    // Tab 1
    void init_TAB1();
    void load_TAB1();
    // Tab 2
    void init_TAB2();
    void load_TAB2();
    void save_TAB2();
    // Tab 3
    // Tab 4
    // Tab 5
};
#endif // DIALOG_H
