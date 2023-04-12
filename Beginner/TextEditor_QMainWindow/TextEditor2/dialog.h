#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void setList(const QStringList &list);  // TODO: test the move!

    QString selected() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
    QString m_selected;
};

#endif // DIALOG_H
