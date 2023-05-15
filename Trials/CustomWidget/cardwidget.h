#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>

namespace Ui {
class cardWidget;
}

class cardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit cardWidget(QWidget *parent = nullptr);
    ~cardWidget();

private:
    Ui::cardWidget *ui;
};

#endif // CARDWIDGET_H
