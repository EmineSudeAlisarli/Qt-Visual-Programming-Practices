#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

#include <QApplication>
#include <QTextStream>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //File menüsü slotları
    void on_actionNew_2_triggered();
    void on_actionOpen_2_triggered();
    void on_actionSave_2_triggered();
    void on_actionExit_triggered();

    // Edit menüsü slotları
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPAste_triggered();
    void on_actionSelect_All_triggered();
    void on_actionSelect_None_triggered();

    //Forms menüsü slotları
    void on_actionOpen_Form_triggered();

    void on_actionToolbar_Top_triggered();

    void on_actionToolbar_Buttom_triggered();

    void on_actionToolbar_Right_2_triggered();

    void on_actionToolbar_Left_triggered();

    void on_actionToolbar_Floatable_triggered();

    void on_actionToolbar_Movable_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
