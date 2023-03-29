#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QIcon>

#include <QFile>
#include <QTextStream>

#include "./ui_dialog.h"


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

private:
    Ui::Dialog *ui;

    // Tab 1
    bool m_saved;
    void init();
    void load();
    void save();
    // Tab 2

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // DIALOG_H
