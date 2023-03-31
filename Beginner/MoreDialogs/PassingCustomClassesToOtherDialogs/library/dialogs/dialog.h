#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "editor.h"
#include "../music/header/music.h"


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
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_edit();

private:
    Ui::Dialog *ui;
    Music m_music;

    void init();
    void load();
};

#endif // DIALOG_H
