#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr);
    ~ReplaceDialog();

    QString text() const;
    QString replaceText() const;

    bool all() const;

private slots:
    void on_buttonBox_rejected();
    void replace();
    void replaceAll();


private:
    Ui::ReplaceDialog *ui;

    QString m_text;
    QString m_replaceText;
    bool m_all;

    void init();
    void saveUserInput();
};

#endif // REPLACEDIALOG_H
