#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include <QDebug>
#include <QMetaEnum>

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

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_cbLineEditEnabled_toggled(bool checked);

    void on_cbLineEditReadOnly_toggled(bool checked);

    void on_cbLineEditClearButton_toggled(bool checked);

    void on_cmbEchoLineEdit_currentIndexChanged(int index);

    void on_lineEditDefault_textChanged(const QString &arg1);

    void on_lineEditTest_textChanged(const QString &arg1);

    void on_btnLineEdit_accepted();

    void on_plainTextEdit_textChanged();

    void on_buttonBox_2_clicked(QAbstractButton *button);

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
    void init_TAB3();
    void load_TAB3();
    void save_TAB3();
    // Tab 4
    void init_TAB4();
    void load_TAB4();
    void save_TAB4();
    QMetaEnum echoModes;     // get all "QLineEdit::EchoMode" modes and add to combobox
    // Tab 5
    void init_TAB5();
    void load_TAB5();
    void save_TAB5();
    bool m_saved;
    // Tab 6
    // Tab 7
    // Tab 8

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // DIALOG_H
