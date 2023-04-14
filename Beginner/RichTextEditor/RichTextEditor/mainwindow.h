#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QLabel>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>

#include <QColorDialog>
#include <QFontDialog>
#include <QDesktopServices>

#include "finddialog.h"
#include "replacedialog.h"
#include "aboutdialog.h"

constexpr inline char dialogFilter[] = "Text Files(*.txt*);;All Files(*.*)";


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



    bool changed() const;
    void setChanged(bool newChanged);
    QString filename() const;
    void setFilename(const QString &newFilename);

private slots:
    //menu-action slots
        // menu-File
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionExit_triggered();
        // menu-Edit
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();
    void on_actionFind_triggered();
    void on_actionReplace_triggered();
    void on_actionSelect_All_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
        // menu-view
    void on_actionZoom_In_triggered();
    void on_actionZoom_Out_triggered();
        // menu-Text
    void on_actionBold_triggered();
    void on_actionItalic_triggered();
    void on_actionUnderline_triggered();
    void on_actionStrike_triggered();
    void on_actionColor_triggered();
    void on_actionFont_triggered();
        // menu-About
    void on_actionHelp_triggered();
    void on_actionAbout_triggered();
    //item slots
    void on_textEdit_textChanged();


    void on_actionCustom_triggered();

    void on_actionAnimals_triggered();

private:
    Ui::MainWindow *ui;

    bool m_changed;
    QString m_path;
    std::array<QLabel*, 3> lblVectorStatus; // lblIcon/lblStatus/lblFile

    void setup();
    void init();
    void load();

    void newFile();
    void openFile();
    void saveFile(QStringView path);
    void saveAsFile();
    void checkFileSaved();

    void setupStatusbar();
    void updateStatusbar(QStringView status);

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
