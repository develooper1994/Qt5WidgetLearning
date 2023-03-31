#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include "../music/header/music.h"

namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    ~Editor();

    Music getMusic() const;
    void setMusic(const Music &newMusic);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Editor *ui;
    Music m_music;
};

#endif // EDITOR_H
