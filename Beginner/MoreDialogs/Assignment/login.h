#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    QString getName() const;
    QString getPassword() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Login *ui;
    QString name, password;

};

#endif // LOGIN_H
