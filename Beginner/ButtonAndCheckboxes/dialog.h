#ifndef DIALOG_H
#define DIALOG_H

#include "./ui_dialog.h"
#include <QDialog>
#include <QCheckBox>
#include <QMessageBox>
#include <QCommandLinkButton>

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
    void on_btnCheckable_clicked();

    void on_btnAutoRepeat_clicked();

    void on_btnDefault_clicked();

    void on_btnIsChecked_clicked();

    void on_btnToggleAutoRepeat_clicked();

    void on_btnToggleDefault_clicked();

    void on_btnQuit_clicked();

    void on_pushButton_2_clicked();

    void on_btnPizzaCancel_clicked();

    void on_btnPizzaOk_clicked();

    void on_option1_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_buttonBox_helpRequested();

    void on_option2_clicked();

    void on_option3_clicked();

private:
    Ui::Dialog *ui;

    QString getPizzaOptions(QObject* obj);
    void selectPage4Option(QObject* sender);
};
#endif // DIALOG_H
