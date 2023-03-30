#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QIcon>

#include <QFile>
#include <QFileInfoList>
#include <QTextStream>
#include <QDir>

#include "./ui_dialog.h"
#include "libraries/MyLib/mylib.h"


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
    void on_btnNew_clicked();
    void on_btnOpen_clicked();
    void on_btnSave_clicked();
    void on_pte_textChanged();
    void on_btnAccept();

    // Tab 2
    void on_btnLoad_clicked();
    void on_btnSave_2_clicked();

    // Tab 3
    void on_listWidget_itemSelectionChanged();
    void on_btnBoxOk_accepted();
    // Tab 4

    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;

    // Tab 1
    bool m_saved;
    void init();
    void load();
    void save();
    // Tab 2
    // Tab 3
    void load_tab3();
    void scan_tab3(QFileInfoList FIL);
    // Tab 4
    void init_tab4();

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // DIALOG_H
